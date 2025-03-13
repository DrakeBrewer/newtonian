#ifndef OBJECT_H
#define OBJECT_H

#include <cmath>
using namespace std;
// Object that interacts with the fluid

class object{
    public:
        string name;
        int shape; // For now: 0: Cube , 1: Sphere
        float dragCoe;
        float initV;
        float mass;    // kg
        float density; // kg/m^3
        float volume;  // mass / density
        float x, y, z;

        // Constructors
        object(){
            shape = 0; // Cube
            dragCoe = 1.05; //Drag Coefficient for a cube
            mass = 0;
            density = 0;
            volume = 0.1; // 10 cm^2
            initV = 0;
            x = 0;
            y = 0;
            z = 0;
        }

        object(const string obj) : object(){
            if(obj == "wood"){//Pine
                density = 500;
                mass = density * volume;
            }
            else if(obj == "aluminium"){
                density = 2710;
                mass = density * volume;
            }
            else if(obj == "rock"){
                density = 2500;
                mass = density * volume;
            }
            name = obj;
            //default
        }

        object(const string obj, float z) : object(obj){
            this->z=z;
        }
        
        float area(){
            if(shape == 0) return pow(cbrt(volume),2); //area for a cube
            return 3.14159 * pow( cbrt( (3*volume) / (4*3.14159) ),2); //area for a sphere
        }


        // Setters and Getters
        void setDensity(float d){density = d;}
        float getDensity(){return density;}

        void setMass(float m){mass = m;}
        float getMass(){return mass;}

        void setVolume(float v){volume = v;}
        float getVolume(){return volume;}

        void setInitV(float newInitV){initV = newInitV;}
        float getInitV(){return initV;}

        void setX(float newX){x = newX;}
        void setY(float newY){y = newY;}
        void setZ(float newZ){z = newZ;}

        float getX(){ return x;}
        float getY(){ return y;}
        float getZ(){ return z;}
};

#endif
