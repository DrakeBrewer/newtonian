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
private:
    LightStruct properties;
    double phase;

public:
    LightWave(double intensity, double frequency, double speed, double x, double y, double z, double phase);

    virtual void update(double timeStep) override {
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
