#pragma once
#include "vector3d.hpp"

// Includes for integration with replayTable
#include <variant>
#include <unordered_map>
#include <string>
#include <variant>

#define PI 3.14f

// TODO: Evaluate the need for doubles instead of floats in 
// some of the more critical sections of the sim

class IShape {
public:
	IShape() {};
	virtual ~IShape() {};

	virtual float volume() = 0;
	virtual float surfaceArea() = 0;
};

class RigidBody {
public:
	RigidBody(): 
		position(Vector3d()), 
		velocity(Vector3d()), 
		acceleration(Vector3d()), 
		mass(0), 
		isStatic(false) {};

	RigidBody(Vector3d initPos, Vector3d initVel, Vector3d initAcc, float mass, bool isStatic);
	~RigidBody(){};

	Vector3d position;
	Vector3d velocity;
	Vector3d acceleration;
	float mass;
	// TODO: implement this with quaternions
	// float rotation;

	bool isStatic;

	virtual void update(double delta);
	void applyForce(Vector3d force);

	// (Brendan) method for getting attribute map for replayTable
	virtual std::unordered_map<std::string, float> getAttributes() const;

};

class Sphere : public RigidBody,
	public IShape {
public:
	Sphere(float radius, Vector3d position, float mass);
	~Sphere() {};

	float radius;

	float surfaceArea();
	float volume();
	float diameter();
};

class Cuboid : public RigidBody,
	public IShape {
public:
	Cuboid(float length, float width, float height, Vector3d position, float mass);
	~Cuboid() {};

	float length;
	float width;
	float height;

	Vector3d vertices[8];

	void update(double delta);

	float surfaceArea();
	float volume();
private:
	void updateVertices();
};

class Ellipse : public RigidBody {
public:
	Ellipse(float radius, Vector3d position, float mass, bool isStatic);
	~Ellipse() {};

	int radius;

	void update(double delta);
	float area();
	float diameter();
};

class Rectangle : public RigidBody {
public:
	Rectangle(int width, int height, Vector3d position, float mass, bool isStatic);
	~Rectangle() {};

	int width;
	int height;

	Vector3d vertices[4];

	void update(double delta);
	float area();
};

class Triangle : public RigidBody {
public:
	Triangle(int width, int height, Vector3d position, float mass, bool isStatic);
	~Triangle() {};

	int width;
	int height;

	Vector3d vertices[3];

	void update(double delta);
	float area();
};
