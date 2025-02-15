#include "planeInteractionMech.hpp"
#include <cmath>

InclinedPlaneMechanics::InclinedPlaneMechanics( 
		double mass,
		double gravity,
		double angleDegrees,
		double length,
		double frictionCoefficient,
		double externalForceApplied,
		const std::string &objectShape,
		const std::string &objectMaterial )
	: m_mass( mass )
	, m_gravity( gravity )
	, m_angleDegrees( angleDegrees )
	, m_length( length )
	, m_frictionCoefficient( frictionCoefficient )
	, m_externalForceApplied( externalForceApplied )
	, m_objectShape( objectShape )
	, m_objectMaterial( objectMaterial )
{
}

// Convert degrees to radians
double InclinedPlaneMechanics::degreesToRadians(double degrees) const {
		return degrees * (3.14159265358979323846 / 180.0);
}

// Calculate net force along the plane:
// Component of gravitational force parallel to the plane minus friction plus any external force.
double InclinedPlaneMechanics::calculateNetForce() const {
		double angleRadians = degreesToRadians(m_angleDegrees);
		double gravitationalForceComponent = m_mass * m_gravity * sin(angleRadians);
		double normalForce = m_mass * m_gravity * cos(angleRadians);
		double frictionForce = m_frictionCoefficient * normalForce;

		// Net force calculation (assuming friction opposes motion)
		double netForce = gravitationalForceComponent + m_externalForceApplied - frictionForce;
		return netForce;
}

// The object slides if the net force is positive.
bool InclinedPlaneMechanics::willSlide() const {
		return calculateNetForce() > 0;
}

// Calculate acceleration using Newton's second law (a = F/m)
double InclinedPlaneMechanics::calculateAcceleration() const {
		return calculateNetForce() / m_mass;
}

