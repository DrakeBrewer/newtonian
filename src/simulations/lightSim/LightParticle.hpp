#pragma once

#include "LightStruct.hpp"
#include "LightBase.hpp"
#include <iostream>

/* 
  This class represents light as a packet of energy; a photon.
  Used for simulating scattering and collision. Anywhere you 
  need a more discrete representation of light
 */
class LightParticle : public LightBase {
private: 
    LightStruct properties;
    double energy;

public: 
    LightParticle(double intensity, double frequency, double speed, double x, double y, double z, double energy);

    virtual void update(double timeStep) override {
        std::cout << "update photon: " << timeStep << " seconds.\n";
    }
    
    void scatter();
    void collide();
    virtual void showProperties() const override;

    virtual LightBase* clone() const override {
        return new LightParticle(*this);
    }
};
