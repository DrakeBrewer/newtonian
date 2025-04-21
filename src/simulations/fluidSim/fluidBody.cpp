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

	std::cout << "\r" << std::fflush(stdout) << "x: " << this->position.x
		<< ", y: " << this->position.y << ", z: " << this->position.z;
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



/*
int main(int argc, char **argv) {
    fluidRectangle *rect = new fluidRectangle(5000, 50, Vector3d(0, 0, 0), 100, true, 1000);
    fluidEllipse *ellipse = new fluidEllipse(20, Vector3d(0, 0, 250), 5, false,  1.05, 500);
    fluidPhysicsWorld *world = new fluidPhysicsWorld(9.81);
    std::cout << rect->density  <<  std::endl;
    std::cout << "mass:  "  << rect->mass << std::endl;

}
    */