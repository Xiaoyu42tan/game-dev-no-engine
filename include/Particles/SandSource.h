#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle
#include "Behaviours/Spawner.h" // needed because its a member var

#include <memory>

#include <SFML/System/Vector2.hpp>

// forward decls
class ParticleGrid;


constexpr sf::Vector2i SPAWN_OFFSET = {0, 1};

class SandSource : public Particle {
public:
    static constexpr sf::Color DEFAULT_COLOR = sf::Color::White;

    SandSource(ParticleGrid& grid);
    void step() override;
    ~SandSource() override = default;
private:
};

