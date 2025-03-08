#pragma once
#include "orbitalMechanics.hpp"

class OrbitSimulation{
private:
    OrbitalMechanics orbitSim;
    // Function that handles the user input for selecting a planet
    bool handlePlanetMassInput();

    // Function that handles the user input for setting the moon mass
    bool handleMoonMassInput();    

    // Function that handles the updates of parameters from the user
    bool handleParameterUpdate();

public:
    // This is the interface for the user, which starts/ runs the simulation and collects input
    void runSimulation();
};
