#include "LightWave.hpp"
#include <iostream> 

LightWave::LightWave(double intensity, double frequency, double speed, double x, double y, double z, double phase)
    : properties(intensity, frequency, speed, x, y, z), phase(phase) {}

void LightWave::interfere() {
    std::cout << "Light wave interfering\n";
}

void LightWave::diffract() {
    std::cout << "Light waves diffracting\n";
}

void LightWave::showProperties() const {
    std::cout << "LightWave properties:\n";
    std::cout << "Intensity: " << properties.intensity << " W/m^2\n";
    std::cout << "Frequency: " << properties.frequency << " Hz\n";
    std::cout << "Wavelength: " << properties.getWavelength() << "nm\n";
    std::cout << "Phase: " << phase << "\n";
}
