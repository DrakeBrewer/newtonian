#include "lightScene.hpp"
#include <iostream>

lightScene::lightScene(double duration, Vector3d minBound = {0,0,0}, Vector3d maxBound = {100,100,100})
    :	timeElapsed(0.0),
	maxTime(duration),
	bounds({minBound, maxBound}),
	ground({0,1,0}, 0) {}

void lightScene::addMedium(std::unique_ptr<Medium> newMedium) {
    mediums.push_back(std::move(newMedium));
}

void lightScene::addLight(const LightBase& light) {
    lights.push_back(std::unique_ptr<LightBase>(light.clone()));
}

void lightScene::simulate(double timeStep) {
    std::cout << "\nStarting simulation, duration: " << maxTime << " seconds\n";

    double accumulatedTime = 0.0;

    // TODO: Finish refactoring dimensional component in to simulation. Have the ground absorb some light, update position of light and objects, etc.
    
    // TODO: Consider wether to use deltaTime or fixed time step, find out what interloping means.

    while (timeElapsed < maxTime) {
	std::cout << "Time: " << timeElapsed << "s\n";

	for(auto& light : lights) {
	    light->update(timeStep);
	}
	timeElapsed += timeStep;
    }
    std::cout << "Simulation Complete.\n\n";
}

const std::vector<std::unique_ptr<LightBase>>& lightScene::getLights() const {
    return lights;
}
