#ifndef FLUID_H
#define FLUID_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

//#include "object.hpp"
using namespace std;

class fluid{
    float density; //kg/m^3
    float fluidLevel; // top of the fluid
    float viscosity;
    float pressure;
    
    public:
        string name;
        // Constructors
        fluid(){
            density = 0;
            fluidLevel = 0;
            viscosity = 0;
            pressure = 0;
        }

        fluid(const string liquid) : fluid(){
            if(liquid == "water"){
                density = 1000;
            }else if(liquid == "oil"){ //diesel
                density = 800;
            }else if(liquid == "corn syrup"){
                density = 1380;
            }
            name = liquid;
            //Default
        }
        
        fluid(const string liquid, float fluidLevel) : fluid(liquid){ 
            this->fluidLevel = fluidLevel;
        }
        
        // Setters and Getters

        void setDensity(float d){density = d;}
        void setFL(float fl){fluidLevel = fl;}
        void setViscosity(float v){viscosity = v;}
        void setPressure(float p){pressure = p;}
        float getDensity(){ return density;}
        float getFL(){ return fluidLevel;}
        float getViscosity(){ return viscosity;}
        float getPressure(){ return pressure;}
};

// Prototypes
// test
int run();
int runTest1();
int runTest2();
// functions
//float netForce(object obj, fluid liquid, float velocity);
#endif
