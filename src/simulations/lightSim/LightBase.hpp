#pragma once

class LightBase {
public:

    virtual ~LightBase() {}

    virtual void update(float timeStep) = 0;
    virtual void showProperties() const = 0;
    virtual LightBase* clone() const = 0;
};
