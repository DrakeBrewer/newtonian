#pragma once

#include "rigidBody.hpp"
#include "vector3d.hpp"

typedef struct CollisionData {
	bool hasCollision;
	float overlap;
	Vector3d normal;
	Vector3d contactPoint;
} CollisionData_t;

class CollisionSystem {
public:
	CollisionSystem();
	~CollisionSystem() {};

	CollisionData_t data;

	virtual bool checkCollision(RigidBody *bodyA, RigidBody *bodyB);
	virtual void resolveCollision(RigidBody *bodyA, RigidBody *bodyB) {};
};

class SATCollisionSystem : public CollisionSystem {
public:
	SATCollisionSystem() {};
	~SATCollisionSystem() {};

	bool checkCollision(RigidBody *bodyA, RigidBody *bodyB) override;
	void resolveCollision(RigidBody *bodyA, RigidBody *bodyB) override;
private:
	bool ellipseVsEllipse(Ellipse *ellipseA, Ellipse *ellipseB);
	bool ellipseVsPolygon(Ellipse *ellipse, RigidBody *polygon);
	bool polygonVsPolygon(RigidBody *polygonA, RigidBody *polygonB);
};
