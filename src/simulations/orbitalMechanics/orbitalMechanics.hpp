#pragma once
#include <string>

struct OrbitalMechanics{
    double planetMass; // this is m1, the mass of the planet [kg]
    double moonMass; // this is m2, the mass of the moon in orbit [kg]
    double planetMoonDistance; // distance between center of planet and moon [m]
    double moonVelocity; // velocity of the moon [m/s]
    double orbitTime;  // time it takes for the moon to do 1 orbit [s]
    double gravitationalConstant; // big G
    std::string planetName; // This is for the name of the planet from the solar system

    // Constructor and the function for setting the proper planet mass with respect to the planet
    OrbitalMechanics(); 
    bool setPlanetType(const std::string& name);
};

