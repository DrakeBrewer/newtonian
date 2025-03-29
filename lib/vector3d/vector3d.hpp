#pragma once

class Vector3d {
public:
	Vector3d(): x(0), y(0), z(0) {};

	Vector3d(float x, float y, float z);
	~Vector3d(){};

	float x;
	float y;
	float z;

	Vector3d operator+(const Vector3d& vec) const;
	Vector3d operator-(const Vector3d& vec) const;
	Vector3d operator-() const;
	Vector3d operator*(float scalar) const;
	friend Vector3d operator*(float scalar, const Vector3d& vec);
	Vector3d operator/(float scalar) const;

	Vector3d crossProduct(const Vector3d& vec);
	Vector3d projectOnto(const Vector3d& vec);
	Vector3d normalized();
	Vector3d reflect(); // TODO: implement this

	float dotProduct(const Vector3d& vec);
	float magnitude();

	void normalize();

	// TODO:: https://people.math.harvard.edu/~jjchen/math21a/handouts/vector-ops.html
	// - [ ] Vector addition
	// - [ ] Scalar multiplication
	// - [ ] Transformations?
};
