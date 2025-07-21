#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle

#include <SFML/System/Vector2.hpp>

// forward decls
class ParticleGrid;

class DebugSolid : public Particle {
public:
    static constexpr sf::Color DEFAULT_COLOR = sf::Color::Magenta;
    DebugSolid(ParticleGrid& grid);
    void step() override;
    ~DebugSolid() override = default;
};

