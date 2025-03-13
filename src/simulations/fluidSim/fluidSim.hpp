#pragma once
#include "fluid.hpp"
#include "object.hpp"


int run();
int runTest1();
int runTest2();
float netForce(object obj, fluid liquid, float velocity);
void userInterface();
int runSimulation(object obj, fluid liquid, bool printFlag);
