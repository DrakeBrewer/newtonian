#include "LightRay.hpp"
#include <iostream>
#include <cmath>

LightRay::LightRay(double intensity, double frequency, double speed, float x, float y, float z)
    : properties(intensity, frequency, speed, x, y, z) {}

void LightRay::refract(const Medium& medium){
    // TODO: figure out how i'm representing mediums. I think planes for now. 
}

void LightRay::reflect() {
    // TODO: Add mirror representation, I think planes also for now. 
}

void LightRay::showProperties() const {
    std::cout << "LightRay Properties:\n";
    properties.showProperties();
}
