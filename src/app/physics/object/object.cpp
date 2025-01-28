#include <iostream>
#include <string>

struct InclinedPlaneInteraction{
    double mass; // mass of the object [kg]
    double gravity; // gravitational acceleration [m/s^2]
    double angle; // angle of the incline [degrees]
    double length; // length of the incline surface [m]
    double frictionCoefficient; // how much friction [no units]
    double externalForceApplied; // external force applied to the object [N]
    std::string objectShape; // shape of the object
    std::string objectMaterial; // what the object is made out of
};

struct TimeControlSystem{
    double timeScale; // how fast the time is moving (...0.75x, 1x, 1.25x, ...)
    double currentTime; // what the current time scale is
    bool isPaused; // this is "freezing" the time or not, pausing or unpausing the simulation
    int frameRate; // this is for frame-by-frame control
};

struct OrbitalMechanics{
    double centralMassOfBody; // this is big M, the mass of what is being orbited around [kg]
    double orbitingObjectMass; // this is small m, the mass of the object in orbit [kg]
    double initialVelocity; // the initial velocity of orbiting object [m/s]
    double trajectoryOfOrbit; // orbital trajectory [m]
    double distanceFromCenter; // how far away center of object is from center of central mass [m]
};

struct LightInteraction{
    double lightIntensity; // how bright/ dim the light is [W/m^2]
    double wavelength; // the wavelength of the light [nm]
    double refractiveIndex; // the refractive index of the medium [no units]
    double reflectivityOfObject; // how reflective the object is [no units]
};

struct FluidMechanics{
    double fluidDensity; // density of the fluid [kg/m^3]
    double fluidViscosity; // viscosity of the fluid [(Pa)(s)]
    double objectVolume; // volume of the object [m^3]
    double fluidVelocity; // how fast the fluid is moving [m/s]
};

struct PlanetaryPhysics{
    double mass; // mass of the object [kg]
    double gravity; // gravitational acceleration [m/s^2]
    std::string planetName; // the name of the planet that is selected
};

struct CollisionSystem{
    double mass; // mass of the object [kg]
    double gravity; // gravitational acceleration [m/s^2]
    double elasticity; // coefficient of restitution [no units]
    double impulse; // the impulse during the collision [(N)(s)]
    double objectVelocity; // speed of the object [m/s]
    double objectPosition; // where the object is away from a point [m]
    bool isCollision; // is there a collision or not
};

// This is the main object
typedef struct Object{
    InclinedPlaneInteraction inclinePlane;
    TimeControlSystem timeControl;
    OrbitalMechanics orbitalMechanics;
    LightInteraction lightInteraction;
    FluidMechanics fluidMechanics;
    PlanetaryPhysics planetaryPhysics;
    CollisionSystem collisionSystem;

    // Constructor for the variables
    Object(){
        // Inclined Place Interaction
        inclinePlane.mass = 10.0;
        inclinePlane.gravity = 9.81;
        inclinePlane.angle = 0.0;
        inclinePlane.length = 5.0;
        inclinePlane.frictionCoefficient = 0.5;
        inclinePlane.externalForceApplied = 0.0;
        inclinePlane.objectShape = "box";
        inclinePlane.objectMaterial = "wood";

        // Time Control System
        timeControl.timeScale = 1.0;
        timeControl.currentTime = 0.0;
        timeControl.isPaused = false;
        timeControl.frameRate = 60;

        // Orbital Mechanics
        orbitalMechanics.centralMassOfBody = 5.97e24;
        orbitalMechanics.orbitingObjectMass = 1.0;
        orbitalMechanics.initialVelocity = 0.0;
        orbitalMechanics.trajectoryOfOrbit = 0.0;
        orbitalMechanics.distanceFromCenter = 10.0;

        // Light Interaction
        lightInteraction.lightIntensity = 100.0;
        lightInteraction.wavelength = 500.0;
        lightInteraction.refractiveIndex = 1.0;
        lightInteraction.reflectivityOfObject = 0.7;

        // Fluid Mechanics
        fluidMechanics.fluidDensity = 100.0;
        fluidMechanics.fluidViscosity = 1.0;
        fluidMechanics.objectVolume = 1.0;
        fluidMechanics.fluidVelocity = 0.0;

        // Planetary Physics
        planetaryPhysics.mass = 10.0;
        planetaryPhysics.gravity = 9.81;
        planetaryPhysics.planetName = "Earth";

        // Collision System
        collisionSystem.mass = 10.0;
        collisionSystem.gravity = 9.81;
        collisionSystem.elasticity = 0.7;
        collisionSystem.impulse = 0.0;
        collisionSystem.objectVelocity = 0.0;
        collisionSystem.objectPosition = 0.0;
        collisionSystem.isCollision = false;
    }
} Object;


int main(){
    // TESTING: this object is made and some parameters printed just for testing
    Object testObject;
    std::cout << "Mass: " << testObject.inclinePlane.mass << " [kg]" << std::endl;
    std::cout << "Gravity: " << testObject.inclinePlane.gravity << " [m/s^2]" << std::endl;
    std::cout << "Incline Angle: " << testObject.inclinePlane.angle << " degrees" << std::endl;
    std::cout << "Surface Length: " << testObject.inclinePlane.length << " [m]" << std::endl;
    std::cout << "Friction: " << testObject.inclinePlane.frictionCoefficient << std::endl;
    std::cout << "Force Applied: " << testObject.inclinePlane.externalForceApplied << " [N]" << std::endl;
    std::cout << "Object Shape: " << testObject.inclinePlane.objectShape << std::endl;
    std::cout << "Object Material: " << testObject.inclinePlane.objectMaterial << std::endl;

    return 0;
}