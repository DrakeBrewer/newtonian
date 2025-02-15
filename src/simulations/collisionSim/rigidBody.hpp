#pragma once

class Vector3d {
public:
	Vector3d(float x, float y, float z);
	~Vector3d();

	float x;
	float y;
	float z;

	float crossProduct(Vector3d vec);
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
	RigidBody();
	~RigidBody();

	Position_t position;
	Vector3d velocity;
	Vector3d acceleration;
	float mass;
};
