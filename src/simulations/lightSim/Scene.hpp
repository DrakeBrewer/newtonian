#pragma once
#include <vector>
#include <memory>
#include "LightBase.hpp"
#include "Medium.hpp"
#include <iostream>

class Scene {
    private:
        std::vector<std::unique_ptr<LightBase>> lights;
        std::vector<std::unique_ptr<Medium>> objects; 
        double timeElapsed;
        double maxTime;

    public:
        //Scene bounded by duration of Scene. Default 10 seconds
        Scene (double duration = 10.0);

        void addObject(std::unique_ptr<Medium> obj);
        void addLight(const LightBase& light);
        void simulate(double timeStep);

        const std::vector<std::unique_ptr<LightBase>>& getLights() const;
};
