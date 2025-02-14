#include <iostream>
#include <iomanip>
#include "orbitalMechanics.hpp"
#include "orbitSimulation.hpp"

int main(){
    OrbitalMechanics runSimulation;

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
        if(!handlePlanetMassInput(runSimulation)){
            break;
        }

        // Handle moon mass
        handleMoonMassInput(runSimulation);
    }

    return 0;
}