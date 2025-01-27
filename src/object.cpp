#include <iostream>
#include <string>

class Object{
public:
    // Universal
    double mass; // mass of the object [kg]
    double gravity; // gravitational acceleration [m/s^2]

    // Inclined Plane Interaction
    double angle; // angle of the incline [degrees]
    double length; // length of the incline surface [m]
    double frictionCoefficient; // how much friction [no units]
    double externalForceApplied; // external force applied to the object [N]
    std::string objectShape; // shape of the object
    std::string objectMaterial; // what the object is made out of

    // Time Control System
    double timeScale; // how fast the time is moving (...0.75x, 1x, 1.25x, ...)
    double currentTime; // what the current time scale is
    bool isPaused; // this is "freezing" the time or not, pausing or unpausing the simulation
    int frameRate; // this is for frame-by-frame control

    // Orbital Mechanics
    double centralMassOfBody; // this is big M, the mass of what is being orbited around [kg]
    double orbitingObjectMass; // this is small m, the mass of the object in orbit [kg]
    double initialVelocity; // the initial velocity of orbiting object [m/s]
    double trajectoryOfOrbit; // orbital trajectory [m]
    double distanceFromCenter; // how far away center of object is from center of central mass [m]

    // Light Intertaction
    double lightIntensity; // how bright/ dim the light is [W/m^2]
    double wavelength; // the wavelength of the light [nm]
    double refractiveIndex; // the refractive index of the medium [no units]
    double reflectivityOfObject; // how reflective the object is [no units]

    // Fluid Simulation
    double fluidDensity; // density of the fluid [kg/m^3]
    double fluidViscosity; // viscosity of the fluid [(Pa)(s)]
    double objectVolume; // volume of the object [m^3]
    double fluidVelocity; // how fast the fluid is moving [m/s]

    // Planetary Physics
    double planetGravity; // gravitational acceleration of the planet [m/s^2]
    std::string planetName; // the name of the planet that is selected

    // Collision System
    double elasticity; // coefficient of restitution [no units]
    double impulse; // the impulse during the collision [(N)(s)]
    double objectVelocity; // speed of the object [m/s]
    double objectPosition; // where the object is away from a point [m]
    bool isCollision; // is there a collision or not

    // Constructor for the variables
    Object(
        double m = 1.0, double g = 9.81, double deg = 0.0, double l = 1.0, double fc = 0.5,
        const std::string& shape = "box", const std::string& material = "wood", const std::string& planet = "Earth"
    ) :
        // Universal
        mass(m),
        gravity(g),

        // Inclined Plane Interaction
        angle(deg),
        length(l),
        frictionCoefficient(fc),
        externalForceApplied(0.0),
        objectShape(shape),
        objectMaterial(material),

        // Time Control System
        timeScale(1.0),
        currentTime(0.0),
        isPaused(false),
        frameRate(60),

        // Orbital Mechanics
        centralMassOfBody(5.97e24),
        orbitingObjectMass(1.0),
        initialVelocity(0.0),
        trajectoryOfOrbit(0.0),
        distanceFromCenter(10.0),

        // Light Intertaction
        lightIntensity(100.0),
        wavelength(500.0),
        refractiveIndex(1.0),
        reflectivityOfObject(0.7),

        // Fluid Simulation
        fluidDensity(100.0),
        fluidViscosity(1.0),
        objectVolume(1.0),
        fluidVelocity(0.0),

        // Planetary Physics
        planetGravity(9.81),
        planetName(planet),

        // Collision System
        elasticity(0.7),
        impulse(0.0), 
        objectVelocity(0.0), 
        objectPosition(0.0),
        isCollision(false)
    {}
};


int main(){
    // TESTING: this object is made and some parameters printed just for testing
    Object testObject;
    std::cout << "Mass: " << testObject.mass << " [kg]" << std::endl;
    std::cout << "Gravity: " << testObject.gravity << " [m/s^2]" << std::endl;
    std::cout << "Planet Name: " << testObject.planetName << std::endl;

    return 0;
}