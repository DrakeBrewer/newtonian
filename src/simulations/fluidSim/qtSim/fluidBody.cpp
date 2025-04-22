#include "fluidBody.hpp"
#include "fluidWorld.hpp"
#include "vector3d.hpp"
#include <cmath>
#include <cstdio>
#include <iostream>





void fluidBody::update(double delta) {
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

	//std::cout << "\r" << std::fflush(stdout) << "x: " << this->position.x
	//	<< ", y: " << this->position.y << ", z: " << this->position.z;
}

void fluidBody::applyForce(Vector3d force) {
	this->acceleration.x = force.x / this->mass;
	this->acceleration.y = force.y / this->mass;
	this->acceleration.z = force.z / this->mass;
}

float fluidEllipse::diameter() {
	return 2 * this->radius;
}

void fluidEllipse::update(double delta) {
	fluidBody::update(delta);
}


void fluidRectangle::update(double delta) {
	fluidBody::update(delta);
}

void fluidTriangle::updateVertices() {
	float halfWidth = float(width) / 2;
	float halfHeight = float(height) / 2;

	this->vertices[0] = Vector3d(this->position.x - halfWidth, 0, this->position.z - halfHeight); // bottom Left
	this->vertices[1] = Vector3d(this->position.x + halfWidth, 0, this->position.z - halfHeight); // bottom Right
	this->vertices[2] = Vector3d(this->position.x, 0, this->position.z + halfHeight); // top
}

void fluidTriangle::update(double delta) {
	fluidBody::update(delta);
	// Can swich the dragCoe here with some if statements
	this->updateVertices();
}