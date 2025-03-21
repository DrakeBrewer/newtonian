#include "rigidBody.hpp"
#include "deltaTime.hpp"
#include "world.hpp"

int main(int argc, char **argv) {
	PhysicsWorld *world = new PhysicsWorld();

	RigidBody *obj = new RigidBody(
		Vector3d(0, 0, 100),
		Vector3d(10, -10, 20),
		Vector3d(),
		10,
		false
	);

	RigidBody *floor = new RigidBody(
		Vector3d(),
		Vector3d(),
		Vector3d(),
		1000,
		true
	);

	Sphere *sphere = new Sphere(
		3.0f,
		Vector3d(0, 0, 100),
		10
	);

	world->addBody(sphere);
	// world->addBody(obj);
	// world->addBody(floor);

	while (sphere->position.z > 0) {
		// TODO: Might want to change this to a float for perf reasons
		// Kind of min-maxxing at that point though.
		double dt = deltaTime();
		world->tick(dt);
	}

	return 0;
}
