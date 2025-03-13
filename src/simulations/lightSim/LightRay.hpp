#pragma once 
#include "LightBase.hpp"
#include <iostream>

class LightRay: public LightBase {
public:
    LightRay(float frequency, float speed, Vector3d p, Vector3d d);

    virtual void update(float timeStep) override {
        std::cout << "updating ray: " << timeStep << " seconds.\n";
    }

    virtual void showProperties() const override;
    virtual LightBase* clone() const override;
    void refract(float n2, const Vector3d& normal);
    void reflect(const Vector3d& normal);
    void absorb();
};
