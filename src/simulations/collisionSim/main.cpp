#include <iostream>
#include <ostream>

#include "main.hpp"
#include "rigidBody.hpp"
#include "delta_time.hpp"

int main(int argc, char **argv) {
	std::cout << "Hello World!" << std::endl;
	RigidBody *obj = new RigidBody(
		Position_t{0, 0, 10},
		Vector3d(),
		Vector3d(),
		10,
		false
	);

	RigidBody *floor = new RigidBody(
		Position_t{0, 0, 0},
		Vector3d(),
		Vector3d(),
		1000,
		true
	);

	while (true) {
		double dt = delta_time();
		tick(dt);

	}

	return 0;
}

void tick(double delta) {
		std::cout << "delta time: " << delta << std::endl;
}
