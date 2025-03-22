#pragma once

class Vector3d {
public:
	Vector3d(): x(0), y(0), z(0) {};

	Vector3d(float x, float y, float z);
	~Vector3d(){};

	float x;
	float y;
	float z;

	Vector3d crossProduct(const Vector3d& vec);
	float dotProduct(const Vector3d& vec);
	float magnitude();

	// TODO:: https://people.math.harvard.edu/~jjchen/math21a/handouts/vector-ops.html
	// - [ ] Vector addition
	// - [ ] Scalar multiplication
	// - [ ] Transformations?
};
