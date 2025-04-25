#pragma once

#include <iostream>
#include <cmath>
#include "rigidBody.hpp"

class LightBody : public RigidBody {
public:
    LightBody(Vector3d origin, Vector3d direction, float wavelength, float speed = 400.0f);
    ~LightBody() = default; 

    float wavelength;
    float speed;
    Vector3d direction;
    float lastDelta = 0;

    // Refractive index of medium currently in
    float refractiveIndex = 1.0f;

    void update(double delta) override;
    void reflect(const Vector3d& surfaceNormal);
    void refract(Vector3d& surfaceNormal, float newRefractiveIndex);
};

class LightRect : public LightBody {
public: 
    LightRect(int width, int height, Vector3d position, bool isStatic);
    ~LightRect() {};

    int width;
    int heigth;

    Vector3d vertices[4];

    void update(double delta);
    void updateVertices();
    float area();
};
