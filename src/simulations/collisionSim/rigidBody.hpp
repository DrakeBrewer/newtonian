#pragma once

#define PI 3.14f

// TODO: Evaluate the need for doubles instead of floats in 
// some of the more critical sections of the sim

class IShape {
public:
	IShape();
	virtual ~IShape();

	virtual float volume() = 0;
	virtual float surfaceArea() = 0;
};

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

class RigidBody {
public:
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
	~Cuboid();

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

// TODO: meshes and compound objects?
