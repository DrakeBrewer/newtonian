#include "LightScene.hpp"
#include <iostream>

LightScene::LightScene(double duration, Vector3d minBound = {0,0,0}, Vector3d maxBound = {100,100,100})
    :	timeElapsed(0.0),
	maxTime((duration < 5.0) ? 5.0 : duration), // 5 sec minimum
	bounds({minBound, maxBound}),
	ground({0,1,0}, 0) {}

LightScene::LightScene()
    :	timeElapsed(0.0),
	maxTime(5.0),
	bounds({{0,0,0}, {100,100,100}}),
	ground({0,1,0}, 0) {}

LightScene::~LightScene() {}

void LightScene::addLight(const LightBase& Light) {
    lights.push_back(std::unique_ptr<LightBase>(Light.clone()));
}

void LightScene::simulate(double timeStep) {
    std::cout << "\nStarting simulation, duration: " << maxTime << " seconds\n";

    double accumulatedTime = 0.0;

    // TODO: Finish refactoring dimensional component in to simulation. Have the ground absorb some Light, update position of Light and objects, etc.
    
    // TODO: Consider wether to use deltaTime or fixed time step

    while (timeElapsed < maxTime) {
	std::cout << "Time: " << timeElapsed << "s\n";

	for(auto& light : lights) {
	    light->update(timeStep);
	}
	timeElapsed += timeStep;
    }
    std::cout << "Simulation Complete.\n\n";
}

const std::vector<std::unique_ptr<LightBase>>& LightScene::getLights() const {
    return lights;
}
