#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle

#include <SFML/Graphics/Color.hpp> // needed because color is defined inline
#include <SFML/System/Vector2.hpp>

// forward decls
class ParticleGrid;

class DebugSolid : public Particle {
public:
    DebugSolid();
    void step(const sf::Vector2i& position, ParticleGrid& grid) override;
    ~DebugSolid() override = default;
};

