#include "rigidBody.hpp"
#include "vector3d.hpp"
#include <cmath>
#include <cstdio>
#include <iostream>

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

// Method to get map of attributes to be used by replayTable.
// Virtual, so can be overridden by dirived classes like Sphere.
// This code was written by Brendan

std::unordered_map<std::string, float> RigidBody::getAttributes() const {
        std::unordered_map<std::string, float> attributes;
	std::cout << "Getting values" << std::endl;
        attributes["position.x"] = position.x;
        attributes["position.y"] = position.y;
        attributes["position.z"] = position.z;
        attributes["velocity.x"] = velocity.x;
        attributes["velocity.y"] = velocity.y;
        attributes["velocity.z"] = velocity.z;
        attributes["acceleration.x"] = acceleration.x;
        attributes["acceleration.y"] = acceleration.y;
        attributes["acceleration.z"] = acceleration.z;
        attributes["mass"] = mass;
	std::cout << "position x, y, z is <" << position.x <<","<< position.y << "," << position.z <<">" << std::endl;
	std::cout << "velocity x, y, z is <" << velocity.x <<","<< velocity.y << "," << velocity.z <<">" << std::endl;

	std::cout << "acceleration x, y, z is <" << acceleration.x <<","<< acceleration.y << "," << acceleration.z <<">" << std::endl;

        return attributes;
}


// TODO: use diff eq's for this later?
void RigidBody::applyForce(Vector3d force) {
	this->acceleration.x += force.x / this->mass;
	this->acceleration.y += force.y / this->mass;
	this->acceleration.z += force.z / this->mass;
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

Ellipse::Ellipse(float radius, Vector3d position, float mass, bool isStatic) {
	this->radius = radius;
	this->position = position;
	this->mass = mass;
	this->isStatic = isStatic;
}

float Ellipse::area() {
	return 2 * PI * this->radius;
}

float Ellipse::diameter() {
	return 2 * this->radius;
}

void Ellipse::update(double delta) {
	RigidBody::update(delta);
}

Rectangle::Rectangle(int width, int height, Vector3d position, float mass, bool isStatic) {
	this->width = width;
	this->height = height;
	this->position = position;
	this->mass = mass;
	this->isStatic = isStatic;

	float halfWidth = float(width) / 2;
	float halfHeight = float(height) / 2;

	this->vertices[0] = Vector3d(this->position.x - halfWidth, this->position.y - halfHeight, 0); // bottom Left
	this->vertices[1] = Vector3d(this->position.x - halfWidth, this->position.y + halfHeight, 0); // bottom Right
	this->vertices[2] = Vector3d(this->position.x + halfWidth, this->position.y - halfHeight, 0); // top Left
	this->vertices[3] = Vector3d(this->position.x + halfWidth, this->position.y + halfHeight, 0); // top right
}

void Rectangle::update(double delta) {
	RigidBody::update(delta);
}

Triangle::Triangle(int width, int height, Vector3d position, float mass, bool isStatic) {
	this->width = width;
	this->height = height;
	this->position = position;
	this->mass = mass;
	this->isStatic = isStatic;

	float halfWidth = float(width) / 2;
	float halfHeight = float(height) / 2;

	this->vertices[0] = Vector3d(this->position.x - halfWidth, this->position.y - halfHeight, 0); // bottom Left
	this->vertices[1] = Vector3d(this->position.x, this->position.y + halfHeight, 0); // bottom Right
	this->vertices[2] = Vector3d(this->position.x + halfWidth, this->position.y - halfHeight, 0); // top Left
}

void Triangle::update(double delta) {
	RigidBody::update(delta);
}
