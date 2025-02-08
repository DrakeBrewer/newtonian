#include "planeInteraction.h"
#include <iostream>
#include "object.hpp"  

void PlaneInteraction() {
    // Create an instance of Object 
    Object testObject;
    
    std::cout << "This is the Inclined Plane Interaction Test:" << std::endl;
    std::cout << "Mass: " << testObject.inclinedPlaneInteraction.mass << " kg" << std::endl;
    std::cout << "Gravity: " << testObject.inclinedPlaneInteraction.gravity << " m/s^2" << std::endl;
    std::cout << "Angle: " << testObject.inclinedPlaneInteraction.angle << " degrees" << std::endl;
    std::cout << "Length: " << testObject.inclinedPlaneInteraction.length << " m" << std::endl;
    std::cout << "Friction Coefficient: " << testObject.inclinedPlaneInteraction.frictionCoefficient << std::endl;
    std::cout << "External Force Applied: " << testObject.inclinedPlaneInteraction.externalForceApplied << " N" << std::endl;
    std::cout << "Object Shape: " << testObject.inclinedPlaneInteraction.objectShape << std::endl;
    std::cout << "Object Material: " << testObject.inclinedPlaneInteraction.objectMaterial << std::endl;
}
