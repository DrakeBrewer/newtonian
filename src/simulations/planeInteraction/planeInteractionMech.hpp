#ifndef PLANE_INTERACTION_MECH_HPP
#define PLANE_INTERACTION_MECH_HPP

#include <string>

// The InclinedPlaneMechanics class encapsulates all the physics parameters
class InclinedPlaneMechanics {
public:
	// Constructor: Initializes the simulation parameters for the object.
	InclinedPlaneMechanics(double mass, double gravity, double angleDegrees, double length,
	                       double frictionCoefficient, double externalForceApplied,
	                       const std::string &objectShape, const std::string &objectMaterial);

	// Calculates the net force acting along the inclined plane.
	// Returns the computed net force in Newtons.
	double calculateNetForce() const;

	// Determines if the object will slide down the plane.
	// Returns true if the net force is positive (indicating sliding), false otherwise.
	bool willSlide() const;

	// Calculates the acceleration of the object using Newton's second law (a = F/m).
	// Returns the acceleration in m/s^2.
	double calculateAcceleration() const;

private:
	// Simulation parameters stored as private member variables.
	double m_mass;                  // Mass of the object (kg)
	double m_gravity;               // Gravitational acceleration (m/s^2)
	double m_angleDegrees;          // Angle of the plane in degrees
	double m_length;                // Length of the inclined plane (m)
	double m_frictionCoefficient;   // Friction coefficient (unitless)
	double m_externalForceApplied;  // External force applied (N)
	std::string m_objectShape;      // Shape of the object (e.g., Cube, Sphere, Cylinder)
	std::string m_objectMaterial;   // Material of the object (e.g., Steel, Wood, Plastic)

	// Converts an angle in degrees to radians.
	// This helper function is used internally for trigonometric calculations.
	double degreesToRadians(double degrees) const;
};

#endif // PLANE_INTERACTION_MECH_HPP

