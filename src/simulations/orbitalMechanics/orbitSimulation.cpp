#include <iostream>
#include <iomanip>
#include "orbitSimulation.hpp"

// Function that handles the user input for selecting a planet
bool OrbitSimulation::handlePlanetMassInput(){
    std::string userPlanet;

    // Prompt the user over and over until a valid planet is selected
    while(true){
        // Prompt user, get input and handle any errors
        std::cout<<"\n<Choose which planet you want to simulate with!"<<std::endl;
        std::cout<<"<Enter Planet Name (or type 'exit' to quit):"<<std::endl;
        std::cout<<">> ";
        std::cin>>userPlanet;

        // exit the program if the user types 'exit'
        if(userPlanet == "exit"){
            std::cout<<"Thank you for choosing Orbital Simulator... Goodbye!\n";
            return false;
        }

        // Set the planet user selected with its relevant mass and error check
        if(!orbitSim.setPlanetType(userPlanet)){
            std::cout<<"\n<ERROR: invalid planet name, please enter a valid planet name from the list!>"<<std::endl;
            continue;
        }

        // Display the details of the planet of course with scientific notation
        std::cout<<std::scientific<<std::setprecision(5);
        std::cout<<"\n<"<<orbitSim.planetName<< " Mass: "<<orbitSim.planetMass<<" [kg]"<<std::endl;
        return true;
    }
}

// Function that handles the user input for setting the moon mass
bool OrbitSimulation::handleMoonMassInput(){
    // Set var for moon mass, and also min (0.1%) and max (50%) of planet mass for the moon mass range
    double userMoonMass;
    double minMoonMass = (orbitSim.planetMass * 0.001);
    double maxMoonMass = (orbitSim.planetMass * 0.1);

    std::cout<<"Valid moon mass range:\n"
                <<minMoonMass<<" -> "<<maxMoonMass<<std::endl;
                
    // Prompt the user over and over until a valid moon mass is selected
    while(true){
        // Show the valid mass range of the moon relative to the selected planet mass
        std::cout<<"\n<Enter the moon's mass in [kg] (or type '-1' to go back to planet selection):"<<std::endl;
        std::cout<<">> ";
        std::cin>>userMoonMass;

        if(userMoonMass == -1){
            std::cout<<"Returning to planet selection..."<<std::endl;
            return false;
        }

        std::cout << "Entered Moon Mass: " << userMoonMass;

        double scalar = 1e-10; // This is very important to scale properly with floating point precision
        if(userMoonMass < (minMoonMass * (1 - scalar)) || userMoonMass > (maxMoonMass * (1 + scalar))){
            std::cout<<"\n<ERROR: Invalid moon mass, please input a moon mass in the valid range!>"<<std::endl;
            continue;
        }

        // Display the details of the moon
        orbitSim.moonMass = userMoonMass;
        std::cout<<std::scientific<<std::setprecision(5);
        std::cout<<"\n<Moon Mass: "<<orbitSim.moonMass<<" [kg]"<<std::endl;
        std::cout<<"--------------------------------------------------------------"<<std::endl;
        return true;
    }
}

bool OrbitSimulation::handleParameterUpdate(){
    int parameterChoice;
    double newParameterValue;

    std::cout<<"\n===========Now You Can Update Equation Parameters===========" << std::endl;
    std::cout << "1) Update Moon Velocity" << std::endl;
    std::cout << "2) Update Planet Mass" << std::endl;
    std::cout << "3) Update Planet-Moon Distance" << std::endl;
    std::cout << "0) Exit Parameter Updates" << std::endl;
    std::cout << "Enter Parameter Update Choice: ";
    std::cin>> parameterChoice;

    if(parameterChoice == 0){
        std::cout << "Exiting Parameter Updates..."<<std::endl;
        return false;
    }
    else if(parameterChoice == 1){
        std::cout << "\n<Enter new moon velocity [m/s]: ";
        std::cin >> newParameterValue;
        orbitSim.updateMoonVelocity(newParameterValue);
    }
    else if(parameterChoice == 2){
        std::cout << "\n<Enter new planet mass [kg]: ";
        std::cin >> newParameterValue;
        orbitSim.updatePlanetMass(newParameterValue);
    }
    else if(parameterChoice == 3){
        std::cout << "\n<Enter new planet-moon distance [m]: ";
        std::cin >> newParameterValue;
        orbitSim.updatePlanetMoonDistance(newParameterValue);
    }
    else{
        std::cout<<"\n<ERROR: Invalid parameter update choice, select options 0-3>"<<std::endl;
    }
    return true;
}

// This is the interface for the user, which starts/ runs the simulation and collects input
void OrbitSimulation::runSimulation(){
    std::cout<<"=============================================================="<<std::endl;
    std::cout<<"          Welcome to the Orbital Mechanics Simulator!         "<<std::endl;
    std::cout<<"--------------------------------------------------------------"<<std::endl;
    std::cout<<"\nDefault planet is Earth and default moon is Earth's Moon"<<std::endl;
    std::cout<<"Here is the list of planets you can run the simulation with:"<<std::endl;
    std::cout<<"1) Mercury"<<std::endl;
    std::cout<<"2) Venus"<<std::endl;
    std::cout<<"3) Earth"<<std::endl;
    std::cout<<"4) Mars"<<std::endl;
    std::cout<<"5) Jupiter"<<std::endl;
    std::cout<<"6) Saturn"<<std::endl;
    std::cout<<"7) Uranus"<<std::endl;
    std::cout<<"8) Neptune"<<std::endl;
    std::cout<<"=============================================================="<<std::endl;
    
    // TEMP: real-time updates are loop driven, with Qt it'll be updated to be event-driven
    while(true){
        // Handle planet mass
        if(!handlePlanetMassInput()){
            break;
        }
        // Handle moon mass, only after a valid planet is selected 
        if(!handleMoonMassInput()){
            continue;
        }
        // Handle parameter updates
        while(handleParameterUpdate()){
            continue;
        }
    }
}