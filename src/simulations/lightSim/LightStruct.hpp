#pragma once

#include <math.h>
#include "../collisionSim/rigidBody.hpp"
#include <iostream>

/*
  This struct stores shared properties between all other representations of light.
*/
struct LightStruct {
    double intensity;
    double frequency;
    double speed;
    Vector3d direction;

    LightStruct(double i, double f, double s, float x, float y, float z)
        : intensity(i), frequency(f), speed(s), direction(x,y,z) {}

    double getWavelength() const {
        return speed / frequency;
    }

    void showProperties() const {
        std::cout << "Intensity: " << intensity << "cd\n";
        std::cout << "Frequency: " << frequency << "Hz\n";
        std::cout << "Speed: " << speed << "m/s\n";
        std::cout << "Wavelength: " << getWavelength() << "nm\n";
        std::cout << "Direction: " << "<" << direction.x << ", " << direction.y << ", " << direction.z << ">\n";
    }

    };
