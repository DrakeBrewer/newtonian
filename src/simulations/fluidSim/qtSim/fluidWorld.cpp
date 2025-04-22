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
	//this->bodies[0-2] // The liquids , the rest are objects
    fluidBody* liquid;

    //For each spawned object
    for (auto& body : this->bodies) {
        if(body->position.x < -11.111) liquid = this->bodies[1]; // corn syrup
        else if(body->position.x < 11.111) liquid = this->bodies[0]; // water
        else liquid = this->bodies[2]; // oil

        // Skip non moving objects (walls, liquids)
        if(!body->isStatic) {
            Vector3d force(0, 0, 0);
            force = netForce(body,liquid,this->gravity);

            body->applyForce(force); 
		    body->update(delta);
        }
    }
}

Vector3d netForce(fluidBody *obj, fluidBody *liquid, float gravity){
    float g = -gravity;  // Down direction is negative
    float weight = obj->mass * g; // Downward force

    Vector3d drag;
    float buoyantForce;
    float airDensity = 1.225;
    Vector3d velocity  = obj->velocity;

    // Object is above the liquid
    if(obj->position.z >= (liquid->height + liquid->position.z )){
        drag = .5 * obj->dragCoe * airDensity * obj->area() * velocity *
         (std::abs(velocity.x), std::abs(velocity.y),  std::abs(velocity.z)); // Upward force
        
        Vector3d force(-drag.x,-drag.y,weight-drag.z);
        return force;
    }

    // Object is interacting with the water
    buoyantForce = liquid->density * obj->volume * (-g); // Upward force
    
    drag = .5 * obj->dragCoe * liquid->density * obj->area() * velocity *
    (std::abs(velocity.x), std::abs(velocity.y),  std::abs(velocity.z)); // Upward force

    Vector3d force(-drag.x,-drag.y,weight + buoyantForce - drag.z);
    return force;
}