#pragma once

#include <vector>

#include "rigidBody.hpp"

class World {
private:
	float deltaTime;
	float timeScale;
public:
	std::vector<RigidBody> objects;
	void tick();
	void updateTimeScale(float newScale);
};
