#include "LightParticle.hpp"
#include <iostream>

LightParticle::LightParticle(double intensity, double frequency, double speed, double x, double y, double z, double energy)
: properties(intensity, frequency, speed, x, y, z), energy(energy) {}

void LightParticle::scatter() {
    std::cout << "Light particle is scattering!" << std::endl;
}

void LightParticle::collide() {
    std::cout << "Light particle colliding";
}

void LightParticle::showProperties() const {
    std::cout << "Intensity: " << properties.intensity << " W/m^2\n";
    std::cout << "Wavelength: " << properties.getWavelength() << " nm\n";
    std::cout << "Energy: " << energy << " J\n";
}
