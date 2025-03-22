#pragma once
#include "LightBase.hpp"
#include <iostream>

/* 
  This class represents light as a packet of energy; a photon.
  Used for simulating scattering and collision. Anywhere you 
  need a more discrete representation of light
 */
class LightParticle : public LightBase {

public: 
    float energy;
    LightParticle(float frequency, float speed, Vector3d p, Vector3d d, float energy);

    void scatter();
    void collide();
    virtual void showProperties() const override;
    virtual LightBase* clone() const override;
};
