#include <iostream>
#include "orbitalMechanics.hpp"

// Constuctor that init the default values for orbital mechanics
OrbitalMechanics::OrbitalMechanics(){
    planetName = "Earth";
    setPlanetType(planetName);
    moonMass = 7.348e22; // [kg]
    planetMoonDistance = 3.844e8; // [m]
    moonVelocity = 1022; // [m/s]
    orbitTime = 2.36e6; // [s]
    gravitationalConstant = 6.67430e-11; // [(N.m^2)/kg^2]
}

// Function that sets the planet type and its corresponding mass, return true if valid, false otherwise
bool OrbitalMechanics::setPlanetType(const std::string& name){
    if (name == "Mercury"){
        planetMass = 3.301e23;
        planetName = "Mercury";
    }
    else if (name == "Venus"){
        planetMass = 4.86732e24;
        planetName = "Venus";
    }
    else if (name == "Earth"){
        planetMass = 5.9722e24;
        planetName = "Earth";
    }
    else if (name == "Mars"){
        planetMass = 6.4171e23;
        planetName = "Mars";
    }
    else if (name == "Jupiter"){
        planetMass = 1.899e27;
        planetName = "Jupiter";
    }
    else if (name == "Saturn"){
        planetMass = 5.685e26;
        planetName = "Saturn";
    }
    else if (name == "Uranus"){
        planetMass = 8.682e25;
        planetName = "Uranus";
    }
    else if (name == "Neptune"){
        planetMass = 1.024e26;
        planetName = "Neptune";
    }
    else{
        return false;
    }
    return true;
    // And yes, no Pluto, it's not considered a planet anymore, go cry about it...
}
