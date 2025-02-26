#include "world.hpp"
#include "rigidBody.hpp"

void PhysicsWorld::addBody(RigidBody *body) {
	this->bodies.push_back(body);
}

void PhysicsWorld::tick(double delta) {
	this->timeElapsed += delta;

	for (auto& body : this->bodies) {
		// TODO: 
		// - [ ] apply forces
		// - [x] update body
		// - [ ] check collision (can of worms, notes contain details)
		// - [ ] resolve collisions

		const Vector3d gravity(0, 0, -9.81);
		Vector3d gForce(
			gravity.x * body->mass,
			gravity.y * body->mass,
			gravity.z * body->mass
		);

		body->applyForce(gForce);
		body->update(delta);
	}
}
