#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle
#include "Particles/Element.h"

#include <SFML/System/Vector2.hpp>

class ParticleGrid;

constexpr float WOOD_FLAMMABILITY = 0.02f;
constexpr unsigned int WOOD_FLAMMABLE_LIFETIME = 400;
constexpr unsigned int WOOD_FLAMMABLE_LIFETIME_VARIANCE = static_cast<unsigned int>(static_cast<float>(WOOD_FLAMMABLE_LIFETIME) / 10);

constexpr Element WOOD_BURNED_TURNS_INTO = Element::ASH;
constexpr float WOOD_BURNED_TURNS_INTO_CHANCE = 0.5f;

constexpr Element WOOD_BURNING_SPAWNS = Element::FIRE;
constexpr sf::Vector2i WOOD_BURNING_SPAWN_DIRECTION = {0, -1};

constexpr bool WOOD_FADE_AWAY_WHILE_BURNING = false;

class Wood : public Particle {
public:
    static constexpr sf::Color DEFAULT_COLOR = sf::Color(139, 69, 19); // brown

    Wood(ParticleGrid& grid);
    void step() override;
    ~Wood() override = default;
};
