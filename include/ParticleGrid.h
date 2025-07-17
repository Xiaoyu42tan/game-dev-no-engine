#pragma once

#include "Particles/Particle.h"

#include <vector>
#include <memory>

#include <SFML/Graphics/Color.hpp> // lightweight header
#include <SFML/System/Vector2.hpp> // lightweight header

class ParticleGrid {
public:
    ParticleGrid(const sf::Vector2u& dimensions);

    // Get a particle
    std::shared_ptr<Particle> get(const sf::Vector2i& position) const;
    
    // sets particle at {x, y}
    // make sure position is a copy to prevent passing self reference
    void set(sf::Vector2i position, std::shared_ptr<Particle> particle);
    
    // swaps particle at {x1, y1} with particle at {x2, y2}
    // make sure position is a copy to prevent passing self reference
    void swap(sf::Vector2i position1, sf::Vector2i position2);
    
    inline bool inBounds(const sf::Vector2i& position) const { return position.x >= 0 && position.x < dimensions.x && position.y >= 0 && position.y < dimensions.y; }
private:

    inline int getIndex(const sf::Vector2i& position) const { return position.y * dimensions.x + position.x; }

    // using flat vectors for contiguous memory
    std::vector<std::shared_ptr<Particle>> grid;
    sf::Vector2u dimensions;
};
