#ifndef PLANE_INTERACTION_MECH_HPP
#define PLANE_INTERACTION_MECH_HPP

#include <string>

class InclinedPlaneMechanics {
public:
		// Constructor with parameters
		InclinedPlaneMechanics(double mass, double gravity, double angleDegrees, double length,
		                       double frictionCoefficient, double externalForceApplied,
		                       const std::string& objectShape, const std::string& objectMaterial);

		// Calculate the net force along the inclined plane
		double calculateNetForce() const;

		// Determine if the object will slide (net force > 0)
		bool willSlide() const;

		// Calculate the acceleration (if sliding): a = netForce / mass
		double calculateAcceleration() const;

private:
		double m_mass;
		double m_gravity;
		double m_angleDegrees;
		double m_length;
		double m_frictionCoefficient;
		double m_externalForceApplied;
		std::string m_objectShape;
		std::string m_objectMaterial;

		// Helper function to convert degrees to radians
		double degreesToRadians(double degrees) const;
};

#endif // PLANE_INTERACTION_MECH_HPP

