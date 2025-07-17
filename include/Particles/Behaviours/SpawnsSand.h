#pragma once

#include "Particles/Behaviours/Behaviour.h"

class ParticleGrid;

class SpawnsSand : public Behaviour {
public:
    SpawnsSand(Particle& particle);

    void step() override;
};
