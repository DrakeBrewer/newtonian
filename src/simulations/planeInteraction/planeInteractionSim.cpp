#include "planeInteractionSim.hpp"
#include "planeInteractionMech.hpp"
#include <iostream>
#include <limits>
#include <string>
#include <cctype>

static double getPositiveDouble(const std::string &prompt, bool allowZero = false);
static double getGravity(const std::string &prompt);
static std::string getValidString(const std::string &prompt);

void runPlaneSimulation() {
	std::cout << "----- Inclined Plane Simulation -----" << std::endl;

	double mass = getPositiveDouble("Enter mass of the object (kg): ");
	double gravity = getGravity("Enter gravitational acceleration (m/s^2): ");
	double angle = getPositiveDouble("Enter angle of the plane (degrees): ");
	double length = getPositiveDouble("Enter length of the plane (m): ");
	double frictionCoefficient = getPositiveDouble("Enter friction coefficient: ", true);
	double externalForceApplied = getPositiveDouble("Enter external force applied (N): ", true);

	std::string objectShape = getValidString("Enter object shape: ");
	std::string objectMaterial = getValidString("Enter object material: ");

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

	std::cout << "\n--- Simulation Parameters ---" << std::endl;
	std::cout << "Mass: " << mass << " kg" << std::endl;
	std::cout << "Gravity: " << gravity << " m/s^2" << std::endl;
	std::cout << "Angle: " << angle << " degrees" << std::endl;
	std::cout << "Length: " << length << " m" << std::endl;
	std::cout << "Friction Coefficient: " << frictionCoefficient << std::endl;
	std::cout << "External Force Applied: " << externalForceApplied << " N" << std::endl;
	std::cout << "Object Shape: " << objectShape << std::endl;
	std::cout << "Object Material: " << objectMaterial << std::endl;

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

static double getPositiveDouble(const std::string &prompt, bool allowZero) {
	double value = 0.0;
	while (true) {
		std::cout << prompt;
		std::cin >> value;
		if (std::cin.fail()) {
			std::cout << "Invalid input. Please enter a valid number.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (!allowZero && value <= 0) {
			std::cout << "Value must be a positive number.\n";
		} else if (allowZero && value < 0) {
			std::cout << "Value must be >= 0.\n";
		} else {
			break;
		}
	}
	return value;
}

static double getGravity(const std::string &prompt) {
	double g = 0.0;
	while (true) {
		std::cout << prompt;
		std::cin >> g;
		if (std::cin.fail()) {
			std::cout << "Invalid input. Please enter a valid number.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (g <= 0) {
			std::cout << "Gravity cannot be zero or negative. Defaulting to 9.81 m/s^2.\n";
			g = 9.81;
		}
		break;
	}
	return g;
}

static std::string getValidString(const std::string &prompt) {
	while (true) {
		std::cout << prompt;
		std::string input;
		std::getline(std::cin, input);
		bool allWhitespace = true;
		for (char c : input) {
			if (!std::isspace(static_cast<unsigned char>(c))) {
				allWhitespace = false;
				break;
			}
		}
		if (input.empty() || allWhitespace) {
			std::cout << "Input cannot be empty. Please try again.\n";
		} else {
			return input;
		}
	}
}

