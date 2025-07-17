#include "Particles/Particle.h"

#include "ParticleGrid.h"

Particle::Particle(Element element, sf::Color color, ParticleGrid& grid) 
    : element(element)
    , color(color)
    , grid(grid)
{}

void Particle::step() { /* do nothing */ }