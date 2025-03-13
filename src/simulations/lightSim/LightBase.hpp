#pragma once
#include "../collisionSim/rigidBody.hpp"
#include "MaterialVolume.hpp"
#include <iostream>

class LightBase {
public:
    float frequency;
    float speed;
    Vector3d position;
    Vector3d direction;
    Material travelingThrough = Material();

    LightBase(float f, float s, Vector3d p, Vector3d d)
        : frequency(f), speed(s), position(p), direction(d) {}

    virtual ~LightBase() {}

    virtual void update(float timeStep) = 0;
    virtual LightBase* clone() const = 0;
    virtual void showProperties() const {
        std::cout << "Frequency: " << frequency << "Hz\n";
        std::cout << "Speed: " << speed << "m/s\n";
        std::cout << "Wavelength: " << getWavelength() << "nm\n";
        std::cout << "Direction: " << "<" << direction.x << ", " << direction.y << ", " << direction.z << ">\n";
    }

    float getWavelength() const { return speed/frequency; }
};
