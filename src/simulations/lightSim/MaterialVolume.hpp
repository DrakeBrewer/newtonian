#pragma once
#include "../../../lib/vector3d/vector3d.hpp"
#include <cmath>
#include <string>

#define BOUNDS 100-(-100) // Bounds of Scene on Z axis: maxZ-minZ

class Material {
public:
    std::string name;
    float mass;
    float volume;
    float density;
    float refractiveIndex;
    float absorptionCoeff;
    Vector3d unitNormal = Vector3d(0,0,1); //Parallel materials for now
    Vector3d center;
    float thickness;
    bool reflective;
    bool transmissive;

    Material(std::string matname, float m, float v, float n, float absCoeff, Vector3d c, float thick, bool refl, bool trans)
	: name(matname), mass(m), volume(v), density(m/v), refractiveIndex(n), absorptionCoeff(absCoeff), center(c), thickness(thick), reflective(refl), transmissive(trans) {}

    Material() : mass(0.0), volume(0.0), density(0.0), refractiveIndex(1), absorptionCoeff(0.0), thickness(BOUNDS), reflective(false), transmissive(false) {}

    bool contains(Vector3d& point) const {
	float dx = point.x - center.x;
	float dy = point.y - center.y;
	float dz = point.z - center.z;

	float dotResult = (dx * unitNormal.x) + (dy * unitNormal.y) + (dz * unitNormal.z);
	float distance = std::abs(dotResult);

	return (distance <= thickness / 2.0);
    }
};
