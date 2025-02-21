#ifndef PLANETS_H
#define PLANETS_H

#include <iostream>
#include <string>
#include "objects.hpp"
#include "plane.hpp"
using namespace std;


class planet{
    string planetName;
    float gravity;
    //TODO: Add other fields as for planet characteristics such as temperature, wind speed, etc.

public:
    planet(const string &input,const float g){//Constructor
        planetName = input;
        gravity = g;
        cout << g << endl;
        cout << planetName << endl;
        
    }
    object spawnObj(const string &input){//Allow a planet to spawn and object
        return object(input);
    }

    plane spawnPlane(const string &input){
        return plane(input);
    }

    //Getters and setters
    float getGrav(){ return gravity;};

};

//Function Prototypes
int planetSim();
int setSim(planet p);
int freeFall(object obj, planet p, plane pl);

#endif