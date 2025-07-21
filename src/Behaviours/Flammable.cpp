#include "Behaviours/Flammable.h"

#include "Particles/ParticleGrid.h"
#include "Particles/ParticleFactory.h"
#include "Util/Random.h"

#include <array>

Flammable::Flammable(Particle& particle, float spreadChance)
    : Behaviour(particle)
    , spreadChance(spreadChance)
{
    renderParticleColor();
}

void Flammable::step() {
    constexpr static std::array<sf::Vector2i, 4> DIRECTIONS = {
        sf::Vector2i{0, 1},
        sf::Vector2i{0, -1},
        sf::Vector2i{1, 0},
        sf::Vector2i{-1, 0},
    };

    if (ignited) {
        for (auto dir : DIRECTIONS) {
            if (shouldSpread(particle.position + dir)) {
                grid.get(particle.position + dir)->behaviourSet.get<Flammable>()->ignited = true;
            }
        }
    }

    renderParticleColor();
}

bool Flammable::shouldSpread(const sf::Vector2i& position) const {
    return grid.inBounds(position) && grid.get(position)->behaviourSet.has<Flammable>() && randomChance(spreadChance);
}

void Flammable::renderParticleColor() {
    constexpr static std::array<sf::Color, 5> colorChanges = {
        // color palette from https://www.schemecolor.com/fire-color-scheme.php
        sf::Color(128, 17, 0),
        sf::Color(182, 34, 3),
        sf::Color(215, 53, 2),
        sf::Color(252, 100, 0),
        sf::Color(250, 192, 0),
    };

    if (ignited && randomChance(0.1f)) {
        auto selectedColor = colorChanges[randomInt(0, colorChanges.size() - 1)];
        particle.color.r = selectedColor.r;
        particle.color.g = selectedColor.g;
        particle.color.b = selectedColor.b;
    } else if (!ignited) {
        auto selectedColor = factoryGetColor(particle.element);
        particle.color.r = selectedColor.r;
        particle.color.g = selectedColor.g;
        particle.color.b = selectedColor.b;
    }
}
