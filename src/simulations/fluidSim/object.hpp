#ifndef OBJECT_H
#define OBJECT_H


// Object that interacts with the fluid

class object{
    float initV;
    float mass;    // kg
    float density; // kg/m^3
    float volume;
    float x, y, z;
    // volume = mass / density

    public:
        // Constructors
        object(){
            mass = 0;
            density = 0;
            volume = 0.01;
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
            }
            else if(obj == "rock"){
                density = 2500;
            }
            //default
        }

        object(const string obj, float z) : object(obj){
            this->z=z;
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
