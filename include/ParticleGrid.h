#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Particle.h"

class ParticleGrid {
public:
    ParticleGrid(const sf::Vector2u& dimensions);

    // Get a particle
    inline Particle get(unsigned int x, unsigned int y) const {
        assert(x < dimensions.x && y < dimensions.y);
        return grid[y * dimensions.x + x];
    }
    
    // Set a particle to a material. Marks it dirty. Dirty particles will not be updated again.
    void set(unsigned int x, unsigned int y, Material material);

    // Undirties the entire grid
    void resetDirty();
private:
    // using flat vectors for contiguous memory
    std::vector<Particle> grid;
    sf::Vector2u dimensions;
};
