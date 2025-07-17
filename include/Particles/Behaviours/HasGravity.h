#pragma once

#include "Particles/Behaviours/Behaviour.h"

class ParticleGrid;


class HasGravity : public Behaviour {
public:
    HasGravity(Particle& particle, float acceleration, float maxVelocity);

    void step() override;
private:
    void stepHelper();

    float velocity = 0.f;
    const float acceleration;
    float maxVelocity;
};


