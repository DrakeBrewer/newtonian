#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <string>
using namespace std;

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
    void setMass(float m){
        if(m <= 0 | NULL){
            mass = 1;
        }
        else if(m > 1000){
            mass = 1000;
        }
        else{mass = m;}
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

    void setX(float newX){
        if(newX > 0){
            x = newX;
        }
        else{ x = 0;}
    }

    void setY(float newY){
        if(newY> 0){
            y = newY;
        }
        else{ y = 0;}
    }

    void setZ(float newZ){

        if(newZ > 0){
            z = newZ;
        }
        else {z = 0;}
    }

    float getX(){ return x;}

    float getY(){ return y;}

    float getZ(){ return z;}

    float getMass(){return mass;}
};

#endif