#include "ParticleGrid.h"

#include "Particles/Empty.h"
#include "Particles/ParticleFactory.h"
#include "Particles/Element.h"

#include <iostream>

ParticleGrid::ParticleGrid(const sf::Vector2u& dimensions) 
    : dimensions(dimensions)
    , grid(dimensions.x * dimensions.y)
{
    for (int x = 0; x < dimensions.x; x++) {
        for (int y = 0; y < dimensions.y; y++) {
            set({x, y}, factoryMakeParticle(Element::EMPTY, *this));
        }
    }
}

std::shared_ptr<Particle> ParticleGrid::get(const sf::Vector2i& position) const {
    assert(inBounds(position));
    
    if (grid[getIndex(position)]->position != position) {
        std::cout << "ACTUAL: " << grid[getIndex(position)]->position.x << ", " << grid[getIndex(position)]->position.y << " vs INPUT: " << position.x << ", " << position.y << "\n";
    }
    assert(grid[getIndex(position)]->position == position);
    
    return grid[getIndex(position)];
}

void ParticleGrid::set(sf::Vector2i position, std::shared_ptr<Particle> particle) {
    assert(inBounds(position));
    grid[getIndex(position)] = particle;
    particle->position = position;
}

void ParticleGrid::swap(sf::Vector2i position1, sf::Vector2i position2) {
    assert(inBounds(position1));
    assert(inBounds(position2));
    
    std::swap(grid[getIndex(position1)]->position, grid[getIndex(position2)]->position);
    std::swap(grid[getIndex(position1)], grid[getIndex(position2)]);
}
