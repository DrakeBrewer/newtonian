#include <iostream>
#include "lightBody.hpp"

bool equalVector(Vector3d a, Vector3d b, float tol = 0.001f){
    return (std::fabs(a.x - b.x) < tol) &&
	   (std::fabs(a.y - b.y) < tol) &&
	   (std::fabs(a.z - b.z) < tol);
}

int main(int argc, char **argv){
    Vector3d initPos = Vector3d(0,0,0); // origin
    Vector3d dir = Vector3d(1,0,0); // direction
    float wavelength = 720E-9; //570 nm, yellow light
    float speed = 2.0f;
    
    int passed = 0; 
    int failed = 0;

    LightBody redLight = LightBody(initPos, dir, wavelength, speed);
    
    double testDelta = 1; // 1 second update, expect postion to be doubled
    redLight.update(testDelta);
    Vector3d expectedPos = Vector3d(2,0,0);

    if(equalVector(expectedPos, redLight.position)){
	std::cout << "\nPosition Test Passed" << std::endl;
	passed += 1;
    } else {
	std::cout << "\nPosition Test Failed" << std::endl;
	failed += 1;
    }

    Vector3d testNormal = Vector3d(0,1,0);
    redLight.reflect(testNormal); //reflect off y-axis
    redLight.update(testDelta);
    redLight.update(testDelta);
    expectedPos = Vector3d(6,0,0);

    if(equalVector(expectedPos, redLight.position)){
	std::cout << "\nReflection Test Passed" << std::endl;
	passed += 1;
    } else {
	std::cout << "\nReflection Test Failed" << std::endl;
	failed += 1;
    }
    // Now going in <-1,0,0> direction

    float waterRIndex = 1.33f;
    Vector3d refractPlaneN = Vector3d(0,1,0);
    // Should be angled slightly by change in medium
    redLight.refract(refractPlaneN, waterRIndex);
    redLight.update(testDelta);
    redLight.update(testDelta);
    // Direction should remain unchanged after 2 updates
    Vector3d expectedDirection = Vector3d(0.75188f, -0.6593f, 0.0f);

    if(equalVector(expectedDirection, redLight.direction)){
	std::cout << "\nRefraction Direction Test Passed" << std::endl;
	passed += 1;
    } else {
	std::cout << "\nRefraction Direction Test Failed" << std::endl;
	failed += 1;
    }

    std::cout << "\nPassed: " << passed << ", Failed: " << failed << std::endl;
    return 0;
}

