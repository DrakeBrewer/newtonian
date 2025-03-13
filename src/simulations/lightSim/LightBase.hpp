#pragma once
#include "../collisionSim/rigidBody.hpp"
#include "MaterialVolume.hpp"
#include <iostream>

class LightBase {
public:
    const float vacuumSpeed  = 2.9979245e8;
    float frequency;
    float speed;
    Vector3d position;
    Vector3d direction;
    // Implement field: Material travellingThrough?

    LightBase(float f, float s, Vector3d p, Vector3d d)
        : frequency(f), speed(s), position(p), direction(d) {}

    virtual ~LightBase() {}

    virtual void update(double timeStep){
        double displacementx = direction.x * speed * timeStep;
        double displacementy = direction.y * speed * timeStep;
        double displacementz = direction.z * speed * timeStep;

        position.x += displacementx;
        position.y += displacementy;
        position.z += displacementz;
    }
    virtual LightBase* clone() const = 0;
    virtual void showProperties() const {
        std::cout << "Frequency: " << frequency << "Hz\n";
        std::cout << "Speed: " << speed << "m/s\n";
        std::cout << "Wavelength: " << getWavelength() << "nm\n";
        std::cout << "Direction: " << "<" << direction.x << ", " << direction.y << ", " << direction.z << ">\n";
        std::cout << "Position: " << "<" << position.x << ", " << position.y << ", " << position.z << ">\n";
    }

    float getWavelength() const { return speed/frequency; }
};
