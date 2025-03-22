#pragma once
#include <vector>
#include <memory>
#include "LightBase.hpp"
#include "../../../lib/vector3d/vector3d.hpp"
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
        float fixedTime = 1.0/60; // 60Hz fixed time step
        float timeElapsed;
        float maxTime;

        //lightScene bounded by duration of lightScene. 5 second minimum.
        LightScene (float duration, Vector3d minBound, Vector3d maxBound);
        LightScene ();
        ~LightScene ();

        void addLight(LightBase& newLight);
        void addMaterial(Material& mat);
        void simulate();
        void update(float deltaTime);

        Material* findMaterialInteraction(Vector3d& position);

        const std::vector<std::unique_ptr<LightBase>>& getLights() const;
};
