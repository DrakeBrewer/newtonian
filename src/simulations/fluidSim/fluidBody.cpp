#include "fluidBody.hpp"
#include "fluidWorld.hpp"
#include "vector3d.hpp"
#include <cmath>
#include <cstdio>
#include <iostream>








float fluidEllipse::diameter() {
	return 2 * this->radius;
}

void fluidEllipse::update(double delta) {
	fluidBody::update(delta);
}


void fluidRectangle::update(double delta) {
	fluidBody::update(delta);
}

/*
int main(int argc, char **argv) {
    fluidRectangle *rect = new fluidRectangle(5000, 50, Vector3d(0, 0, 0), 100, true, 1000);
    fluidEllipse *ellipse = new fluidEllipse(20, Vector3d(0, 0, 250), 5, false,  1.05, 500);
    fluidPhysicsWorld *world = new fluidPhysicsWorld(9.81);
    std::cout << rect->density  <<  std::endl;
    std::cout << "mass:  "  << rect->mass << std::endl;

}
    */