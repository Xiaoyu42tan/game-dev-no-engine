#include "Particles/Particle.h"

#include "ParticleGrid.h"

Particle::Particle(Element element, sf::Color color) 
    : element(element)
    , color(color)
{}

void Particle::step(const sf::Vector2i& position, ParticleGrid& grid) { /* do nothing */ }