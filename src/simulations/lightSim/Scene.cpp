#include "Scene.hpp"
#include <iostream>

Scene::Scene(double duration)
    : timeElapsed(0.0), maxTime(duration) {}

void Scene::addObject(std::unique_ptr<Medium> obj) {
    objects.push_back(std::move(obj));
}

void Scene::addLight(const LightBase& light) {
    lights.push_back(std::unique_ptr<LightBase>(light.clone()));
}

void Scene::simulate(double timeStep) {
    std::cout << "\nStarting simulation, duration: " << maxTime << " seconds\n";
    while (timeElapsed < maxTime) {
	std::cout << "Time: " << timeElapsed << "s\n";

	for(auto& light : lights) {
	    light->update(timeStep);
	}
	timeElapsed += timeStep;
    }
    std::cout << "Simulation Complete.\n\n";
}

const std::vector<std::unique_ptr<LightBase>>& Scene::getLights() const {
    return lights;
}
