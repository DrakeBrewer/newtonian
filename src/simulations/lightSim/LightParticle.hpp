#pragma once
#include "LightBase.hpp"
#include "LightStruct.hpp"
#include <iostream>

/* 
  This class represents light as a packet of energy; a photon.
  Used for simulating scattering and collision. Anywhere you 
  need a more discrete representation of light
 */
class LightParticle : public LightBase {

public: 
    LightStruct properties;
    double energy;

    LightParticle(double intensity, double frequency, double speed, float x, float y, float z, double energy);

    virtual void update(float timeStep) override {
        std::cout << "Update photon: " << timeStep << " seconds.\n";
    }
    
    void scatter();
    void collide();
    virtual void showProperties() const override;

    virtual LightBase* clone() const override {
        return new LightParticle(*this);
    }
};
