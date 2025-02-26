#include "rigidBody.hpp"
#include <cmath>
#include <iostream>

Vector3d::Vector3d(float x, float y, float z): x(0), y(0), z(0) {
	this->x = x;
	this->y = y;
	this->z = z;
}

// this X vec
// TODO: make vec a reference since we aren't modifying it
Vector3d Vector3d::crossProduct(Vector3d vec) {
	float i = (this->y * vec.z) - (this->z * vec.y);
	float j = (this->x * vec.z) - (this->z * vec.x);
	float k = (this->x * vec.y) - (this->y * vec.x);

	return Vector3d(i, j, k);
}

float Vector3d::dotProduct(Vector3d vec) {
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
	if (!this->isStatic) {
		this->velocity.x += this->acceleration.x * delta;
		this->velocity.y += this->acceleration.y * delta;
		this->velocity.z += this->acceleration.z * delta;

		this->position.x += this->velocity.x * delta;
		this->position.y += this->velocity.y * delta;
		this->position.z += this->velocity.z * delta;
	}

	// std::cout << "pos x: " << this->position.x << std::endl;
	// std::cout << "pos y: " << this->position.y << std::endl;
	std::cout << "pos z: " << this->position.z << std::endl;
}


// TODO: use diff eq's for this later
void RigidBody::applyForce(Vector3d force) {
	this->acceleration.x = force.x / this->mass;
	this->acceleration.y = force.y / this->mass;
	this->acceleration.z = force.z / this->mass;
}
