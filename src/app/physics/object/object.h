#pragma once
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
    double planetMass; // this is m1, the mass of the planet [kg]
    double moonMass; // this is m2, the mass of the moon in orbit [kg]
    double planetMoonDistance; // distance between center of planet and moon [m]
    double moonVelocity; // velocity of the moon [m/s]
    double orbitTime;  // time it takes for the moon to do 1 orbit [s]
    double gravitationalConstant; // big G
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
        orbitalMechanics.planetMass = 5.97e24;
        orbitalMechanics.moonMass = 7.35e22;
        orbitalMechanics.planetMoonDistance = 3.84e8;
        orbitalMechanics.moonVelocity = 1022;
        orbitalMechanics.orbitTime = 2.36e6;
        orbitalMechanics.gravitationalConstant = 6.67430e-11;

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