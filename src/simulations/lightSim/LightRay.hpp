#pragma once 
#include "LightStruct.hpp"
#include "Medium.hpp"

class LightRay {
private:
    LightStruct properties;

public:
    LightRay(double intensity, double frequency, double speed, double x, double y, double z);

    void refract(const Medium& medium);
    void reflect(); // TODO: Add parameter, struct mirror (medium subclass?), must contain position, size, and curvature at a minimum 
    void showProperties() const;
};
