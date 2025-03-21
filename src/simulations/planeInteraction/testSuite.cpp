#include <gtest/gtest.h>
#include "planeInteractionMech.hpp"

// Black Box Unit Tests
TEST(BlackBoxUnitTests, SlidingScenario) {
    // Test when the object should slide.
    // (mass=10, gravity=9.81, angle=30, friction=0.1, ext force=0; expected netForce ~40.5554, acceleration ~4.05554)
    InclinedPlaneMechanics plane(10.0, 9.81, 30.0, 5.0, 0.1, 0.0, "Cube", "Steel");
    double netForce = plane.calculateNetForce();
    ASSERT_DOUBLE_EQ(netForce, 40.5554) << "Net force is off";
    ASSERT_TRUE(plane.willSlide()) << "Should slide when net force is positive";
    double acceleration = plane.calculateAcceleration();
    ASSERT_DOUBLE_EQ(acceleration, 4.05554) << "Acceleration is off";
}

TEST(BlackBoxUnitTests, NoSlideScenario) {
    // Test when friction prevents sliding.
    // (mass=10, gravity=9.81, angle=10, friction=1.0, ext force=0; expected netForce ~ -79.46)
    InclinedPlaneMechanics plane(10.0, 9.81, 10.0, 5.0, 1.0, 0.0, "Sphere", "Wood");
    double netForce = plane.calculateNetForce();
    ASSERT_DOUBLE_EQ(netForce, -79.46) << "Net force should be negative";
    ASSERT_FALSE(plane.willSlide()) << "Should not slide when net force is negative";
}

TEST(BlackBoxUnitTests, ExternalForceScenario) {
    // Test with extra external force.
    // (mass=20, gravity=9.81, angle=20, friction=0.3, ext force=50; expected netForce ~61.732)
    InclinedPlaneMechanics plane(20.0, 9.81, 20.0, 5.0, 0.3, 50.0, "Cylinder", "Plastic");
    double netForce = plane.calculateNetForce();
    ASSERT_DOUBLE_EQ(netForce, 61.732) << "Net force with external force is off";
    ASSERT_TRUE(plane.willSlide()) << "Should slide with extra force";
    double acceleration = plane.calculateAcceleration();
    ASSERT_DOUBLE_EQ(acceleration, netForce / 20.0) << "Acceleration calculation mismatch";
}

// White Box Unit Tests
// Branch coverage for calculateNetForce() and willSlide().
// Function under test:
// double InclinedPlaneMechanics::calculateNetForce() const {
//   double angleRadians = degreesToRadians(m_angleDegrees);
//   double gravitationalForceComponent = m_mass * m_gravity * sin(angleRadians);
//   double normalForce = m_mass * m_gravity * cos(angleRadians);
//   double frictionForce = m_frictionCoefficient * normalForce;
//   double netForce = gravitationalForceComponent + m_externalForceApplied - frictionForce;
//   return netForce;
// }
TEST(WhiteBoxUnitTests, PositiveNetForce) {
    // Expect positive net force -> willSlide() true.
    InclinedPlaneMechanics plane(15.0, 9.81, 40.0, 10.0, 0.1, 0.0, "Cube", "Steel");
    double netForce = plane.calculateNetForce();
    ASSERT_GT(netForce, 0) << "Net force should be positive";
    ASSERT_TRUE(plane.willSlide());
}

TEST(WhiteBoxUnitTests, NegativeNetForce) {
    // Expect negative net force -> willSlide() false.
    InclinedPlaneMechanics plane(15.0, 9.81, 10.0, 10.0, 1.0, 0.0, "Cube", "Wood");
    double netForce = plane.calculateNetForce();
    ASSERT_LT(netForce, 0) << "Net force should be negative";
    ASSERT_FALSE(plane.willSlide());
}

TEST(WhiteBoxUnitTests, AccelerationDivTest) {
    // Check that acceleration equals netForce divided by mass.
    InclinedPlaneMechanics plane(20.0, 9.81, 25.0, 10.0, 0.2, 5.0, "Sphere", "Plastic");
    double netForce = plane.calculateNetForce();
    double acceleration = plane.calculateAcceleration();
    ASSERT_DOUBLE_EQ(acceleration, netForce / 20.0) << "Acceleration mismatch";
}

// Integration Tests
// Testing integration of calculateAcceleration(), calculateNetForce(), and willSlide().
// Units tested: physics calculations and sliding condition.
TEST(IntegrationTests, MotionIntegration) {
    // Simulate motion over 1 second with dt = 0.1.
    InclinedPlaneMechanics plane(10.0, 9.81, 35.0, 10.0, 0.1, 0.0, "Cylinder", "Steel");
    double acceleration = plane.calculateAcceleration();
    double position = 0.0, velocity = 0.0, dt = 0.1;
    for (int i = 0; i < 10; i++) {
        velocity += acceleration * dt;
        position += velocity * dt;
    }
    ASSERT_GT(position, 0) << "Object should have moved";
    ASSERT_GT(acceleration, 0) << "Acceleration should be positive";
    ASSERT_TRUE(plane.willSlide()) << "Sliding condition should be met";
}
