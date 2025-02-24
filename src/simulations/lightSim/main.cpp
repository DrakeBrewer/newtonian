#include "Scene.hpp"
#include "LightRay.hpp"
#include "LightWave.hpp"
#include "LightParticle.hpp"
#include "Mirror.hpp"
#include <iostream>

int main() {
    Scene scene(5.0);

    LightRay ray(1000, 600, 299792458, 1.0, 0.0, 0.0);
    scene.addLight(ray);

    LightWave wave(800, 500, 299792458, 0.0, 1.0, 0.0, 0.0);
    scene.addLight(wave);

    LightParticle particle(500, 400, 299792458, 0.0, 0.0, 1.0, 1.0e-19);
    scene.addLight(particle);

    for(const auto& light : scene.getLights()) {
	light->showProperties();
	std::cout << "-------------------------\n";
    }

    Mirror mirror;
    if(!scene.getLights().empty()) {
	mirror.interact(*scene.getLights()[0]);
    }

    scene.simulate(1.0);

    for(const auto& light : scene.getLights()) {
	light->showProperties();
	std::cout << "-------------------------\n";
    }

    return 0;
}
