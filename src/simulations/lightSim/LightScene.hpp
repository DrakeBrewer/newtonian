#pragma once
#include <vector>
#include <memory>
#include "LightBase.hpp"
#include "../collisionSim/rigidBody.hpp"
#include <iostream>
#include "MaterialVolume.hpp"
#include "../../../lib/deltaTime/deltaTime.hpp"

struct sceneBounds {
    Vector3d minBound;
    Vector3d maxBound;

    bool contains(const Vector3d& point) const {
        return  (point.x >= minBound.x && point.x <= maxBound.x) &&
                (point.y >= minBound.y && point.y <= maxBound.y) &&
                (point.z >= minBound.z && point.z <= maxBound.z);
    }
};

class LightScene {
    public:
        std::vector<std::unique_ptr<LightBase>> lights;
        std::vector<Material> materials;
        sceneBounds bounds;
        double fixedTime = 1.0/60; // 60Hz fixed time step
        double timeElapsed;
        double maxTime;

        //lightScene bounded by duration of lightScene. 5 second minimum.
        LightScene (double duration, Vector3d minBound, Vector3d maxBound);
        LightScene ();
        ~LightScene ();

        void addLight(const LightBase& newLight);
        void addMaterial(const Material& mat);
        void simulate();
        void update(float deltaTime);

        const Material* findMaterialInteraction(Vector3d& position) const;

        const std::vector<std::unique_ptr<LightBase>>& getLights() const;
};
