#include <iostream>
#include "planeInteractionSim.hpp"
#include <limits>

int main() {
		std::cout << "Welcome to the Inclined Plane Simulation!" << std::endl;

		char choice = 'y';
		while (choice == 'y' || choice == 'Y') {
				runPlaneSimulation();

				std::cout << "\nWould you like to run another simulation? (y/n): ";
				std::cin >> choice;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer
				std::cout << std::endl;
		}

		std::cout << "Thank you for using the Inclined Plane Simulation. Goodbye!" << std::endl;
		return 0;
}

