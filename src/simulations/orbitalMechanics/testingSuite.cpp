#include <iostream>
#include <gtest/gtest.h>
#include <sstream>
#include "orbitalMechanics.hpp"
#include "orbitSimulation.hpp"
#include <math.h>

// black box unit test
TEST(OrbitalMechanics, setPlanetType){
    OrbitalMechanics testPlanet;

    // Test all 8 valid planet types, so we want to make sure that the
    // planet name is correct and also have the relevant planet mass set
    // These are all the same except for the name and mass
    ASSERT_TRUE(testPlanet.setPlanetType("Mercury"));
    EXPECT_EQ(testPlanet.planetName, "Mercury");
    EXPECT_DOUBLE_EQ(testPlanet.planetMass, 3.301e23);

    ASSERT_TRUE(testPlanet.setPlanetType("Venus"));
    EXPECT_EQ(testPlanet.planetName, "Venus");
    EXPECT_DOUBLE_EQ(testPlanet.planetMass, 4.86732e24);

    ASSERT_TRUE(testPlanet.setPlanetType("Earth"));
    EXPECT_EQ(testPlanet.planetName, "Earth");
    EXPECT_DOUBLE_EQ(testPlanet.planetMass, 5.9722e24);

    ASSERT_TRUE(testPlanet.setPlanetType("Mars"));
    EXPECT_EQ(testPlanet.planetName, "Mars");
    EXPECT_DOUBLE_EQ(testPlanet.planetMass, 6.4171e23);

    ASSERT_TRUE(testPlanet.setPlanetType("Jupiter"));
    EXPECT_EQ(testPlanet.planetName, "Jupiter");
    EXPECT_DOUBLE_EQ(testPlanet.planetMass, 1.899e27);

    ASSERT_TRUE(testPlanet.setPlanetType("Saturn"));
    EXPECT_EQ(testPlanet.planetName, "Saturn");
    EXPECT_DOUBLE_EQ(testPlanet.planetMass, 5.685e26);

    ASSERT_TRUE(testPlanet.setPlanetType("Uranus"));
    EXPECT_EQ(testPlanet.planetName, "Uranus");
    EXPECT_DOUBLE_EQ(testPlanet.planetMass, 8.682e25);

    ASSERT_TRUE(testPlanet.setPlanetType("Neptune"));
    EXPECT_EQ(testPlanet.planetName, "Neptune");
    EXPECT_DOUBLE_EQ(testPlanet.planetMass, 1.024e26);

    // Test the possible invalid planet types, so we want to make sure when an invalid
    // planet is entered, the user is reprompted, default name and mass is kept for Earth
    ASSERT_FALSE(testPlanet.setPlanetType("Pluto"));
    EXPECT_EQ(testPlanet.planetName, "Earth");
    EXPECT_DOUBLE_EQ(testPlanet.planetMass, 5.9722e24);

    ASSERT_FALSE(testPlanet.setPlanetType("12345"));
    EXPECT_EQ(testPlanet.planetName, "Earth");
    EXPECT_DOUBLE_EQ(testPlanet.planetMass, 5.9722e24);
}

// white box unit test
TEST(OrbitSimulation, handleMoonMassInput){
    OrbitSimulation testMoonMass;

    // I will stick to using Earth as the planet here since the moon mass is relative to planet mass
    // So we set min and max moon mass like we do in orbitSimulation.cpp
    // I could of just incluted the min and max moon values in the individual parts of the test
    // but it is more streamline this way since we can set the planet to any and right away
    // get the min and max moon mass relative to the planet mass
    testMoonMass.orbitSim.setPlanetType("Earth");
    double minMoonMass = (testMoonMass.orbitSim.planetMass * 0.001);
    double maxMoonMass = (testMoonMass.orbitSim.planetMass * 0.1);

    // Test a valid moon mass input relative to the planet mass
    {
        std::istringstream validMass("7.348e22\n");
        std::streambuf* originalInputRead = std::cin.rdbuf();
        std::cin.rdbuf(validMass.rdbuf());
        EXPECT_TRUE(testMoonMass.handleMoonMassInput());
        EXPECT_DOUBLE_EQ(testMoonMass.orbitSim.moonMass, 7.348e22);
        std::cin.rdbuf(originalInputRead);
    }

    // Test a moon mass that is below the min the moon mass can be relative to the planet mass
    // Also have to make sure the moon mass stays the same after this invlaid min input
    {
        std::istringstream belowMinMass("5.9722e10\n-1\n");
        std::streambuf* originalInputRead = std::cin.rdbuf();
        std::cin.rdbuf(belowMinMass.rdbuf());
        EXPECT_FALSE(testMoonMass.handleMoonMassInput());
        EXPECT_DOUBLE_EQ(testMoonMass.orbitSim.moonMass, 7.348e22);
        std::cin.rdbuf(originalInputRead);
    }

    // Test a moon mass that is above the max the moon mass can be relative to the planet mass
    // Also have to make sure the moon mass stays the same after this invalid max input
    {
        std::istringstream aboveMaxMass("5.9722e34\n-1\n");
        std::streambuf* originalInputRead = std::cin.rdbuf();
        std::cin.rdbuf(aboveMaxMass.rdbuf());
        EXPECT_FALSE(testMoonMass.handleMoonMassInput());
        EXPECT_DOUBLE_EQ(testMoonMass.orbitSim.moonMass, 7.348e22);
        std::cin.rdbuf(originalInputRead);
    }

    // Test a moon mass that is exactly the minimum mass it can be relative to the planet mass
    {
        std::string minMoonMassString = std::to_string(minMoonMass) + "\n";
        std::istringstream minMass(minMoonMassString);
        std::streambuf* originalInputRead = std::cin.rdbuf();
        std::cin.rdbuf(minMass.rdbuf());
        EXPECT_TRUE(testMoonMass.handleMoonMassInput());
        EXPECT_NEAR(testMoonMass.orbitSim.moonMass, minMoonMass, 1e10);
        std::cin.rdbuf(originalInputRead);
    }

    // Test a moon mass that is exactly the maximum mass it can be relative to the planet mass
    {
        std::string maxMoonMassString = std::to_string(maxMoonMass) + "\n";
        std::istringstream maxMass(maxMoonMassString);
        std::streambuf* originalInputRead = std::cin.rdbuf();
        std::cin.rdbuf(maxMass.rdbuf());
        EXPECT_TRUE(testMoonMass.handleMoonMassInput());
        EXPECT_NEAR(testMoonMass.orbitSim.moonMass, maxMoonMass, 1e10);
        std::cin.rdbuf(originalInputRead);
    }

    // Test the go back feature "-1" which just takes the user back to the planet selection
    {
        std::istringstream goBack("-1\n");
        std::streambuf* originalInputRead = std::cin.rdbuf();
        std::cin.rdbuf(goBack.rdbuf());
        EXPECT_FALSE(testMoonMass.handleMoonMassInput());
        std::cin.rdbuf(originalInputRead);
    }
}


// integration unit test, the units are updatePlanetMass() and updateMoonVelocty()
TEST(OrbitalMechanics, updatePlanetMassANDmoonVelocity){
    // Since updating the planet mass changes the moon velocity, we can make this
    // test check the moon velocity too see if it was properly updated after
    // updating the planet mass. If the planet mass increases so should moon velocity
    // and if it decreases so should the moon velocity 
    OrbitalMechanics testUpdates;

    double originalMoonVelocity = testUpdates.moonVelocity;
    double originalPlanetMass = testUpdates.planetMass;
    double originalPlanetMoonDistance = testUpdates.planetMoonDistance;
    double updatedPlanetMass = 8.682e25; // This is Uranus's planet mass by the way

    testUpdates.updatePlanetMass(updatedPlanetMass);
    EXPECT_NE(testUpdates.moonVelocity, originalMoonVelocity);

    double expectedUpdatedMoonVelocity = sqrt(testUpdates.gravitationalConstant * updatedPlanetMass / originalPlanetMoonDistance);
    EXPECT_NEAR(testUpdates.moonVelocity, expectedUpdatedMoonVelocity, 1e-10);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}