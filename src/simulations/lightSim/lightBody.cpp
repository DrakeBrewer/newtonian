#include "lightBody.hpp"

LightBody::LightBody(Vector3d initPos, Vector3d dir, float wavelength, float speed)
    : RigidBody(initPos, dir.normalized() * speed, Vector3d(0,0,0), 0.0f, true), wavelength(wavelength), speed(speed), direction(dir.normalized()) {

    this->velocity = direction * speed;
}

// gonna need += operator, need to ask if I can implement it into vector3d
inline Vector3d& addScaler(Vector3d& a, const Vector3d& b, float scalar) {
    a = a + (b * scalar);
    return a;
}

void LightBody::update(double delta) {
    //acceleration and force do not apply to light, need custom update
    addScaler(position, velocity, delta);
}

void LightBody::reflect(Vector3d& normal){
    // Reflection forumla R = D-2(D dot N)N, where R is the reflection
    // vector, D is the incident ray direction, and N is the surface normal.
    // Derived from law of reflection. thetaL=thetaR.
    direction = direction - 2 * (direction.dotProduct(normal)) * normal;
    direction = direction.normalized();
    velocity = direction * speed;
}

void LightBody::refract(Vector3d& normal, float newRefractiveIndex) {
    // Vector form of refraction:
    // T = n*I + (ncos(thetai) - cos(thetat)) * N
    // where	T is a refracted ray direciton vector
    //		I is incident direction vector (normalized)
    //		N is surface normal vector (pointing into incoming medium)
    //		n is the ratio of refractive indices n1/n2
    //		cos(thetai) = -N dot I
    //		cos(thetat) = sqrt(1 - n^2(1-cos^2(thetai))

    float n = refractiveIndex / newRefractiveIndex;
    float cosi = - normal.dotProduct(direction);
    float sin2t = n * n * (1.0f - cosi * cosi);

    if(sin2t > 1.0f) {
	reflect(normal);
	return;
    }

    float cost = std::sqrt(1.0f - sin2t);

    direction = (n * direction + (n * cosi - cost) * normal).normalized();
    refractiveIndex = newRefractiveIndex;
    speed =  2.997925E8 / refractiveIndex;
    velocity = direction * speed;

}

std::unordered_map<std::string, float> LightBody::getAttributes() const {
    std::unordered_map<std::string, float> attributes;

    attributes["position.x"] = position.x;
    attributes["position.y"] = position.y;
    attributes["position.z"] = position.z;

    attributes["velocity.x"] = velocity.x;
    attributes["velocity.y"] = velocity.y;
    attributes["velocity.z"] = velocity.z;

    attributes["wavelength"] = wavelength;
    attributes["speed"] = speed;
    attributes["refractiveIndex"] = refractiveIndex;

    return attributes;
}
