#pragma once

#include "rigidBody.hpp"
#include <vector>

class PhysicsWorld {
private:
	double timeElapsed;
	std::vector<RigidBody*> bodies;

public:
	void addBody(RigidBody *body);
	void tick(double delta);
};
