#include "Scene.hpp"
#include <iostream>

void Scene::simulate(double timeStep) {
    std::cout << "Duration: " << maxTime << " seconds...\n";

    while (timeElapsed < maxTime) {
	std::cout << "Time: " << timeElapsed << "s\n";
	timeElapsed += timeStep;
    }


    std::cout << "Simulation Complete.\n";
}


