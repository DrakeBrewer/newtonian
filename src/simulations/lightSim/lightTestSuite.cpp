#include "LightRay.hpp"
#include "LightScene.hpp"
#include "MaterialVolume.hpp"
#include <exception>
#include <string>
#include "../collisionSim/rigidBody.hpp"
#include <gtest/gtest.h>

// ------------- Black-box unit tests --------------

// Tests correct initialization of LighRay object.
TEST(LightRayTests, Initialization) {
    float frequency = 4.5e14; // Hz
    float vacSpeed = 2.9979245e8;
    Vector3d startingPos = Vector3d(0,0,0);
    Vector3d direction = Vector3d(0,0,1);

    LightRay ray = LightRay(frequency, vacSpeed, startingPos, direction);

    EXPECT_FLOAT_EQ(ray.frequency, frequency);
    EXPECT_FLOAT_EQ(ray.speed, vacSpeed);
    EXPECT_TRUE(ray.position.isEqual(startingPos));
    EXPECT_TRUE(ray.direction.isEqual(direction));
}

// Tests functionality of LightRay reset method
TEST(LightTests, resetFuncCheck) {
    float frequency = 6.6e14;
    float arbitrarySpeed = 16.9875;
    Vector3d strangePos = Vector3d(3,1,4);
    Vector3d strangeDir = Vector3d(4,1,3);
    LightRay ray(frequency, arbitrarySpeed, strangePos, strangeDir);

    // new state
    Vector3d newDir = Vector3d(0.5, 0, -1);
    ray.reset(7.0e14, arbitrarySpeed / 2, strangeDir, strangePos);

    EXPECT_FLOAT_EQ(ray.frequency, 7.0e14);
    EXPECT_FLOAT_EQ(ray.speed, arbitrarySpeed / 2);
    EXPECT_TRUE(ray.position.isEqual(strangeDir)); // Notice flipped values in reset
    EXPECT_TRUE(ray.direction.isEqual(strangePos));
}

// ------------- White-box unit tests --------------

// Tests refract() full branch coverage.
///void LightRay::refract(float n2, Vector3d& normal) {
//
 //   if(n2 < 1) throw std::invalid_argument("Invalid index: n2 must be >= 1");
//
  //  // n = c/v
 //   float n1 = vacuumSpeed / this->speed;
//
 //   float ratio = n1/n2;
//
  //  // angle between incoming light and surface normal
 //   float cosTheta1 = normal.dotProduct(direction);
//
  //  // sin^2(theta) = (ratio)^2 * (1 - cos^2(theta))
 //   float sinTheta2 = ratio * ratio * (1 - cosTheta1 * cosTheta1);
//
  //  // Check for total internal reflection
 //   if(sinTheta2 > 1.0) {
//	reflect(normal);
//	return;
 //   }
//
  //  // if none, compute speed in new medium
 //   this->speed = vacuumSpeed / n2;
//
//
 //   float cosTheta2 = std::sqrt(1 - sinTheta2);
//
    //direction.x = (ratio * direction.x) + (ratio * cosTheta1 - cosTheta2) * normal.x;
   // direction.y = (ratio * direction.y) + (ratio * cosTheta1 - cosTheta2) * normal.y;
 ////   direction.z = (ratio * direction.z) + (ratio * cosTheta1 - cosTheta2) * normal.z;
//

 //   if(DEBUG) std::cout << "New direction: <" << this->direction.x << ", " << this->direction.y << ", " << this->direction.z << ">\n";
//}

//
TEST(LightRayTests, Refraction) {
    float frequency = 5.0e14; // Hz
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
    float thickness = 100; // thickiness of material relative to center
    bool reflective = false; // isReflective
    bool refractive = true; // isRefractive
    Material glass = Material(matName, mass, volume, refractiveIndex, absorptionCoeff, center, thickness, reflective, refractive);

    // Case 1: Incidence normal to surface

    ray.refract(glass.refractiveIndex, glass.unitNormal);

    // calculate expected z
    float n1 = 1.0;
    float n2 = glass.refractiveIndex;
    float theta1 = std::asin(std::abs(rayDirection.x));
    float theta2 = std::asin((n1/n2) * std::sin(theta1));
    float expectedZ = -std::cos(theta2);

    EXPECT_FLOAT_EQ(ray.direction.z, expectedZ);  // direction remains negative
    EXPECT_LT(ray.speed, vacuumSpeed); // speed decrease
    EXPECT_EQ(ray.frequency, frequency); // Frequency unchanged
    
    // Case 2: Angled incidence
    rayDirection = Vector3d(0.8, 0,-0.6); // high incidence angle
    ray.reset(frequency, vacuumSpeed, startPos, rayDirection);
    ray.refract(glass.refractiveIndex, glass.unitNormal);

    // calculate expected values
    n1 = 1.0;
    n2 = glass.refractiveIndex;
    theta1 = std::asin(std::abs(rayDirection.x));
    theta2 = std::asin((n1/n2) * std::sin(theta1));

    float expectedX = std::sin(theta2);
    expectedZ = -std::cos(theta2);

    EXPECT_FLOAT_EQ(ray.direction.x, expectedX); // should bend toward normal
    EXPECT_LT(ray.direction.z, expectedZ);
    EXPECT_LT(ray.speed, vacuumSpeed); // speed decrease
    
    // Case 3: Total Internal Reflection
    rayDirection = Vector3d(0.8, 0, -0.6); // high incedence angle
    Material water("Water", 1.0, 1.0, 1.33, 0, Vector3d(0,0,0), 100, false, true);
    Material air("Air", 1.0, 1.0, 1.0003, 0, Vector3d(0,0,0), 100, false, true);

    // compute critical angle
    n1 = water.refractiveIndex;
    n2 = air.refractiveIndex;
    float thetaCritical = std::asin(n2/n1);

    // compute incident angle
    float thetaIncident = std::asin(std::abs(rayDirection.x));

    ray.reset(frequency, vacuumSpeed, startPos, rayDirection);
    ray.refract(water.refractiveIndex, water.unitNormal); // enter water
    ray.refract(air.refractiveIndex, air.unitNormal); // attempt exit into air
    // check if TIR occured
    if(thetaIncident > thetaCritical) {
	// expect reflection
	EXPECT_FLOAT_EQ(ray.direction.x, -rayDirection.x);
	EXPECT_FLOAT_EQ(ray.direction.z, rayDirection.z);
    } else {
	ADD_FAILURE() << "Expected total internal reflection";
    }

    // Case 4: No refraction (n1 == n2)
    ray.reset(frequency, vacuumSpeed, startPos, rayDirection);
    Vector3d unitN = Vector3d(0,0,1);
    ray.refract(1.5, unitN);
    EXPECT_EQ(ray.direction.x, rayDirection.x);
    EXPECT_EQ(ray.direction.z, rayDirection.z);
    EXPECT_EQ(ray.speed, vacuumSpeed / 1.5);

    // Case 5: Edge Case n2 = 0
    ray.reset(frequency, vacuumSpeed, startPos, rayDirection);
    EXPECT_THROW(ray.refract(0, unitN), std::exception);
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
    reflectScene.simulate();

    EXPECT_FLOAT_EQ(mirroredRay.direction.z, -1);
    EXPECT_LE(reflectScene.timeElapsed, reflectScene.maxTime);
    EXPECT_NE(mirroredRay.position.z, startPos.z);
    EXPECT_FLOAT_EQ(mirroredRay.frequency, frequency);
    EXPECT_FLOAT_EQ(mirroredRay.speed, vacuumSpeed);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
