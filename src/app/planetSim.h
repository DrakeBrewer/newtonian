#ifndef PLANETSIM_H
#define PLANETSIM_H

#include <iostream>
#include <string>
using namespace std;

/*Might not even need this?
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

};*/

class object{//Base object class for spheres, rectangles, cylinders etc.
    string name;
    float initV;
    float mass;
    float x;
    float y;
    float z;

public:
    object(const string &input){//constructor
        name = input;
        mass = 0;
        initV = 0;
        x = 0;
        y = 0;
        z = 0;

    }

    //Getters and setters
    void setMass(float m)
    {
        mass = m;
    }

    void printInfo(){
        cout<<"Object:"<< name<<endl;
        cout<<"Mass:"<<mass<<endl;
        cout<<"Position("<<x<<","<<y<<","<<z<<")"<<endl;

    }
    void printPos(){
        cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
    }

    void setInitV(float newInitV){initV = newInitV;}

    float getInitV(){return initV;}

    void setX(float newX){x = newX;}

    void setY(float newY){y = newY;}

    void setZ(float newZ){z = newZ;}

    float getX(){ return x;}

    float getY(){ return y;}

    float getZ(){ return z;}
};

int runSim(float grav);

#endif