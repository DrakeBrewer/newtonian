#pragma once
#include <vector>
#include <memory>
#include "LightBase.hpp"
#include "Medium.hpp"
#include "../collisionSim/rigidBody.hpp"
#include <iostream>

struct sceneBounds {
    Vector3d minBound;
    Vector3d maxBound;

    bool contains(const Vector3d& point) const {
        return  (point.x >= minBound.x && point.x <= maxBound.x) &&
                (point.y >= minBound.y && point.y <= maxBound.y) &&
                (point.z >= minBound.z && point.z <= maxBound.z);
    }
};

struct Plane {
    Vector3d normalVector;
    float distanceFromOrigin;

    Plane(Vector3d normal, float distance)
        : normalVector(normal), distanceFromOrigin(distance) {}

    bool isBelow(const Vector3d point) const {
        return (normalVector.x * point.x + normalVector.y * point.y + normalVector.z * point.z + distanceFromOrigin) < 0;
    }
};

class lightScene {
    private:
        std::vector<std::unique_ptr<LightBase>> lights;
        std::vector<std::unique_ptr<Medium>> mediums; 
        sceneBounds bounds;
        Plane ground;
        double timeElapsed;
        double maxTime;

    public:
        //lightScene bounded by duration of lightScene. Default 10 seconds
        lightScene (double duration, Vector3d minBound, Vector3d maxBound);

        void addMedium(std::unique_ptr<Medium> newMedium);
        void addLight(const LightBase& newLight);
        void simulate(double timeStep);

        const std::vector<std::unique_ptr<LightBase>>& getLights() const;
};
