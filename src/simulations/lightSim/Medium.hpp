#pragma once

class Medium {
private:
    double refractiveIndex;

public:
    Medium(double index);

    double getRefractiveIdex() const;
};
