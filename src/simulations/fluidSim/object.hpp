#ifndef OBJECT_H
#define OBJECT_H


// Object that interacts with the fluid

class object{
    float initV;
    float mass;    // kg
    float density; // kg/m^3
    float x, y, z;
    // volume = mass / density

    public:
        // Constructors
        object(){
            mass = 0;
            density = 0;
            initV = 0;
            x = 0;
            y = 0;
            z = 0;
        }

        object(const string obj) : object(){
            if(obj == "wood"){//Pine
                density = 500;
            }
            else if(obj == "aluminium"){
                density = 2710;
            }
            //default
        }

        object(const string obj, float z) : object(obj){
            this->z=z;
        }
        

        // Setters and Getters
        void setMass(float m){mass = m;}
        float getMass(){return mass;}

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
