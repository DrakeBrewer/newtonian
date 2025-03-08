#include "rigidBody.hpp"
#include <cmath>
#include <cstdio>
#include <iostream>

Vector3d::Vector3d(float x, float y, float z): x(0), y(0), z(0) {
	this->x = x;
	this->y = y;
	this->z = z;
}

// internal X vec
Vector3d Vector3d::crossProduct(const Vector3d& vec) {
	float i = (this->y * vec.z) - (this->z * vec.y);
	float j = (this->x * vec.z) - (this->z * vec.x);
	float k = (this->x * vec.y) - (this->y * vec.x);

	return Vector3d(i, j, k);
}

float Vector3d::dotProduct(const Vector3d& vec) {
	 return (this->x * vec.x) + (this->y * vec.y) + (this->z * vec.z);
}

float Vector3d::magnitude() {
	float sum = std::pow(this->x, 2) + std::pow(this->y, 2) + std::pow(this->z, 2);
	return std::sqrt(sum);
}

RigidBody::RigidBody(Vector3d initPos, Vector3d initVel, Vector3d initAcc, float mass, bool isStatic) {
	this->position = initPos;
	this->velocity = initVel;
	this->acceleration = initAcc;
	this->mass = mass;
	this->isStatic = isStatic;
}

void RigidBody::update(double delta) {
	// If an object is static we don't want it to be affected by any other forces
	// unstoppable force meets immovable object
	if (!this->isStatic) {
		this->velocity.x += this->acceleration.x * delta;
		this->velocity.y += this->acceleration.y * delta;
		this->velocity.z += this->acceleration.z * delta;

		this->position.x += this->velocity.x * delta;
		this->position.y += this->velocity.y * delta;
		this->position.z += this->velocity.z * delta;
	}

	std::cout << "\r" << std::fflush(stdout) <<
		"x: " << this->position.x <<
		", y: " << this->position.y <<
		", z: " << this->position.z;
}


// TODO: use diff eq's for this later?
void RigidBody::applyForce(Vector3d force) {
	this->acceleration.x = force.x / this->mass;
	this->acceleration.y = force.y / this->mass;
	this->acceleration.z = force.z / this->mass;
}


Sphere::Sphere(float radius, Vector3d position, float mass)
	: RigidBody(position, Vector3d(), Vector3d(), mass, false) {
	this->radius = radius;
	this->position = position;
	this->mass = mass;
}

float Sphere::surfaceArea() {
	return 4.0f * PI * std::pow(this->radius, 2);
}

float Sphere::volume() {
	return (4.0f/3.0f) * PI * std::pow(this->radius, 3);
}

float Sphere::diameter() {
	return 2 * this->radius;
}

Cuboid::Cuboid(float length, float width, float height, Vector3d position, float mass)
	: RigidBody(position, Vector3d(), Vector3d(), mass, false) {
	this->length = length;
	this->width = width;
	this->height = height;

	float halfL = this->length / 2;
	float halfW = this->width / 2;
	float halfH = this->height / 2;

	this->vertices[0] = Vector3d(this->position.x + halfL, this->position.y + halfW, this->position.z + halfH);  // top-front-right
	this->vertices[1] = Vector3d(this->position.x - halfL, this->position.y + halfW, this->position.z + halfH);  // top-front-left
	this->vertices[2] = Vector3d(this->position.x + halfL, this->position.y - halfW, this->position.z + halfH);  // top-back-right
	this->vertices[3] = Vector3d(this->position.x - halfL, this->position.y - halfW, this->position.z + halfH);  // top-back-left
	this->vertices[4] = Vector3d(this->position.x + halfL, this->position.y + halfW, this->position.z - halfH);  // bottom-front-right
	this->vertices[5] = Vector3d(this->position.x - halfL, this->position.y + halfW, this->position.z - halfH);  // bottom-front-left
	this->vertices[6] = Vector3d(this->position.x + halfL, this->position.y - halfW, this->position.z - halfH);  // bottom-back-right
	this->vertices[7] = Vector3d(this->position.x - halfL, this->position.y - halfW, this->position.z - halfH);  // bottom-back-left
}

void Cuboid::update(double delta) {
	RigidBody::update(delta);
	this->updateVertices();
}

void Cuboid::updateVertices() {
	float halfL = this->length / 2;
	float halfW = this->width / 2;
	float halfH = this->height / 2;

	// NOTE: This code is disgusting
	// TODO: Find a not gross way to do it without remaking a bunch of vectors..?
	this->vertices[0].x = this->position.x + halfL;
	this->vertices[0].y = this->position.y + halfW;
	this->vertices[0].z = this->position.z + halfH;

	this->vertices[1].x = this->position.x - halfL;
	this->vertices[1].y = this->position.y + halfW;
	this->vertices[1].z = this->position.z + halfH;

	this->vertices[2].x = this->position.x + halfL;
	this->vertices[2].y = this->position.y - halfW;
	this->vertices[2].z = this->position.z + halfH;

	this->vertices[3].x = this->position.x - halfL;
	this->vertices[3].y = this->position.y - halfW;
	this->vertices[3].z = this->position.z + halfH;

	this->vertices[4].x = this->position.x + halfL;
	this->vertices[4].y = this->position.y + halfW;
	this->vertices[4].z = this->position.z - halfH;

	this->vertices[5].x = this->position.x - halfL;
	this->vertices[5].y = this->position.y + halfW;
	this->vertices[5].z = this->position.z - halfH;

	this->vertices[6].x = this->position.x + halfL;
	this->vertices[6].y = this->position.y - halfW;
	this->vertices[6].z = this->position.z - halfH;

	this->vertices[7].x = this->position.x - halfL;
	this->vertices[7].y = this->position.y - halfW;
	this->vertices[7].z = this->position.z - halfH;
}

float Cuboid::surfaceArea() {
	return 2 * (this->length * this->width +
		    this->height * this->width +
		    this->length * this->height);
}

float Cuboid::volume() {
	return this->length * this->width * this->height;
}
