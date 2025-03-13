#include "LightScene.hpp"
#include "LightRay.hpp"
#include "LightWave.hpp"
#include "LightParticle.hpp"
#include "MaterialVolume.hpp"
#include <iostream>

LightScene::LightScene(double duration, Vector3d minBound = {0,0,0}, Vector3d maxBound = {100,100,100})
    :	timeElapsed(0.0),
	maxTime((duration < 5.0) ? 5.0 : duration), // 5 sec minimum
	bounds({minBound, maxBound}) {}

LightScene::LightScene()
    :	timeElapsed(0.0),
	maxTime(5.0),
	bounds({{0,0,0}, {100,100,100}}) {}

LightScene::~LightScene() {}

void LightScene::addLight(const LightBase& Light) {
    lights.push_back(std::unique_ptr<LightBase>(Light.clone()));
}

const Material* LightScene::findMaterialInteraction(Vector3d& position) const {
    for(const auto& material : materials) {
	if(material.contains(position)) {
	    return &material;
	}
    }
    return nullptr;
}

void LightScene::simulate() {
    std::cout << "\nStarting simulation, duration: " << maxTime << " seconds\n";

    double accumulatedTime = 0.0;

    while (timeElapsed < maxTime) {
	double deltaT = deltaTime();
	accumulatedTime += deltaT;
	timeElapsed += deltaT;

	std::cout << "Time: " << timeElapsed << "s\n";

	for(auto& light : lights) {
	    Vector3d position = light->position;
	    const Material* material = findMaterialInteraction(position); //-1 if no interaction

	    LightRay* ray = dynamic_cast<LightRay*>(light.get());
	    if(material && ray) {
		if(material->reflective) {
		    ray->reflect(material->unitNormal);
		} else if (material->transmissive) {
		    ray->refract(material->refractiveIndex, material->unitNormal);
		} else { 
		    ray->absorb();
		}
	    }

	    light->update(deltaT);
	}
    }

    std::cout << "Simulation Complete.\n\n";
}

const std::vector<std::unique_ptr<LightBase>>& LightScene::getLights() const {
    return lights;
}
