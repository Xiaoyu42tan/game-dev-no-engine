#pragma once

#include "Particles/Particle.h" // need full include in this header because ParticlePtr is a type alias

#include <vector>
#include <memory>

#include <SFML/Graphics/Color.hpp> // lightweight header
#include <SFML/System/Vector2.hpp> // lightweight header

class ParticleGrid {
public:
    ParticleGrid(const sf::Vector2u& dimensions);

    // Get a particle
    ParticlePtr get(const sf::Vector2i& position) const;
    
    // sets particle at {x, y}
    // make sure position is a copy to prevent passing self reference
    void set(sf::Vector2i position, ParticlePtr particle);
    
    // swaps particle at {x1, y1} with particle at {x2, y2}
    // make sure position is a copy to prevent passing self reference
    void swap(sf::Vector2i position1, sf::Vector2i position2);
    
    inline bool inBounds(const sf::Vector2i& position) const { return position.x >= 0 && position.x < dimensions.x && position.y >= 0 && position.y < dimensions.y; }
private:

    inline int getIndex(const sf::Vector2i& position) const { return position.y * dimensions.x + position.x; }

    // using flat vectors for contiguous memory
    std::vector<ParticlePtr> grid;
    sf::Vector2u dimensions;
};
