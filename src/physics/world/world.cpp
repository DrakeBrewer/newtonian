#include "world.hpp"
#include "rigidBody.hpp"
#include "collision.hpp"
#include <cstdint>

PhysicsWorld::PhysicsWorld(float gravity) {
	this->gravity = gravity;
	this->collisionSystem = new SATCollisionSystem();
}

void PhysicsWorld::addBody(RigidBody *body, uint8_t color[3]) {
	this->bodies.push_back(body);
}

void PhysicsWorld::tick(double delta) {
	this->timeElapsed += delta;

	for (auto& body : this->bodies) {
		const Vector3d gravity(0, 0, -this->gravity);
		Vector3d gForce(
			gravity.x * body->mass,
			gravity.y * body->mass,
			gravity.z * body->mass
		);

		body->applyForce(gForce);
		body->update(delta);
	}

	for (int i = 0; i < bodies.size(); i++) {
		for (int j = i+1; j < bodies.size(); j++) {
			if (bodies[i]->isStatic && bodies[j]->isStatic) {
				continue;
			}

			if (this->collisionSystem->checkCollision(bodies[i], bodies[j])) {
				this->collisionSystem->resolveCollision(bodies[i], bodies[j]);
			}
		}
	}
}
