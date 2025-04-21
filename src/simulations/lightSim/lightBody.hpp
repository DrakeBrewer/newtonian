#pragma once

#include <iostream>
#include <cmath>
#include "rigidBody.hpp"

class LightBody : public RigidBody {
public:
    LightBody(Vector3d origin, Vector3d direction, float wavelength, float speed = 2.997925E8);
    ~LightBody() = default; 

    float wavelength;
    float speed;
    Vector3d direction;

    // Refractive index of medium currently in
    float refractiveIndex = 1.0f;

    void update(double delta) override;
    void reflect(Vector3d& surfaceNormal);
    void refract(Vector3d& surfaceNormal, float newRefractiveIndex);
};
