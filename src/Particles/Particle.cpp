#include "Particles/Particle.h"

#include "Particles/ParticleGrid.h"

Particle::Particle(Element element, sf::Color color, ParticleGrid& grid)
    : element(element)
    , color(color)
    , grid(grid)
    , behaviourSet(*this)
{
    numCreated++;
}

void Particle::step() { /* do nothing */ }