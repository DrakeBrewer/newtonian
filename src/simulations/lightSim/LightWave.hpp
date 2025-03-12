#pragma once

#include "LightStruct.hpp"
#include "LightBase.hpp"
#include <iostream>

/* 
  This class represents light as a wave. Useful for simulating
  wave optics like interference, diffraction, polarization, and
  wave shifts.
*/

class LightWave : public LightBase {
public:
    LightStruct properties;
    float phase;

    LightWave(double intensity, double frequency, double speed, float x, float y, float z, float phase);


    virtual void update(float timeStep) override {
        phase += timeStep;
        std::cout << "update wave: " << timeStep << " seconds\n";
    }
    
    void interfere();
    void diffract();
    virtual void showProperties() const override;

    virtual LightBase* clone() const override {
        return new LightWave(*this);
    }
};
