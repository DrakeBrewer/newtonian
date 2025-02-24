#pragma once 
#include "LightStruct.hpp"
#include "Medium.hpp"
#include "LightBase.hpp"
#include <iostream>

class LightRay: public LightBase {
private:
    LightStruct properties;

public:
    LightRay(double intensity, double frequency, double speed, double x, double y, double z);

    virtual void update(double timeStep) override {
        std::cout << "updating ray: " << timeStep << " seconds.\n";
    }

    void refract(const Medium& medium);
    void reflect(); // TODO: Add parameter, struct mirror (medium subclass?), must contain position, size, and curvature at a minimum 

    virtual void showProperties() const override;

    virtual LightBase* clone() const override {
        return new LightRay(*this);
    }
};
