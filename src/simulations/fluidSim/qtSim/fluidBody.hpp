#pragma once

#include "rigidBody.hpp"
#include "vector3d.hpp"

#include <cmath>
#include <iostream>


#define PI 3.14f


// Rigid Body but for objects in the fluid sim
class fluidBody : public RigidBody {
    public:
        float dragCoe;
        float volume;
        float density;
        float radius;
        float height;

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
        
        void update(double delta);
        void applyForce(Vector3d force);


};


class fluidEllipse : public fluidBody {
public:

    fluidEllipse(Vector3d position, bool isStatic,
        float dragCoe, float density)
    {   
        this->volume = 3; //3m^3
	    this->position = position;
        this->density = density;
	    this->mass = this->volume * this->density;
	    this->isStatic = isStatic;
        this->dragCoe = dragCoe;
        this->radius = std::cbrt((3*this->volume)/(4*PI));    //meters

    }
    
    ~fluidEllipse() {};
    
    
    void update(double delta);
    float area() override{
        return  PI * this->radius * this->radius;
    }
    float diameter();
};


class fluidRectangle : public fluidBody {
public:
    float width;
    

    Vector3d vertices[4];
    

    fluidRectangle(Vector3d position, bool isStatic,float dragCoe,  float density)
    {   
        this->volume = 3; //3m^3
        this->width = std::cbrt(this->volume);
	    this->height = this->width;
        
        
	    this->position = position;
        this->density = density;
        this->mass = this->volume * this->density;
	    this->isStatic = isStatic;
        this->dragCoe = dragCoe;
        
	    float halfWidth = float(width) / 2;
	    float halfHeight = float(height) / 2;

	    this->vertices[0] = Vector3d(this->position.x - halfWidth, this->position.y - halfHeight, 0); // bottom Left
	    this->vertices[1] = Vector3d(this->position.x - halfWidth, this->position.y + halfHeight, 0); // bottom Right
	    this->vertices[2] = Vector3d(this->position.x + halfWidth, this->position.y - halfHeight, 0); // top Left
	    this->vertices[3] = Vector3d(this->position.x + halfWidth, this->position.y + halfHeight, 0); // top right
    }
    fluidRectangle(float width, float height, Vector3d position, bool isStatic){
        this->width = width;
        this->height = height; 
        this->position = position; 
        this->isStatic = isStatic;
    }

    ~fluidRectangle() {};

    float area() override{
        return  this->width * this->height;
    }
        
    void update(double delta);
};    

class fluidTriangle : public fluidBody {
public:
    float width;
	float height;
    int direction; // where the tip is pointing, 1: up, 2: down

	Vector3d vertices[3];

    fluidTriangle(Vector3d position, bool isStatic,  int direction, float dragCoe,  float density){
        this->volume = 3; //3m^3
        this->width = std::cbrt(this->volume);
	    this->height = this->width;
	    this->direction = direction;
        this->position = position;
	    this->isStatic = isStatic;
        this->density = density;
        this->mass = this->volume * this->density;
        this->dragCoe = dragCoe;  // Not accurate since it changes depending on the direction it's moving

	    this->updateVertices();
    }
	~fluidTriangle() {};

	
	void update(double delta);
	void updateVertices();
	float area() override{ 
        return  this->width * this->height;
    }
};

//--------------Liquid----------------//

class fluidLiquid : public fluidBody {
    public:
        float width;
        
    
        fluidLiquid(float width, float height, Vector3d position, bool isStatic,
            float density)
        {   
            this->width = width;
            this->height = height;
            this->position = position;
            this->density = density;
            
            this->isStatic = isStatic;
            
        }
        ~fluidLiquid() {};
    };   