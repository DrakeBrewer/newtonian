#include "LightParticle.hpp"
#include <iostream>

LightParticle::LightParticle(double intensity, double frequency, double speed, float x, float y, float z, double energy)
: properties(intensity, frequency, speed, x, y, z), energy(energy) {}

void LightParticle::scatter() {
    std::cout << "Light particle is scattering!" << std::endl;
}

void LightParticle::collide() {
    std::cout << "Light particle colliding";
}

void LightParticle::showProperties() const {
    std::cout << "---Particle Properties---\n";
    properties.showProperties();
    std::cout << "Energy: " << energy << " J\n";
}
