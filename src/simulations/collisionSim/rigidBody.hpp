#pragma once

class Vector3d {
public:
	float x;
	float y;
	float z;

	float crossProduct(Vector3d vec);
	float dotProduct(Vector3d vec);
	float magnitude();
};

typedef struct Position {
public:
	float x;
	float y;
	float z;
} Position_t;

class RigidBody {
	Position_t position;
	Vector3d velocity;
	Vector3d acceleration;
	float mass;
};
