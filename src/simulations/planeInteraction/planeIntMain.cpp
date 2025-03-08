#include <iostream>
#include "planeInteractionSim.hpp"
#include <limits>

int main() {
	std::cout << "Welcome to the Inclined Plane Simulation!" << std::endl;

	// Allow the user to run multiple simulations.
	char choice = 'y';
	while (choice == 'y' || choice == 'Y') {
		// Run a single simulation iteration.
		runPlaneSimulation();

		// Prompt the user if they want to run another simulation.
		std::cout << "\nWould you like to run another simulation? (y/n): ";
		std::cin >> choice;
		// Clear the input buffer to avoid any stray input.
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;
	}

	std::cout << "Thank you for using the Inclined Plane Simulation. Goodbye!" << std::endl;
	return 0;
}

