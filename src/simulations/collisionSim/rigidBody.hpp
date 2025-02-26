#pragma once

class Vector3d {
public:
	Vector3d(): x(0), y(0), z(0) {}
	Vector3d(float x, float y, float z);
	~Vector3d(){};

	float x;
	float y;
	float z;

	Vector3d crossProduct(Vector3d vec);
	float dotProduct(Vector3d vec);
	float magnitude();
};

typedef struct Position {
	float x;
	float y;
	float z;
} Position_t;

class RigidBody {
public:
	RigidBody(Position initPos, Vector3d initVel, Vector3d initAcc, float mass, bool isStatic);
	~RigidBody(){};

	Position_t position;
	Vector3d velocity;
	Vector3d acceleration;
	float mass;
	bool isStatic;
};
