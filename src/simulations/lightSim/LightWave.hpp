#pragma once

#include "LightStruct.hpp"

/* 
  This class represents light as a wave. Useful for simulating
  wave optics like interference, diffraction, polarization, and
  wave shifts.
*/

class LightWave {
private:
    LightStruct properties;
    double phase;

public:
    LightWave(double intensity, double frequency, double speed, double x, double y, double z, double phase);

    void interfere();
    void diffract();
    void showProperties() const;
};
