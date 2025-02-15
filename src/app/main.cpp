#include <iostream>
#include "orbitalMechanics.hpp"
#include "planeInteraction.h"
#include "planets.hpp"

// TODO: Add your header files here

int main() {
	int userChoice = 0;

	std::cout << "Welcome to Newtonian!" << std::endl;

    // Promt (and reprompt if needed) the user and get their numeric choice
	while(true){
		std::cout << "Choose which physics simulation you want to experiment with..." << std::endl;
		std::cout << "1) Inclined Plane Interaction" << std::endl;
    	std::cout << "2) Time Control System" << std::endl;
    	std::cout << "3) Orbital Mechanics" << std::endl;
    	std::cout << "4) Light Interaction" << std::endl;
    	std::cout << "5) Fluid Mechanics" << std::endl;
    	std::cout << "6) Planetary Physics" << std::endl;
    	std::cout << "7) Collision System" << std::endl;
    	std::cout << "Enter the number you want to go to: ";
    	std::cin >> userChoice;

		if(userChoice > 0 && userChoice < 8){
			break;
		}
		std::cout << "ERROR: Please enter a number from 1 to 7" << std::endl;
	}

    // Switch case which will execute based on what number the user inputed
	// TODO: Add your functions here
	switch(userChoice){
		case 1:
		    PlaneInteraction();
			break;
		case 2:
		    std::cout << "Selected: Time Control System" << std::endl;
            break;
        case 3:
            std::cout<<"Orbital Mechanics"<<std::endl;
			break;
		case 4:
		    std::cout << "Selected: Light Interaction" << std::endl;
            break;
        case 5:
            std::cout << "Selected: Fluid Mechanics" << std::endl;
            break;
		case 6:
		    std::cout << "Selected: Planetary Physics" << std::endl;
			planetSim();
            break;
        case 7:
            std::cout << "Selected: Collision System" << std::endl;
            break;
	}

	return 0;
}
