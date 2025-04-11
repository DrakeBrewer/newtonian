#pragma once

#include "rigidBody.hpp"
#include <cstdint>
#include <vector>

class PhysicsWorld {
private:
	double timeElapsed;
	std::vector<RigidBody*> bodies;
	float gravity;

public:
	PhysicsWorld(float gravity);
	void addBody(RigidBody *body, uint8_t color[3]);
	void tick(double delta);
};
