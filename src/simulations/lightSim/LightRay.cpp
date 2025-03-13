#include <exception>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include "LightRay.hpp"

#define DEBUG 0

LightRay::LightRay(float f, float s, Vector3d p, Vector3d d)
    : LightBase::LightBase(f,s,p,d) {}

void LightRay::refract(float n2, Vector3d& normal) {

    if(n2 < 1) throw std::invalid_argument("Invalid index: n2 must be >= 1");

    // n = c/v
    float n1 = vacuumSpeed / this->speed;

    float ratio = n1/n2;

    // angle between incoming light and surface normal
    float cosTheta1 = normal.dotProduct(direction);

    // sin^2(theta) = (ratio)^2 * (1 - cos^2(theta))
    float sinTheta2 = ratio * ratio * (1 - cosTheta1 * cosTheta1);

    // Check for total internal reflection
    if(sinTheta2 > 1.0) {
	reflect(normal);
	return;
    }

    // if none, compute speed in new medium
    this->speed = vacuumSpeed / n2;


    float cosTheta2 = std::sqrt(1 - sinTheta2);

    direction.x = (ratio * direction.x) + (ratio * cosTheta1 - cosTheta2) * normal.x;
    direction.y = (ratio * direction.y) + (ratio * cosTheta1 - cosTheta2) * normal.y;
    direction.z = (ratio * direction.z) + (ratio * cosTheta1 - cosTheta2) * normal.z;


    if(DEBUG) std::cout << "New direction: <" << this->direction.x << ", " << this->direction.y << ", " << this->direction.z << ">\n";
}

void LightRay::reflect(Vector3d& normal) {
    float dot = direction.dotProduct(normal);
    direction.x = direction.x - 2 * dot * normal.x;
    direction.y = direction.y - 2 * dot * normal.y;
    direction.z = direction.z - 2 * dot * normal.z;

    if(DEBUG) std::cout << "New direction: <" << this->direction.x << ", " << this->direction.y << ", " << this->direction.z << ">\n";
}

void LightRay::showProperties() const {
    std::cout << "LightRay Properties:\n";
    LightBase::showProperties();
}

LightBase* LightRay::clone() const {
    return new LightRay(*this);
}

void LightRay::absorb() {
}
