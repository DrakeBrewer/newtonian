#pragma once
#include <math.h>
#include <iostream>

class Medium {
public:
    float refractiveIndex;
    std::string mediumName;

    Medium(float refractionIndex, std::string name)
        : refractiveIndex(refractionIndex), mediumName(std::move(name)) {}

    float refractionAngle(float incidentAngle) const {
        return asin(sin(incidentAngle) / refractiveIndex);
    }
};
