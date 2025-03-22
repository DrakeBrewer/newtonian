#pragma once 
#include "LightBase.hpp"
#include "LightScene.hpp"
#include <iostream>

class LightRay: public LightBase {
public:
    LightRay(float frequency, float speed, Vector3d p, Vector3d d);

    virtual void showProperties() const override;
    virtual LightBase* clone() const override;
    void refract(float n2, Vector3d& normal);
    void reflect(Vector3d& normal);
    void absorb();
};
