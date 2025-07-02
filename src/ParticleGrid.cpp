#include "ParticleGrid.h"

ParticleGrid::ParticleGrid(const sf::Vector2u& dimensions) 
    : dimensions(dimensions)
    , grid(dimensions.x * dimensions.y, Particle{Material::NONE, false})
{}

void ParticleGrid::set(unsigned int x, unsigned int y, Material material) {
    assert(x < dimensions.x && y < dimensions.y);
    
    int index = y * dimensions.x + x;
    grid[index].material = material;
    grid[index].isDirty = true;
}

void ParticleGrid::resetDirty() {
    for (Particle& p : grid) p.isDirty = false;
}
