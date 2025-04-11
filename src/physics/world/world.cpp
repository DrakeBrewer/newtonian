#include "world.hpp"
#include "rigidBody.hpp"

PhysicsWorld::PhysicsWorld(float gravity) {
	this->gravity = gravity;
}

void PhysicsWorld::addBody(RigidBody *body) {
	this->bodies.push_back(body);
}

void PhysicsWorld::tick(double delta) {
	this->timeElapsed += delta;
	// std::cout << "\r" << std::fflush(stdout) << "Time: " << this->timeElapsed;

	for (auto& body : this->bodies) {
		// TODO: 
		// - [ ] apply forces (kinda implemented)
		// - [x] update body
		// - [ ] check collision (can of worms, notes contain details)
		// - [ ] resolve collisions

		const Vector3d gravity(0, 0, -this->gravity);
		Vector3d gForce(
			gravity.x * body->mass,
			gravity.y * body->mass,
			gravity.z * body->mass
		);

		body->applyForce(gForce);
		body->update(delta);
	}
}
