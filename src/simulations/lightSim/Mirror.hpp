#pragma once
#include "Medium.hpp"

class Mirror : public Medium {
private: 
    double reflectivity;

public:
    Mirror(double reflectivity = 1.0)
        : Medium(1.0), reflectivity(reflectivity) {}

    void interactWithRay(LightRay& ray) override;
};
