#pragma once

class Vector3d {
public:
	Vector3d(): x(0), y(0), z(0) {}
	Vector3d(float x, float y, float z);
	~Vector3d(){};

	float x;
	float y;
	float z;

	// TODO: vector params should be by ref since we prob
	// aren't changing the incoming vector.
	Vector3d crossProduct(const Vector3d& vec);
	float dotProduct(const Vector3d& vec);
	float magnitude();

	// TODO:: https://people.math.harvard.edu/~jjchen/math21a/handouts/vector-ops.html
	// - [ ] Vector addition
	// - [ ] Scalar multiplication
	// - [ ] Transformations?
};

class RigidBody {
public:
	RigidBody(Vector3d initPos, Vector3d initVel, Vector3d initAcc, float mass, bool isStatic);
	~RigidBody(){};

	Vector3d position;
	Vector3d velocity;
	Vector3d acceleration;
	float mass;
	bool isStatic;

	void update(double delta);
	void applyForce(Vector3d force);
};
