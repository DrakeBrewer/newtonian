#include "planeInteractionSim.hpp"
#include "planeInteractionMech.hpp"
#include <iostream>
#include <limits>

void runPlaneSimulation() {
		std::cout << "----- Inclined Plane Simulation -----" << std::endl;

		double mass, gravity, angle, length, frictionCoefficient, externalForceApplied;
		std::string objectShape, objectMaterial;

		// Get user inputs
		std::cout << "Enter mass of the object (kg): ";
		std::cin >> mass;

		std::cout << "Enter gravitational acceleration (m/s^2): ";
		std::cin >> gravity;

		std::cout << "Enter angle of the plane (degrees): ";
		std::cin >> angle;

		std::cout << "Enter length of the plane (m): ";
		std::cin >> length;

		std::cout << "Enter friction coefficient: ";
		std::cin >> frictionCoefficient;

		std::cout << "Enter external force applied (N): ";
		std::cin >> externalForceApplied;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear newline from buffer

		std::cout << "Enter object shape: ";
		std::getline(std::cin, objectShape);

		std::cout << "Enter object material: ";
		std::getline(std::cin, objectMaterial);

		// Create an instance of InclinedPlaneMechanics with the provided parameters
		InclinedPlaneMechanics plane(mass, gravity, angle, length,
							         frictionCoefficient, externalForceApplied,
							         objectShape, objectMaterial);

		// Display the input values
		std::cout << "\n--- Simulation Parameters ---" << std::endl;
		std::cout << "Mass: " << mass << " kg" << std::endl;
		std::cout << "Gravity: " << gravity << " m/s^2" << std::endl;
		std::cout << "Angle: " << angle << " degrees" << std::endl;
		std::cout << "Length: " << length << " m" << std::endl;
		std::cout << "Friction Coefficient: " << frictionCoefficient << std::endl;
		std::cout << "External Force Applied: " << externalForceApplied << " N" << std::endl;
		std::cout << "Object Shape: " << objectShape << std::endl;
		std::cout << "Object Material: " << objectMaterial << std::endl;

		// Run calculations
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

