#pragma once
#include "orbitalMechanics.hpp"

class OrbitSimulation{
public:
    OrbitalMechanics orbitSim;
    // Function that handles the user input for selecting a planet
    bool handlePlanetMassInput();

    // Function that handles the user input for setting the moon mass
    bool handleMoonMassInput();    

    // These functions handle what they say, called for the Qt interface
    bool isValidMoonMass(double userMoonMass);
    double getMinMoonMass();
    double getMaxMoonMass();

    // Function that handles the updates of parameters from the user
    bool handleParameterUpdate();

    // This is the interface for the user, which starts/ runs the simulation and collects input
    void runSimulation();
};
