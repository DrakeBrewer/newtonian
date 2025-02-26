#include "rigidBody.hpp"
#include "delta_time.hpp"
#include "world.hpp"

int main(int argc, char **argv) {
	PhysicsWorld *world = new PhysicsWorld();

	RigidBody *obj = new RigidBody(
		Vector3d(0, 0, 100),
		Vector3d(),
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

	world->addBody(obj);
	world->addBody(floor);

	while (true) {
		// TODO: Might want to change this to a float for perf reasons
		// Kind of min-maxxing at that point though.
		double dt = delta_time();
		world->tick(dt);
	}

	return 0;
}
