#include "planeInteractionMech.hpp"
#include <cmath> 

// Constructor: Initializes all simulation parameters using an initializer list.
InclinedPlaneMechanics::InclinedPlaneMechanics( 
	double mass,
	double gravity,
	double angleDegrees,
	double length,
	double frictionCoefficient,
	double externalForceApplied,
	const std::string &objectShape,
	const std::string &objectMaterial )
	: m_mass(mass)
	, m_gravity(gravity)
	, m_angleDegrees(angleDegrees)
	, m_length(length)
	, m_frictionCoefficient(frictionCoefficient)
	, m_externalForceApplied(externalForceApplied)
	, m_objectShape(objectShape)
	, m_objectMaterial(objectMaterial)
{
	// No additional setup is needed in the constructor body.
}

// Helper function that converts degrees to radians.
// Trigonometric functions in <cmath> use radians, so this conversion is necessary.
double InclinedPlaneMechanics::degreesToRadians(double degrees) const {
	return degrees * (3.14159265358979323846 / 180.0);
}

// Calculates the net force acting along the inclined plane.
// It factors in gravitational force, friction, and any external force.
double InclinedPlaneMechanics::calculateNetForce() const {
	// Convert angle from degrees to radians for the trigonometric functions.
	double angleRadians = degreesToRadians(m_angleDegrees);
	// Calculate the component of gravitational force along the plane.
	double gravitationalForceComponent = m_mass * m_gravity * sin(angleRadians);
	// Calculate the normal force perpendicular to the plane.
	double normalForce = m_mass * m_gravity * cos(angleRadians);
	// Calculate friction force, which opposes motion.
	double frictionForce = m_frictionCoefficient * normalForce;

	// Net force is the gravitational component plus any external force minus friction.
	double netForce = gravitationalForceComponent + m_externalForceApplied - frictionForce;
	return netForce;
}

// Determines if the object will slide down the plane based on net force.
// Returns true if net force is greater than zero.
bool InclinedPlaneMechanics::willSlide() const {
	return calculateNetForce() > 0;
}

// Calculates the acceleration of the object using Newton's second law: a = F / m.
double InclinedPlaneMechanics::calculateAcceleration() const {
	return calculateNetForce() / m_mass;
}
