#include <iostream>
#include <cmath>
#include "LightRay.hpp"

LightRay::LightRay(float f, float s, Vector3d p, Vector3d d)
    : LightBase::LightBase(f,s,p,d) {}

void LightRay::refract(float n2,const Vector3d& normal) {
    float n1 = travelingThrough.refractiveIndex;
    float ratio = n1/n2;
    float cosThetaI = normal.dotProduct(direction);
    float sinThetaT2 = ratio * ratio * (1 - cosThetaI * cosThetaI);

    if(sinThetaT2 > 1.0) {
	reflect(normal);
    } else{ 
	float cosThetaT = std::sqrt(1 - sinThetaT2);
	direction.x = (ratio * direction.x) + (ratio * cosThetaI - cosThetaT) * normal.x;
	direction.y = (ratio * direction.y) + (ratio * cosThetaI - cosThetaT) * normal.y;
	direction.z = (ratio * direction.z) + (ratio * cosThetaI - cosThetaT) * normal.z;
    }
}

void LightRay::reflect(const Vector3d& normal) {
    float dot = direction.dotProduct(normal);
    direction.x = direction.x - 2 * dot * normal.x;
    direction.y = direction.y - 2 * dot * normal.y;
    direction.z = direction.z - 2 * dot * normal.z;
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
