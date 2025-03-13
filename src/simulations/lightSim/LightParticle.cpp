#include "LightParticle.hpp"
#include <iostream>
 
LightParticle::LightParticle(float f, float s, Vector3d p, Vector3d d, float e)
    : LightBase::LightBase(f, s, p, d), energy(e) {}
 
void LightParticle::scatter() {
     std::cout << "Light particle is scattering!" << std::endl;
}
 
void LightParticle::collide() {
     std::cout << "Light particle colliding";
}
 
void LightParticle::showProperties() const {
    std::cout << "LightParticle Properties: \n";
    LightBase::showProperties();
    std::cout << "Energy: " << energy << " J\n";
}

LightBase* LightParticle::clone() const {
    return new LightParticle(*this);
}
