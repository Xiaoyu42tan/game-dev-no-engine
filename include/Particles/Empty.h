#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle

#include <SFML/System/Vector2.hpp>

class Empty : public Particle {
public:
    Empty(ParticleGrid& grid);
    void step() override;
    ~Empty() override = default;
};
