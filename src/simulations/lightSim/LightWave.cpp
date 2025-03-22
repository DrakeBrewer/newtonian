#include "LightWave.hpp"
#include <iostream> 

LightWave::LightWave(float f, float s, Vector3d p, Vector3d d, float phase)
    : LightBase::LightBase(f,s,p,d), phase(phase) {}

void LightWave::interfere() {
    std::cout << "Light wave interfering\n";
}

void LightWave::diffract() {
    std::cout << "Light waves diffracting\n";
}

void LightWave::showProperties() const {
    std::cout << "LightWave properties:\n";
    LightBase::showProperties();
    std::cout << "Phase: " << phase << "\n";
}

LightBase* LightWave::clone() const {
    return new LightWave(*this);
}
