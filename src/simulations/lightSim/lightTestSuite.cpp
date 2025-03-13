#include "LightBase.hpp"
#include "LightRay.hpp"
#include "LightScene.hpp"
#include "MaterialVolume.hpp"
#include <string>
#include "../collisionSim/rigidBody.hpp"
#include <gtest/gtest.h>

// ------------- Black-box unit tests --------------

// Tests correct initialization of LighRay object.
TEST(LightRayTests, Initialization) {
    float frequency = 4.5e14; // Hz
    float vacSpeed = 2.9979245e8;
    Vector3d startingPos(0,0,0);
    Vector3d direction(0,0,1);

    LightRay ray = LightRay(frequency, vacSpeed, startingPos, direction);

    EXPECT_FLOAT_EQ(ray.frequency, frequency);
    EXPECT_FLOAT_EQ(ray.speed, vacSpeed);
    EXPECT_TRUE(ray.position.isEqual(startingPos));
    EXPECT_TRUE(ray.direction.isEqual(direction));
}

// ------------- White-box unit tests --------------

// Tests: LightRay's refraction() method
// Ensure correct behavior for a lightRay interacting with a new medium at a perpendicular angle to the surface (90 degrees).
TEST(LightRayTests, Refraction) {
    float frequency = 4.5e14; // Hz
    float vacuumSpeed = 2.9979245e8; // speed of light
    Vector3d startPos = Vector3d(0,0,0); // starting position
    Vector3d rayDirection = Vector3d(0,0,-1); // moving down z-axis

    LightRay ray = LightRay(frequency, vacuumSpeed, startPos, rayDirection);

    std::string matName = "Glass";
    float mass = 0.8; // kg
    float volume = 1.2; // m^3
    float refractiveIndex = 1.5;
    float absorptionCoeff = 0;
    Vector3d center = Vector3d(0,0,0); // center of material volume
    float thickness = 100;
    bool reflective = false;
    bool refractive = true;

    Material glass = Material(matName, mass, volume, refractiveIndex, absorptionCoeff, center, thickness, reflective, refractive);

    Vector3d normal = Vector3d(0,0,1);

    // Light is inside the glass material volume, it will refract once. Since it is 90 degrees to the plane, it should only change in speed, not direction
    ray.refract(glass.refractiveIndex, glass.unitNormal);

    EXPECT_TRUE(ray.direction.isEqual(rayDirection)); // direction should reamin unchanged
    EXPECT_LT(ray.speed, vacuumSpeed); // speed decrease when travelling through glass
    EXPECT_LT(ray.position.x, 0); // no total internal reflection, should continue moving down relative to start.
    EXPECT_EQ(ray.frequency, frequency); // Frequency should remain unchanged
}

// ------------- Integration tests --------------

// Tests: LightScene, LightRay, Material
// Ensures proper reflection during a simulation with interaction between ray and mirror
TEST(LightSceneTests, Reflection) {

    LightScene reflectScene = LightScene();

    float frequency = 4.5e14; // Hz
    float vacuumSpeed = 2.9979245e8; // m/s
    Vector3d startPos(0,0,30);
    Vector3d direction(0,0,1);

    LightRay mirroredRay = LightRay(frequency, vacuumSpeed, startPos, direction);

    std::string matName = "Mirror";
    float mass = 0.5; // kg
    float volume = 2.4; // m^3
    float refractiveIndex = 1.69;
    float absorptionCoeff = 0;
    Vector3d center = Vector3d(0,0,100); // center of material volume
    float thickness = 100;
    bool reflective = true;
    bool refractive = false;

    Material mirror = Material("Mirror", 0.5, 1.0, 0.5, 0.95, center, 100.0, true, false);

    reflectScene.addLight(mirroredRay);
    reflectScene.addMaterial(mirror);
    reflectScene.simulate();:

    EXPECT_FLOAT_EQ(mirroredRay.direction.z, -1);
    EXPECT_LE(reflectScene.timeElapsed, reflectScene.maxTime);
    EXPECT_NE(mirroedRay.position.z, startPos.z);
    EXPECT_FLOAT_EQ(mirroedRay.frequency, frequency);
    EXPECT_FLOAT_EQ(mirroedRay.speed, vacuumSpeed);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
