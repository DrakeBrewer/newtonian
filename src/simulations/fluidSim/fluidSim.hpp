#pragma once
#include "fluid.hpp"
#include "object.hpp"

void userInterface();

int run();
int runTest1();
int runTest2();

// Need: to implement rigidBody
int runSimulation(object obj, fluid liquid, bool printFlag);
float netForce(object obj, fluid liquid, float velocity);
