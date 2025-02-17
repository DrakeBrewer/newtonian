#include "Medium.hpp"

Medium::Medium(double index) : refractiveIndex(index) {}

double Medium::getRefractiveIdex() const {
    return refractiveIndex;
}
