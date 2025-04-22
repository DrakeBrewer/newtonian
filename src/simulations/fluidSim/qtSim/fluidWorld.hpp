#pragma once

#include "rigidBody.hpp"
#include "fluidBody.hpp"

#include <cstdint>
#include <vector>

class fluidPhysicsWorld {
private:
	double timeElapsed;
	std::vector<fluidBody*> bodies;
	float gravity;

public:
    fluidPhysicsWorld(float gravity);
	void addBody(fluidBody *body, uint8_t color[3]);
	void tick(double delta);
};

Vector3d netForce(fluidBody *obj, fluidBody *liquid, float gravity);