#include "ParticleGrid.h"

#include "Particles/Empty.h"
#include "Particles/ParticleFactory.h"
#include "Particles/Element.h"

ParticleGrid::ParticleGrid(const sf::Vector2u& dimensions) 
    : dimensions(dimensions)
    , grid(dimensions.x * dimensions.y)
{
    for (int i = 0; i < grid.size(); i++) {
        grid[i] = factoryMakeParticle(Element::EMPTY);
    }
}

ParticlePtr ParticleGrid::get(const sf::Vector2i& position) const {
    assert(inBounds(position));
    return grid[getIndex(position)];
}

void ParticleGrid::set(const sf::Vector2i& position, ParticlePtr particle) {
    assert(inBounds(position));
    grid[getIndex(position)] = particle;
}

void ParticleGrid::swap(const sf::Vector2i& position1, const sf::Vector2i& position2) {
    assert(inBounds(position1));
    assert(inBounds(position2));
    std::swap(grid[getIndex(position1)], grid[getIndex(position2)]);
}
