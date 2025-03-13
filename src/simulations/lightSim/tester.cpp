#include "LightBase.hpp"
#include "../collisionSim/rigidBody.hpp"
#include "LightRay.hpp"

int main() {
    LightBase* light = new LightRay(600, 3.0, Vector3d(0,0,0), Vector3d(0,0,1));
    light->showProperties();
    delete light;
}

