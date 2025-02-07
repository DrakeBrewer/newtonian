#include <iostream>
#include "orbitalMechanics.h"
#include "object.h"

void testOrbitalMechanics(){
    Object testObject; // Make an instance of Object since it contains orbitalMechanics

    // Print out the default values for orbitalMechanics
    std::cout << "This is the Orbital Mechanics File" << std::endl;
    std::cout << "Planet Mass: " << testObject.orbitalMechanics.planetMass << " [kg]" << std::endl;
    std::cout << "Moon Mass: " << testObject.orbitalMechanics.moonMass << " [kg]" << std::endl;
    std::cout << "Planet to Moon Distance: " << testObject.orbitalMechanics.planetMoonDistance << " [m]" << std::endl;
    std::cout << "Moon Velocity: " << testObject.orbitalMechanics.moonVelocity << " [m/s]" << std::endl;
    std::cout << "Orbit Time: " << testObject.orbitalMechanics.orbitTime << " [s]" << std::endl;
    std::cout << "Gravitational Constant (G): " << testObject.orbitalMechanics.gravitationalConstant << " [(Nm^2)/(kg^2)]" << std::endl;
}