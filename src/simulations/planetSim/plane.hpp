#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include <string>
using namespace std;
class plane{

    string name;
    int x;
    int y;
    int z;


public:
    plane(const string &input){//Constructor
        name = input;
        x = 0;
        y = 0;
        z = 0;

    }

    //Getters and Setters
    void setX(float newX){x = newX;}

    void setY(float newY){y = newY;}

    void setZ(float newZ){z = newZ;}

    float getX(){ return x;}

    float getY(){ return y;}

    float getZ(){ return z;}


};

#endif