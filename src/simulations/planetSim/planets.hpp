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
    planet(const string &input){//Constructor
        planetName = input;
        
    }
    object spawnObj(const string &input){//Allow a planet to spawn and object
        return object(input);
    }

    plane spawnPlane(const string &input){
        return plane(input);
    }

    //Getters and setters
    void setGrav() {
        if (planetName == "earth") gravity = 9.81f;
        else if (planetName == "moon") gravity = 1.62f;
        else if (planetName == "mercury") gravity = 3.7f;
        else if (planetName == "venus") gravity = 8.87f;
        else if (planetName == "mars") gravity = 3.73f;
        else if (planetName == "jupiter") gravity = 24.79f;
        else if (planetName == "saturn") gravity = 10.44f;
        else if (planetName == "uranus") gravity = 8.87f;
        else if (planetName == "neptune") gravity = 11.15f;
        else gravity = 9.81f;
    }
    
    float getGrav(){ return gravity;};

};

//Function Prototypes
int planetSim();
int setSim(planet p);
int freeFall(object obj, planet p, plane pl);

#endif