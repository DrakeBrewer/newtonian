#include "LightWave.hpp"
#include <iostream> 

LightWave::LightWave(double intensity, double frequency, double speed, float x, float y, float z, float phase)
    : properties(intensity, frequency, speed, x, y, z), phase(phase) {}

void LightWave::interfere() {
    std::cout << "Light wave interfering\n";
}

void LightWave::diffract() {
    std::cout << "Light waves diffracting\n";
}

void LightWave::showProperties() const {
    std::cout << "LightWave properties:\n";
    properties.showProperties();
    std::cout << "Phase: " << phase << "\n";
}
