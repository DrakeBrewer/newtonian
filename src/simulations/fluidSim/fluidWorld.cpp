#include "fluidWorld.hpp"
#include <cstdint>
#include <iostream>

fluidPhysicsWorld::fluidPhysicsWorld(float gravity) {
	this->gravity = gravity;
}

void fluidPhysicsWorld::addBody(fluidBody *body, uint8_t color[3]) {
	this->bodies.push_back(body);
}

void fluidPhysicsWorld::tick(double delta) {
	this->timeElapsed += delta;
	// std::cout << "\r" << std::fflush(stdout) << "Time: " << this->timeElapsed;

	for (auto& body : this->bodies) {
        Vector3d force(0, 0, 0);

        if(!body->isStatic) {
            force = force + netForce(body,this->gravity);
            //std::cout << "mass: "<<  body->mass  <<  ", velocity"<<  body->velocity.z  <<
             //", raadius"<<  body->radius  << ", vol"<<  body->volume  <<
            //", draf"<<  body->dragCoe<< ", position:"<< body->position.z <<
            //", area:"<< body->area() << ", accel:"<< body->acceleration.z << std::endl; 
        }
        
        std::cout << "force: " << force.z << std::endl; 

        const Vector3d gravity(0, 0, -this->gravity);
		Vector3d force2(
			gravity.x * body->mass,
			gravity.y * body->mass,
			gravity.z * body->mass
		);

        body->applyForce(force);
		body->update(delta); 
	}
}

Vector3d netForce(fluidBody *body, float gravity){
    float waterDensity = 1000;
    float dragCoefficient = body->dragCoe;
    float g = -gravity;
    std::cout <<  "g:" << g  << std::endl;
    float buoyantForce = waterDensity * body->volume * (-g);
    float weight = body->mass * g;
    //float weight = 0;
    float drag;
    float airDensity = 1.225;
    
    if(body->position.z >= 0 ){
        std::cout <<  "AABOVE WATER" << std::endl;
        drag = .5 * dragCoefficient * airDensity * body->area() * body->velocity.z * std::abs(body->velocity.z);
        Vector3d force(0,0,(weight - drag));
        std::cout <<  "drag: "<<drag<<  "weight: "<< weight << std::endl;
        std::cout <<  " velocity"<<  body->velocity.z  <<
            ", draf"<<  body->dragCoe<< ", position:"<< body->position.z <<
            ", area:"<< body->area() << std::endl; 

        return force;
    }
    drag = .4 * dragCoefficient * waterDensity * body->area() * body->velocity.z * std::abs(body->velocity.z);
    //drag=0;
    Vector3d force(0,0,(weight - buoyantForce - drag));
    std::cout <<  "drag: "<<drag<<  "weight: "<< weight << "buoyancy:" << buoyantForce << std::endl;
    return force;
}