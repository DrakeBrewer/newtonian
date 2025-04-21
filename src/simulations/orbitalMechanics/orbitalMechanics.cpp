#include <iostream>
#include <cmath>
#include <iomanip>
#include "orbitalMechanics.hpp"


// Constuctor that init the default values for orbital mechanics
OrbitalMechanics::OrbitalMechanics(){
    // Default parameters for the Planet and Moon
    planetName = "Earth";
    setPlanetType(planetName);
    moonMass = 7.348e22; // [kg]
    planetMoonDistance = 3.844e8; // [m]
    moonVelocity = 1022; // [m/s]
    orbitTime = 2.36e6; // [s]
    gravitationalConstant = 6.67430e-11; // [(N.m^2)/kg^2]
    pi = 3.1415926535; // First 10 digits of pi

    // Default 2D orbit parameters for the moon orbit
    // I just want the default start position of the moon to be (0,r) with r being the planet-moon distance
    // So everytime the moon passes the (0,r) mark, the dayCounter will be incremented
    // IMPORTANT: The velocity is scaled by a scalar so that the orbit is visually sped up
    // Nobody wants to sit and watch the position of the moon be in real time (that would take almost a month)
    // So to fix that, the velocity will be multiplied by a scalar so that a full orbit will take just minute(s)
    angle = (pi/2);
    orbitCounter = 0;

    // Since I am also now working with orbit, I have to convert from a polar representation of the moon's position
    // to Cartesian, simply by multiplying the distance by cos and sin of the starting angle (pi/2) so it starts 
    // at (0,r)
    posX = (planetMoonDistance * cos(angle));
    posY = (planetMoonDistance * sin(angle));
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
}

// This method updates moon's 2D position around the planet based on orbital kinematics, there is kind of a lot to explain the logic behind this...
void OrbitalMechanics::updateMoonOrbitalPosition(double timeInterval, int timeScalar = 59000){
    // Looking back at my physics notes there are multiple ways to calculate the angular velocity of the moon
    // Either with omega = (2pi / T) or omega = (v / r) where v = moon velocity and r = planet to moon distane
    // I will be sticking with omega = (v / r) since it is just more straightforward with my code
    double omega = (moonVelocity / planetMoonDistance);

    // This is where I update the angle of the moon. timeScalar is by how much I scale the time for the orbit
    // For example, the moon take 26.3 days to complete an orbit which is too much time to sit and watch live 
    // here, I want an orbit to be represented in 40 seconds, to I divided 26.3days/40seconds to get a scalar
    // of 59,000. So every second that passes in the simulation is equivalent of 59,000 seconds passing in real
    // time. And timeInterval is how often the output is updated, this is to simulate watching
    // the posX and posY in real time. Like I could have timeInterval be 0.05, so it would update
    // 20 times a second, so kinda like being 20fps. 
    double adjustedTimeInterval = (timeInterval / 1000);
    angle -= (omega * (adjustedTimeInterval * timeScalar));

    posX = (planetMoonDistance * cos(angle));
    posY = (planetMoonDistance * sin(angle));

    // This just keeps track of how many orbits the moon completed around the planet. Every time the moon passes
    // (0,r) the dayCounter incremenets
    if(angle < (pi / 2 - 2 * pi)){
        angle += (2 * pi);
        orbitCounter++;
    }
}
