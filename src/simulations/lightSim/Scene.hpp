#pragma once
#include <vector>
#include <memory>
#include "Medium.hpp"
#include "LightRay.hpp"
#include "LightWave.hpp"
#include "LightParticle.hpp"

class Scene {
    private:
        std::vector<std::unique_ptr<Medium>> objects; 
        std::vector<std::unique_ptr<LightRay>> rays; 
        std::vector<std::unique_ptr<LightWave>> waves;
        std::vector<std::unique_ptr<LightParticle>> photons;

        double timeElapsed;
        double maxTime;

    public:
        Scene (double duration = 10.0) // Default duration of 10 seconds
            : timeElapsed(0.0), maxTime(duration) {}

        void addObject(std::unique_ptr<Medium> obj);
        void addRay(const LightRay& ray);
        void addWave(const LightWave& wave);
        void addPhoton(const LightParticle& photon);
        void simulate(double timeStep);

        std::vector<std::unique_ptr<LightRay>>& getRays() { return rays; }
        std::vector<std::unique_ptr<LightWave>>& getWaves() { return waves; }
        std::vector<std::unique_ptr<LightParticle>>& getParticles() { return photons; }

        bool isComplete() const { return timeElapsed >= maxTime; }
};
