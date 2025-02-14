#include <iostream>
#include <iomanip>
#include "orbitSimulation.hpp"

// Function that handles the user input for selecting a planet
bool handlePlanetMassInput(OrbitalMechanics &simulation){
    std::string userPlanet;

    while(true){
        // Prompt user, get input and handle any errors
        std::cout<<"\n<Choose which planet you want to simulate with!"<<std::endl;
        std::cout<<"<Enter Planet Name (or type 'exit' to quit):"<<std::endl;
        std::cout<<">> ";
        std::cin>>userPlanet;

        if(userPlanet == "exit"){
            std::cout<<"Thank you for choosing Orbital Simulator... Goodbye!\n";
            return false;
        }

        // Set the planet user selected with its relevant mass and error check
        if(!simulation.setPlanetType(userPlanet)){
            std::cout<<"\n<ERROR: invalid planet name, please enter a valid planet name from the list!>"<<std::endl;
            continue;
        }

        // Display the details of the planet
        std::cout<<std::scientific<<std::setprecision(5);
        std::cout<<"\n<"<<simulation.planetName<< " Mass: "<<simulation.planetMass<<" [kg]"<<std::endl;
        return true;
    }
}

// Function that handles the user input for setting the moon mass
bool handleMoonMassInput(OrbitalMechanics &simulation){
    // Set var for moon mass, and also min (0.1%) and max (50%) of planet mass for the moon mass range
    double userMoonMass;
    double minMoonMass = (simulation.planetMass * 0.001);
    double maxMoonMass = (simulation.planetMass * 0.5);

    while(true){
        // Prompt user, get input and handle any errors
        std::cout<<"Valid moon mass range:\n"
                <<minMoonMass<<" -> "<<maxMoonMass<<std::endl;
        std::cout<<"\n<Enter the moon's mass in [kg] (or type '-1' to go back to planet selection):"<<std::endl;
        std::cout<<">> ";
        std::cin>>userMoonMass;

        if(userMoonMass == -1){
            std::cout<<"Returning to planet selection..."<<std::endl;
            return false;
        }

        double scalar = 1e-10; // This is very important to scale properly with floating point precision
        if(userMoonMass < (minMoonMass * (1 - scalar)) || userMoonMass > (maxMoonMass * (1 + scalar))){
            std::cout<<"\n<ERROR: Invalid moon mass, please input a moon mass in the valid range!>"<<std::endl;
            continue;
        }

        // Display the details of the moon
        simulation.moonMass = userMoonMass;
        std::cout<<std::scientific<<std::setprecision(5);
        std::cout<<"\n<Moon Mass: "<<simulation.moonMass<<" [kg]"<<std::endl;
        std::cout<<"--------------------------------------------------------------"<<std::endl;

        return true;
    }
}