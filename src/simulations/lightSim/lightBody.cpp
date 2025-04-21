#include "lightBody.hpp"


LightBody::LightBody(Vector3d initPos, Vector3d dir, float wavelength, float speed)
    : RigidBody(initPos, dir.normalized() * speed, Vector3d(0,0,0), 0.0f, true), wavelength(wavelength), speed(speed), direction(dir.normalized()) {

    this->velocity = direction * speed;
}

void LightBody::update(double delta) {
    //acceleration and force do not apply to light, need custom update
    this->position.x += this->velocity.x * delta;
    this->position.y += this->velocity.y * delta;
    this->position.z += this->velocity.z * delta;

    std::cout << "\r" << std::fflush(stdout) <<
    	"x: " << this->position.x <<
    	", y: " << this->position.y <<
    	", z: " << this->position.z;

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
