#include "vector3d.hpp"
#include <cmath>
#include <stdexcept>

Vector3d::Vector3d(float x, float y, float z): x(0), y(0), z(0) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3d Vector3d::operator+(const Vector3d& vec) const {
	return Vector3d(
		this->x + vec.x,
		this->y + vec.y,
		this->z + vec.z
	);
}

Vector3d Vector3d::operator-(const Vector3d& vec) const {
	return Vector3d(
		this->x - vec.x,
		this->y - vec.y,
		this->z - vec.z
	);
}

Vector3d Vector3d::operator-() const {
	return Vector3d(-this->x, -this->y, -this->z);
}

Vector3d Vector3d::operator*(float scalar) const {
	return Vector3d(
		this->x * scalar,
		this->y * scalar,
		this->z * scalar
	);
}

Vector3d operator*(float scalar, const Vector3d& vec) {
	return vec * scalar;
}

Vector3d Vector3d::operator/(float scalar) const {
	if (scalar != 0) {
		return Vector3d(
			this->x / scalar,
			this->y / scalar,
			this->z / scalar
		);
	}

	throw std::overflow_error("Divide by zero exception");
}

// internal X vec
Vector3d Vector3d::crossProduct(const Vector3d& vec) {
	float i = (this->y * vec.z) - (this->z * vec.y);
	float j = (this->x * vec.z) - (this->z * vec.x);
	float k = (this->x * vec.y) - (this->y * vec.x);

	return Vector3d(i, j, k);
}

Vector3d Vector3d::projectOnto(const Vector3d& vec) {
	float dot = this->dotProduct(vec);
	float sum = std::pow(vec.x, 2) + std::pow(vec.y, 2) + std::pow(vec.z, 2);
	float magSqrd = std::sqrt(sum) * std::sqrt(sum);

	return (dot / magSqrd) * vec;
}

Vector3d Vector3d::normalize() {
	float magnitude = this->magnitude();

	return Vector3d(
		this->x / magnitude,
		this->y / magnitude,
		this->z / magnitude
	);
}

float Vector3d::dotProduct(const Vector3d& vec) {
	 return (this->x * vec.x) + (this->y * vec.y) + (this->z * vec.z);
}

float Vector3d::magnitude() {
	float sum = std::pow(this->x, 2) + std::pow(this->y, 2) + std::pow(this->z, 2);
	return std::sqrt(sum);
}
