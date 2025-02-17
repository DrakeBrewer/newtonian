#pragma once

#include <math.h>

/*
  This struct stores shared properties between all other representations of light.
*/
struct LightStruct {
    double intensity;
    double frequency;
    double speed;
    double direction[3];

    LightStruct(double i, double f, double s, double x, double y, double z)
        : intensity(i), frequency(f), speed(s) {
        setDirection(x, y, z);
    }

    double getWavelength() const { return speed / frequency; }

    void setDirection(double x, double y, double z) {
        // Normalize direction vector so it is independent of speed
        double magnitude = std::sqrt((x * x)  + (y * y) + (z * z));
        if(magnitude > 0) {
            direction[0] = x/magnitude;
            direction[1] = y/magnitude;
            direction[2] = z/magnitude;
        } else {
            direction[0] = direction[1] = direction[2] = 0; // Stationary if invalid
        }
    }
};
