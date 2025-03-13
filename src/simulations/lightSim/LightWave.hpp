#pragma once

#include "LightBase.hpp"
#include <iostream>

/* 
  This class represents light as a wave. Useful for simulating
  wave optics like interference, diffraction, polarization, and
  wave shifts.
*/

class LightWave : public LightBase {
public:
    float phase;

    LightWave(float frequency, float speed, Vector3d p, Vector3d d, float phase);


    void interfere();
    void diffract();
    virtual void showProperties() const override;

    virtual LightBase* clone() const override;
};
