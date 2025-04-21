#pragma once

#include "rigidBody.hpp"
#include "vector3d.hpp"

#include <cmath>
#include <iostream>


#define PI 3.14f

// Rigid Body but for an object for the fluid sim
class fluidBody : public RigidBody {
    public:
        float dragCoe;
        float volume;
        float density;
        float radius;

        fluidBody() : RigidBody(){
            float dragCoe = 0;
            float volume = 0.1;
            float density = 0;
            int radius  =  0;
        }

        fluidBody(Vector3d initPos, Vector3d initVel, Vector3d initAcc, float mass, bool isStatic,
            float dragCoe, float volume, float density) : RigidBody(initPos, initVel,
            initAcc, mass, isStatic)
        {  
            this->dragCoe = dragCoe;
            this->volume = volume;
            this->density = density;
        }
        ~fluidBody(){};

        virtual float area(){
            return 0;
        }
        /*Vector3d position;
	    Vector3d velocity;
	    Vector3d acceleration;
	    float mass;*/
        //applyForce()  this->acceleration.x += force.x / this->mass;
};


class fluidEllipse : public fluidBody {
public:

    fluidEllipse(Vector3d position, float mass, bool isStatic,
        float dragCoe, float density)
    {
	    this->position = position;
	    this->mass = mass;
	    this->isStatic = isStatic;
        this->dragCoe = dragCoe;
        this->volume = mass/density;
        this->density = density;
        this->radius = std::cbrt((3*this->volume)/(4*PI));    //meters

    }
    
    ~fluidEllipse() {};
    
    
    void update(double delta);
    float area() override{
        return 2 * PI * this->radius;
    }
    float diameter();
};


class fluidRectangle : public fluidBody {
public:
    int width;
    int height;

    Vector3d vertices[4];
    

    fluidRectangle(int width, int height, Vector3d position, float mass, bool isStatic,
        float density)
    {
        this->width = width;
	    this->height = height;
	    this->position = position;
	    this->mass = mass;
	    this->isStatic = isStatic;
        this->density = density;

	    float halfWidth = float(width) / 2;
	    float halfHeight = float(height) / 2;

	    this->vertices[0] = Vector3d(this->position.x - halfWidth, this->position.y - halfHeight, 0); // bottom Left
	    this->vertices[1] = Vector3d(this->position.x - halfWidth, this->position.y + halfHeight, 0); // bottom Right
	    this->vertices[2] = Vector3d(this->position.x + halfWidth, this->position.y - halfHeight, 0); // top Left
	    this->vertices[3] = Vector3d(this->position.x + halfWidth, this->position.y + halfHeight, 0); // top right
    }
    ~fluidRectangle() {};
        
    void update(double delta);
};    