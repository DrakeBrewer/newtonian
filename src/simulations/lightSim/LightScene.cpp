#include "LightScene.hpp"
#include "LightRay.hpp"
#include "MaterialVolume.hpp"
#include <iostream>

#define DEBUG 0

LightScene::LightScene(float duration, Vector3d minBound = {0,0,0}, Vector3d maxBound = {100,100,100})
    :	timeElapsed(0.0),
	maxTime(duration),
	bounds({minBound, maxBound}) {}

LightScene::LightScene()
    :	timeElapsed(0.0),
	maxTime(0.001), // thousandth f a second by default
	bounds({{0,0,0}, {9999999, 9999999, 9999999}}) {}

LightScene::~LightScene() {}

void LightScene::addLight(LightBase& light) {
    lights.push_back(std::unique_ptr<LightBase>(light.clone()));
}

void LightScene::addMaterial(Material& mat) {
    materials.push_back(mat);
}

Material* LightScene::findMaterialInteraction(Vector3d& position) {
    for(auto& material : materials) {
	if(material.contains(position)) {
	    return &material;
	}
    }
    return nullptr;
}

void LightScene::simulate() {
    if(DEBUG) std::cout << "\nStarting simulation, duration: " << maxTime << " seconds\n";

    double accumulatedTime = 0.0;

    while (timeElapsed < maxTime) {
	double deltaT = deltaTime();
	accumulatedTime += deltaT;
	timeElapsed += deltaT;

	if(DEBUG) std::cout << "Time: " << timeElapsed << "s\n";

	for(auto& light : lights) {
	    Vector3d position = light->position;
	    Material* material = findMaterialInteraction(position); //-1 if no interaction

	    LightRay* ray = dynamic_cast<LightRay*>(light.get());
	    if(material && ray) {
		if(material->reflective) {
		    if(DEBUG) std::cout << "Reflection occurs.\n";
		    ray->reflect(material->unitNormal);
		} else if (material->transmissive) {
		    if(DEBUG) std::cout << "Refraction occurs.\n";
		    ray->refract(material->refractiveIndex, material->unitNormal);
		} else { 
		    if(DEBUG) std::cout << "Absorption occurs.\n";
		    ray->absorb();
		}
	    }

	    light->update(deltaT);
	}
    }

    if(DEBUG) std::cout << "Simulation Complete.\n\n";
}

const std::vector<std::unique_ptr<LightBase>>& LightScene::getLights() const {
    return lights;
}
