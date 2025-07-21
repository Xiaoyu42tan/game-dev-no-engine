#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle

#include <SFML/System/Vector2.hpp>

class ParticleGrid;

constexpr float SMOKE_MAX_VELOCITY = -0.5f;
constexpr float SMOKE_ACCELERATION = -0.1f;
constexpr unsigned int SMOKE_LIFETIME = 500;
constexpr unsigned int SMOKE_LIFETIME_VARIANCE = static_cast<unsigned int>(static_cast<float>(SMOKE_LIFETIME) / 10);

class Smoke : public Particle {
public:
    static constexpr sf::Color DEFAULT_COLOR = sf::Color(50, 50, 50); // grey

    Smoke(ParticleGrid& grid);
    void step() override;
    ~Smoke() override = default;
};
