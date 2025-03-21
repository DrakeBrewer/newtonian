#include "vector3d.hpp"
#include <cmath>

Vector3d::Vector3d(float x, float y, float z): x(0), y(0), z(0) {
	this->x = x;
	this->y = y;
	this->z = z;
}

// internal X vec
Vector3d Vector3d::crossProduct(const Vector3d& vec) {
	float i = (this->y * vec.z) - (this->z * vec.y);
	float j = (this->x * vec.z) - (this->z * vec.x);
	float k = (this->x * vec.y) - (this->y * vec.x);

	return Vector3d(i, j, k);
}

float Vector3d::dotProduct(const Vector3d& vec) {
	 return (this->x * vec.x) + (this->y * vec.y) + (this->z * vec.z);
}

float Vector3d::magnitude() {
	float sum = std::pow(this->x, 2) + std::pow(this->y, 2) + std::pow(this->z, 2);
	return std::sqrt(sum);
}
