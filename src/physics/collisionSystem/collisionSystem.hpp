#pragma once
#include "rigidBody.hpp"
#include "vector3d.hpp"

class Projection {
	float min;
	float max;

	bool isOverlapping(const Projection &other);
	float calcOverlap(const Projection &other);
};

typedef struct collisionData {
    Vector3d collisionNormal;
    Vector3d collisionPoint;
    bool hasCollided;
} collisionData_t;

class CollisionSystem {
public:
	CollisionSystem();
	~CollisionSystem();

	collisionData_t *state;

	bool checkOverlap();

	bool detectCollision();
	void resolveCollision();

	// SAT specific funcitons
	Vector3d findSeparatingAxis();

};

class CollisionResolver {
public:
	CollisionResolver(float restitution);
	~CollisionResolver() {};

	float restitution;

	void resolveCollision(RigidBody *bodyA, RigidBody *bodyB);
};
