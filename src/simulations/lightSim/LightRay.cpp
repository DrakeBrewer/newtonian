#include "LightRay.hpp"
#include <iostream>
#include <cmath>

LightRay::LightRay(double intensity, double frequency, double speed, double x, double y, double z)
    : properties(intensity, frequency, speed, x, y, z) {}

void LightRay::refract(const Medium& medium){
    double n2 = medium.getRefractiveIndex();
    // Angle change based on Snell's law to be implemented.
    // For now, speed simply changes based on new index.
    properties.speed /= n2;
    std::cout << "Refracted. New speed = " << properties.speed << " m/s\n";
}

void LightRay::reflect() {
    // TODO: Add mirror representation
    
    // Horizontal refelction off a straight vertical surface example:
    properties.direction[0] = -properties.direction[0];
    std::cout << "Reflected. New direction: ("
	<< properties.direction[0] << ", "
	<< properties.direction[1] << ", "
	<< properties.direction[2] << ")\n";
}

void LightRay::showProperties() const {
    std::cout << "LightRay Properties:\n";
    std::cout << "Intensity: " << properties.intensity << " W/m^2";
    std::cout << "Frequency: " << properties.frequency << " Hz\n";
    std::cout << "Wavelength: " << properties.getWavelength() << " nm\n";
    std::cout << "Speed: " << properties.speed << " m/s\n";
    std::cout << "Direction: (" << properties.direction[0] << ", "
	<< properties.direction[1] << ", "
	<< properties.direction[2] << ")\n";
}
