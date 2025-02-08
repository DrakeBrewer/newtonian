#ifndef FLUIDSIM_H
#define FLUIDSIM_H

#include <iostream>
#include <string>
using namespace std;

class object{//Base object
    float initV;
    float mass;
    float density;
    float x, y, z;

    public:
        object(){
            mass = 0;
            initV = 0;
            x = 0;
            y = 0;
            z = 0;
        }
        object(int Z){
            mass = 0;
            initV = 0;
            x = 0;
            y = 0;
            z = Z;
        }

        void setMass(float m){mass = m;}

        void setInitV(float newInitV){initV = newInitV;}
        float getInitV(){return initV;}

        void setX(float newX){x = newX;}
        void setY(float newY){y = newY;}
        void setZ(float newZ){z = newZ;}

        float getX(){ return x;}
        float getY(){ return y;}
        float getZ(){ return z;}

        void printPos(){
            cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
        }
};


class fluid{
    float density;
    float fluidLevel; // top of the fluid
    float viscosity;
    float pressure;

    public:
        fluid(){
            density = 0;
            fluidLevel = 0;
            viscosity = 0;
            pressure = 0;
        }
        //add constructors that will set values for liquids like water
        

        void setDensity(float d){density = d;}
        void setFL(float fl){fluidLevel = fl;}
        void setViscosity(float v){viscosity = v;}
        void setPressure(float p){pressure = p;}

        float getDensity(){ return density;}
        float getFL(){ return fluidLevel;}
        float getViscosity(){ return viscosity;}
        float getPressure(){ return pressure;}
        
};

int runTest1();
int runTest2();

#endif
