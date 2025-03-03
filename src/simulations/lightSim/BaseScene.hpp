#pragma once
#include <vector>
#include <memory>
#include "../collisionSim/rigidBody.hpp"
#include "Medium.hpp"

class BaseScene {
public:
    BaseScene(): x(1000), y(1000), z(1000) {}
    BaseScene(double x, double y, double z);
    ~BaseScene() {};

    std::vector<std::unique_ptr<RigidBody>> rigidBodies;
    std::vector<std::unique_ptr<Medium>> mediums;
    double x;
    double y;
    double z;
    float fixedTime = 1.0/60.0; // 60hz default update time
    double timeElapsed;
    double maxTime;

    bool inBounds(); // Used to delete object when it goes out of bounds
    void simulate(float fixedTime, double maxTime, double timeElapsed);
};
