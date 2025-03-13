#include "LightScene.hpp"
#include "LightRay.hpp"
#include "LightWave.hpp"
#include "LightParticle.hpp"
#include "MaterialVolume.hpp"
#include <iostream>

int main() {

    // Useful Variables
    float vacuumSpeed = 2.9979245e8;
    Vector3d startPosition = Vector3d(0,0,0);

    // Materials
    Material mirror = Material("Mirror", 0.5, 1.0, 0.5, 0.95, Vector3d(0, 0, 40), 10.0, true, false);
    Material glass = Material("Glass", 0.8, 1.2, 1.5, 0.04, Vector3d(0, 0, 60), 100.0, false, true);
    Material absorber = Material("Surface", 1.0, 2.0, 100, 1.0, Vector3d(0, 0, 80), 100.0, false, false);

    // 1. Reflection Test
    std::cout << "\n\n ---Reflection test---\n";
    LightScene mirrorScene = LightScene();
    Vector3d startMirror = Vector3d(0,0,30);
    Vector3d upwardDirection = Vector3d(0,0,1);
    LightRay mirrorTest(600, vacuumSpeed, startMirror, upwardDirection);
    mirrorScene.addLight(mirrorTest);
    mirrorScene.addMaterial(mirror);
    std::cout << "Before:\n";
    for(const auto& light : mirrorScene.getLights()) {
	light->showProperties();
	std::cout << "-------------------------\n";
    }
    mirrorScene.simulate();
    std::cout << "After:\n";
    for(const auto& light : mirrorScene.getLights()) {
	light->showProperties();
	std::cout << "-------------------------\n";
    }

    // 2. Refraction Test
    std::cout << "\n\n ---Refraction test---\n";
    LightScene refractScene = LightScene();
    Vector3d insideGlass = Vector3d(0,0,61);
    Vector3d downward = Vector3d(0,0,-1);
    LightRay refractionTest(500, vacuumSpeed, insideGlass, downward);
    refractScene.addLight(refractionTest);
    refractScene.addMaterial(glass);
    for(const auto& light : refractScene.getLights()) {
	light->showProperties();
	std::cout << "-------------------------\n";
    }
    refractScene.simulate();
    std::cout << "After:\n";
    for(const auto& light : refractScene.getLights()) {
	light->showProperties();
	std::cout << "-------------------------\n";
    }

    return 0;
}
