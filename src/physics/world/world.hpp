#pragma once

#include "rigidBody.hpp"
#include <vector>

class PhysicsWorld {
private:
	double timeElapsed;
	std::vector<RigidBody*> bodies;
	float gravity;

public:
	PhysicsWorld(float gravity);
	void addBody(RigidBody *body);
	void tick(double delta);
};
