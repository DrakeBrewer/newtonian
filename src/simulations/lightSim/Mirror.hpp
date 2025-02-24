#pragma once
#include "Medium.hpp"
#include "LightBase.hpp"
#include <iostream>
#include <cmath>

class Mirror : public Medium {
private: 
    double reflectivity;

public:
    Mirror(double reflectivity = 1.0)
        : Medium(1.0), reflectivity(reflectivity) {}

    virtual void interact(class LightBase & light) const override;
};
