#pragma once
#include "orbitalMechanics.hpp"

// Function that handles the user input for selecting a planet
bool handlePlanetMassInput(OrbitalMechanics &simulation);

// Function that handles the user input for setting the moon mass
bool handleMoonMassInput(OrbitalMechanics &simulation);