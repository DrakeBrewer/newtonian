#pragma once
#include <string>

class OrbitalMechanics{
public:
    double planetMass; // this is m1, the mass of the planet [kg]
    double moonMass; // this is m2, the mass of the moon in orbit [kg]
    double planetMoonDistance; // distance between center of planet and moon [m]
    double moonVelocity; // velocity of the moon [m/s]
    double orbitTime;  // time it takes for the moon to do 1 orbit [s]
    double gravitationalConstant; // big G
    std::string planetName; // This is for the name of the planet from the solar system

    // Constructor to init the default values for planet being Earth and moon the Moon
    OrbitalMechanics(); 
    
    // This method sets the relevant mass for the chosen planet type
    // Which it returns true if the planet name is valid, otherwise false
    bool setPlanetType(const std::string& name);

    // This method updates the moon's velocity and adjusts the other parameters accordingly
    void updateMoonVelocity(double newVelocity);

    // This method updates the planet's mass and adjusts the other parameters accordingly
    void updatePlanetMass(double newPlanetMass);

    // This method updates the moon's mass and adjusts the other parameters accordingly
    void updateMoonMass(double newMoonMass);

    // This method updates the distance between the planet and moon and adjusts the other parameters accordingly
    void updatePlanetMoonDistance(double newDistance);
};

