#pragma once
#include "LightStruct.hpp"

class LightBase {
public:
    virtual ~LightBase() {}

    virtual void update(double timeStep) = 0;
    virtual void showProperties() const = 0;
    virtual LightBase* clone() const = 0;
};
