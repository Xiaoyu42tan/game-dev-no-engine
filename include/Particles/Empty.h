#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle

class ParticleGrid;

class Empty : public Particle {
public:
    static constexpr sf::Color DEFAULT_COLOR = sf::Color::Transparent;

    Empty(ParticleGrid& grid);
    void step() override;
    ~Empty() override = default;
};
