#include "planeInteractionSim.hpp"
#include "planeInteractionMech.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

// Helper function to get a positive double value.
// If allowZero is false, only values greater than 0 are accepted.
// If allowZero is true, 0 is accepted but negatives are not.
double getPositiveDouble(const std::string &prompt, bool allowZero = false) {
	std::cout << prompt;
	double value = 0.0;
	while (true) {
		std::cin >> value;
		if (std::cin.fail()) {
			std::cout << "Invalid input. Please enter a valid number.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (!allowZero && value <= 0) {
				std::cout << "Value must be a positive number.\n";
			} else if (allowZero && value < 0) {
				std::cout << "Value must be >= 0.\n";
			} else {
				break;
			}
		}
		std::cout << prompt;
	}
	return value;
}

// Helper function to get a valid gravity value.
// If the user enters a value <= 0, gravity defaults to 9.81.
double getGravity(const std::string &prompt) {
	double g = 0.0;
	while (true) {
		std::cout << prompt;
		std::cin >> g;
		if (std::cin.fail()) {
			std::cout << "Invalid input. Please enter a valid number.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (g <= 0) {
				std::cout << "Gravity cannot be zero or negative. Defaulting to 9.81 m/s^2.\n";
				g = 9.81;
			}
			break;
		}
	}
	return g;
}

// Helper function to prompt the user to select one of the allowed options.
// It continues to prompt until the user enters a valid choice.
std::string getValidChoice(const std::string &prompt, const std::vector<std::string>& allowedOptions) {
	while (true) {
		std::cout << prompt;
		std::string input;
		std::getline(std::cin, input);
		// Check if the input is one of the allowed options.
		if (std::find(allowedOptions.begin(), allowedOptions.end(), input) != allowedOptions.end()) {
			return input;
		} else {
			std::cout << "Invalid choice. Please choose one of the following options: ";
			for (const auto &option : allowedOptions) {
				std::cout << option << " ";
			}
			std::cout << "\n";
		}
	}
}

// Main simulation function that gathers input, creates the simulation object, and displays results.
void runPlaneSimulation() {
	std::cout << "----- Inclined Plane Simulation -----" << std::endl;

	// Get validated numeric inputs
	double mass = getPositiveDouble("Enter mass of the object (kg): ");
	double gravity = getGravity("Enter gravitational acceleration (m/s^2): ");
	double angle = getPositiveDouble("Enter angle of the plane (degrees): ");
	double length = getPositiveDouble("Enter length of the plane (m): ");
	double frictionCoefficient = getPositiveDouble("Enter friction coefficient: ", true);
	double externalForceApplied = getPositiveDouble("Enter external force applied (N): ", true);

	// Define allowed options for object shape and material
	std::vector<std::string> allowedShapes = {"Cube", "Sphere", "Cylinder"};
	std::vector<std::string> allowedMaterials = {"Steel", "Wood", "Plastic"};

	// Get valid choices for object shape and material
	std::string objectShape = getValidChoice("Enter object shape (Cube, Sphere, Cylinder): ", allowedShapes);
	std::string objectMaterial = getValidChoice("Enter object material (Steel, Wood, Plastic): ", allowedMaterials);

	// Create simulation object using the provided parameters
	InclinedPlaneMechanics plane(
		mass,
		gravity,
		angle,
		length,
		frictionCoefficient,
		externalForceApplied,
		objectShape,
		objectMaterial
	);

	// Display the input parameters
	std::cout << "\n--- Simulation Parameters ---" << std::endl;
	std::cout << "Mass: " << mass << " kg" << std::endl;
	std::cout << "Gravity: " << gravity << " m/s^2" << std::endl;
	std::cout << "Angle: " << angle << " degrees" << std::endl;
	std::cout << "Length: " << length << " m" << std::endl;
	std::cout << "Friction Coefficient: " << frictionCoefficient << std::endl;
	std::cout << "External Force Applied: " << externalForceApplied << " N" << std::endl;
	std::cout << "Object Shape: " << objectShape << std::endl;
	std::cout << "Object Material: " << objectMaterial << std::endl;

	// Run calculations using the simulation object
	double netForce = plane.calculateNetForce();
	std::cout << "\nCalculated Net Force along the plane: " << netForce << " N" << std::endl;

	if (plane.willSlide()) {
		double acceleration = plane.calculateAcceleration();
		std::cout << "Result: The object will slide down the plane." << std::endl;
		std::cout << "Acceleration of the object: " << acceleration << " m/s^2" << std::endl;
	} else {
		std::cout << "Result: The object remains stationary on the plane." << std::endl;
	}

	std::cout << "--------------------------------------" << std::endl;
}

