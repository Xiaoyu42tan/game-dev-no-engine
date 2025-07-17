#pragma once

#include "Particles/Element.h"
#include "Particles/Behaviours/Behaviour.h"

#include <memory>

#include <SFML/Graphics/Color.hpp> // lightweight header
#include <SFML/System/Vector2.hpp> // lightweight header

// forward decls
class ParticleGrid;

class Particle {
public:
    const Element element;
    sf::Color color;
    sf::Vector2i position = {-1, -1};

    Particle(Element element, sf::Color color, ParticleGrid& grid);

    virtual void step();

    virtual ~Particle() = default;
protected:
    friend class Behaviour;
    ParticleGrid& grid;
    
};

using ParticlePtr = std::shared_ptr<Particle>;