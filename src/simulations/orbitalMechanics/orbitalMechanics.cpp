#include <iostream>
#include <cmath>
#include <iomanip>
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
    pi = 3.1415926535; // First 10 digits of pi
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
        planetMass = 5.9722e24;
        planetName = "Earth";
        return false;
    }
    return true;
    // And yes, no Pluto, it's not considered a planet anymore, go cry about it...
}

// This method updates the moon's velocity and adjusts the other parameters accordingly
void OrbitalMechanics::updateMoonVelocity(double newVelocity){
    moonVelocity = newVelocity;

    // Since we update moon velocity, we have to update 'r' (planet moon distance) to keep the equation true
    // So from the equation v = sqrt(GM/r) we get r = GM/v^2, which gives us the updated 'r' value
    planetMoonDistance = (gravitationalConstant * planetMass) / (moonVelocity * moonVelocity);

    // Since 'r' has changed, we also have to update the orbital period t = (2pi) * sqrt(r^3/(GM)
    orbitTime = (2 * pi) * sqrt((planetMoonDistance * planetMoonDistance * planetMoonDistance) / (gravitationalConstant * planetMass));

    std::cout << std::scientific << std::setprecision(5);
    std::cout << "\n<Updated Moon Velocity, v = " << moonVelocity << " [m/s]" << std::endl;
    std::cout << "<Updated Planet-Moon Distance, r = " << planetMoonDistance << " [m]" << std::endl;
    std::cout << "<Updated Orbital Period, t = " << orbitTime << " [s] (or " << (orbitTime / 86400) << " [days])" << std::endl;
}

// This method updates the planet's mass and adjusts the other parameters accordingly
void OrbitalMechanics::updatePlanetMass(double newPlanetMass){
    planetMass = newPlanetMass;

    // Since we update planet mass, we can update 'v' or 'r', lets stick with updating 'v', the moon velocity
    // We use equation v = sqrt(GM/r) of the updated velocity of the moon
    moonVelocity = sqrt(gravitationalConstant * planetMass / planetMoonDistance);

    // Since 'v' has changed, we also have to update the orbital period t = (2pi) * sqrt(r^3/(GM)
    orbitTime = (2 * pi) * sqrt((planetMoonDistance * planetMoonDistance * planetMoonDistance) / (gravitationalConstant * planetMass));

    std::cout << std::scientific << std::setprecision(5);
    std::cout << "\n<Updated Planet Mass, M = " << planetMass << " [kg]" << std::endl;
    std::cout << "<Updated Moon Velocity, v = " << moonVelocity << " [m/s]" << std::endl;
    std::cout << "<Updated Orbital Period, t = " << orbitTime << " [s] (or " << (orbitTime / 86400) << " [days])" << std::endl;
}

// This method updates the distance between the planet and moon and adjusts the other parameters accordingly
void OrbitalMechanics::updatePlanetMoonDistance(double newDistance){
    planetMoonDistance = newDistance;

    // Since we update planet-moon distance, we can update 'v' or 'M', lets stick with updating 'v', the moon velocity
    // We use equation v = sqrt(GM/r) of the updated velocity of the moon
    moonVelocity = sqrt(gravitationalConstant * planetMass / planetMoonDistance);

    // Since 'v' has changed, we also have to update the orbital period t = (2pi) * sqrt(r^3/(GM)
    orbitTime = (2 * pi) * sqrt((planetMoonDistance * planetMoonDistance * planetMoonDistance) / (gravitationalConstant * planetMass));

    std::cout << std::scientific << std::setprecision(5);
    std::cout << "\n<Updated Planet-Moon Distance, r = " << planetMoonDistance << " [m]" << std::endl;
    std::cout << "<Updated Moon Velocity, v = " << moonVelocity << " [m/s]" << std::endl;
    std::cout << "<Updated Orbital Period, t = " << orbitTime << " [s] (or " << (orbitTime / 86400) << " [days])" << std::endl;
}
