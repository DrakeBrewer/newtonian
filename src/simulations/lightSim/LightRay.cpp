#include <iostream>
#include <cmath>
#include "LightRay.hpp"

LightRay::LightRay(float f, float s, Vector3d p, Vector3d d)
    : LightBase::LightBase(f,s,p,d) {}

void LightRay::refract(float n2, Vector3d& normal, LightScene& scene) {

    Material* currentMaterial = scene.findMaterialInteraction(position);

    float n1 = (currentMaterial) ? currentMaterial->refractiveIndex : 1.0;

    float ratio = (n1 < n2) ? (n1/n2) : (n2/n1);
    float cosThetaI = normal.dotProduct(direction);

    // clamp to prevent floating point errors
    cosThetaI = std::max(-1.0f, std::min(1.0f, cosThetaI));

    if(cosThetaI < 0) {
	normal.x *= -1;
	normal.y *= -1;
	normal.z *= -1;
	cosThetaI = -cosThetaI;
    }

    float sinThetaT2 = ratio * ratio * (1 - cosThetaI * cosThetaI);

    if(sinThetaT2 > 1.0) {
	reflect(normal);
	return;
    }

    this->speed = vacuumSpeed / n2;

    float cosThetaT = std::sqrt(1 - sinThetaT2);

    direction.x = (ratio * direction.x) + (ratio * cosThetaI - cosThetaT) * normal.x;
    direction.y = (ratio * direction.y) + (ratio * cosThetaI - cosThetaT) * normal.y;
    direction.z = (ratio * direction.z) + (ratio * cosThetaI - cosThetaT) * normal.z;


    std::cout << "New direction: <" << this->direction.x << ", " << this->direction.y << ", " << this->direction.z << ">\n";
}

void LightRay::reflect(Vector3d& normal) {
    float dot = direction.dotProduct(normal);
    direction.x = direction.x - 2 * dot * normal.x;
    direction.y = direction.y - 2 * dot * normal.y;
    direction.z = direction.z - 2 * dot * normal.z;

    std::cout << "New direction: <" << this->direction.x << ", " << this->direction.y << ", " << this->direction.z << ">\n";
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
