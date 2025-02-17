#pragma once

#include "LightStruct.hpp"

/* 
  This class represents light as a packet of energy; a photon.
  Used for simulating scattering and collision. Anywhere you 
  need a more discrete representation of light
 */
class LightParticle{
    
private: 
    LightStruct properties;
    double energy;

public: 
    LightParticle(double intensity, double frequency, double speed, double x, double y, double z, double energy);
    
    void scatter();
    void collide();
    void showProperties() const;
};
