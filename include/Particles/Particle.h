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

    // NAIVE TESTING FOR MEMORY LEAK
    inline static int numCreated = 0;
    inline static int numDeleted = 0;

    inline virtual ~Particle() { numDeleted++; }
protected:
    friend class Behaviour;
    ParticleGrid& grid;
    
};