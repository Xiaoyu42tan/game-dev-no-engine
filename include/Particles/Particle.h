#pragma once

#include "Particles/Element.h"

#include <memory>

#include <SFML/Graphics/Color.hpp> // lightweight header
#include <SFML/System/Vector2.hpp> // lightweight header

// forward decls
class ParticleGrid;

class Particle {
public:
    const Element element;
    sf::Color color;

    Particle(Element element, sf::Color color);

    virtual void step(const sf::Vector2i& position, ParticleGrid& grid);

    virtual ~Particle() = default;
};

using ParticlePtr = std::shared_ptr<Particle>;