#include "LightParticle.hpp"
#include <iostream>

LightParticle::LightParticle(float frequency, float speed, Vector3d p, Vector3d d, float energy)
: LightBase::LightBase(speed, frequency, p, d), energy(energy) {}

void LightParticle::scatter() {
    std::cout << "Light particle is scattering!" << std::endl;
}

void LightParticle::collide() {
    std::cout << "Light particle colliding";
}

void LightParticle::showProperties() const {
    std::cout << "---Particle Properties---\n";
    LightBase::showProperties();
    std::cout << "Energy: " << energy << " J\n";
}

LightBase* LightParticle:: clone() const {
    return new LightParticle(*this);
}
