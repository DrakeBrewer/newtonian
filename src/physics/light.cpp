#include <iostream>
#include <ostream>
#include <math.h>

class Light {
private:
    double intensity; // watts/square-meter
    double wavelength; // nano-meter
    double currentSpeed; // speed in current medium
    double refractiveIndex; // mediums refraction index
    const double vacuumSpeed = 2.99792458e8; // m/s

public:

    Light(double i, double w){
	intensity = i;
	wavelength = w;
	refractiveIndex = 1.0;
	currentSpeed = vacuumSpeed;
    }

    double getIntensity() { return intensity; }
    double getWavelength() { return wavelength; }

    void setIntensity(double i) { intensity = i; }
    void setWavelength(double w) { wavelength = w; }

    void refraction(double indexR) {
	if(indexR <= 0) {
	    std::cerr << "Invalid refractive index!\n";
	    return;
	}
	refractiveIndex = indexR;
	currentSpeed = vacuumSpeed / refractiveIndex;
    }

    void showInfo() {
	std::cout << "Intensity: " << intensity << " W/m^2" << std::endl;
	std::cout << "Wavelength: " << wavelength << " nm" << std::endl;
	std::cout << "Speed: " << currentSpeed << " m/s" << std::endl;
	std::cout << "Frequency: " << currentSpeed/wavelength << " Hz" << std::endl;
    }

};

int main(){
    Light laser(500, 650);
    laser.showInfo();
    laser.setIntensity(600);
    std::cout << "New Intensity: " << laser.getIntensity() << std::endl;
    return 0;
}



