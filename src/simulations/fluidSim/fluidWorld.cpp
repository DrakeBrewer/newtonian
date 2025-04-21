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
    bool printFlag = true;
	//for (auto& body : this->bodies) {
    //this->bodies[0] // rect (the fluid)
        Vector3d force(0, 0, 0);

        if(!bodies[1]->isStatic) {
            force = netForce(bodies[1],bodies[0],this->gravity);
            if(printFlag){
                fluidBody *body = bodies[1];
                std::cout << "mass: "<<  body->mass  <<  ", velocity"<<  body->velocity.z  <<
                ", raadius"<<  body->radius  << ", vol"<<  body->volume  <<
                ", draf"<<  body->dragCoe<< ", position:"<< body->position.z <<
                ", area:"<< body->area() << ", accel:"<< body->acceleration.z << std::endl; 
            }
        }
    

        bodies[1]->applyForce(force); 
		bodies[1]->update(delta); 
	//}
}

Vector3d netForce(fluidBody *obj, fluidBody *fluid, float gravity){
    //float waterDensity = 1000;
    float dragCoefficient = obj->dragCoe;
    float g = -gravity;
    std::cout <<  " ACCeleration:" << obj->acceleration.z  << std::endl;
    float buoyantForce = fluid->density * obj->volume * (-g);
    float weight = obj->mass * g;
    //float weight = body->mass * body->acceleration.z;
    float drag;
    float airDensity = 1.225;
    
    if(obj->position.z >= 0 ){
        std::cout <<  "AABOVE WATER" << std::endl;
        drag = .5 * dragCoefficient * airDensity * obj->area() * obj->velocity.z * std::abs(obj->velocity.z);
        Vector3d force(0,0,(weight - drag));
        std::cout <<  "drag: "<<drag<<  "weight: "<< weight << std::endl;
        std::cout <<  " velocity"<<  obj->velocity.z  <<
            ", draf"<<  obj->dragCoe<< ", position:"<< obj->position.z <<
            ", area:"<< obj->area() << std::endl; 

        return force;
    }
    drag = .5 * dragCoefficient * fluid->density * obj->area() * obj->velocity.z * std::abs(obj->velocity.z);
    //drag=0;
    Vector3d force(0,0,(weight + buoyantForce - drag));
    std::cout <<  "drag: "<<drag<<  "weight: "<< weight << "buoyancy:" << buoyantForce << std::endl;
    return force;
}