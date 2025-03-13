#include "LightScene.hpp"
#include "LightRay.hpp"
#include "LightWave.hpp"
#include "LightParticle.hpp"
#include <iostream>

int main() {
    LightScene scene = LightScene();
    float vacuumSpeed = 2.9979245e8;

    LightRay ray(600, vacuumSpeed, 1.0, 0.0, 0.0);
    scene.addLight(ray);

    LightWave wave(500, vacuumSpeed, 0.0, 1.0, 0.0, 0.0);
    scene.addLight(wave);

    LightParticle particle(400, vacuumSpeed, 0.0, 0.0, 1.0, 1.0e-19);
    scene.addLight(particle);

    std::cout << "Before:\n";
    for(const auto& light : scene.getLights()) {
	light->showProperties();
	std::cout << "-------------------------\n";
    }

    scene.simulate(1.0);

    std::cout << "After:\n";
    for(const auto& light : scene.getLights()) {
	light->showProperties();
	std::cout << "-------------------------\n";
    }

    return 0;
}
