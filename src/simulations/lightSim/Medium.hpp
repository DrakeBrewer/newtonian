#pragma once

class Medium {
protected:
    double refractiveIndex; 

public:
    Medium(double index) : refractiveIndex(index) {}
    virtual ~Medium() {}

    double getRefractiveIndex() const { return refractiveIndex; }
};
