#pragma once
#include "../collisionSim/rigidBody.hpp"
#include <cmath>

#define BOUNDS 100-(-100) // Bounds of Scene on Z axis: maxZ-minZ

class Material {
public:
    float mass;
    float volume;
    float density;
    float refractiveIndex;
    float absorptionCoeff;
    Vector3d unitNormal = Vector3d(0,0,1); //Parallel materials for now
    float thickness;
    bool reflective;
    bool transmissive;

    Material(float m, float v, float n, float absCoeff, float thick, bool refl, bool trans)
	: mass(m), volume(v), density(m/v), refractiveIndex(n), absorptionCoeff(absCoeff), thickness(thick), reflective(refl), transmissive(trans) {}

    Material() : mass(0.0), volume(0.0), density(0.0), refractiveIndex(1), absorptionCoeff(0.0), thickness(BOUNDS), reflective(false), transmissive(false) {}

    bool contains(Vector3d& point) const {
	float dotResult = point.dotProduct(unitNormal);
	float distance = std::abs(dotResult);

	return (distance <= thickness / 2.0);
    }
};
