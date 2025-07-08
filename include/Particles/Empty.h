#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle

#include <SFML/Graphics/Color.hpp> // needed because color is defined inline
#include <SFML/System/Vector2.hpp>

class Empty : public Particle {
public:
    Empty();
    void step(const sf::Vector2i& position, ParticleGrid& grid) override;
    ~Empty() override = default;
};
