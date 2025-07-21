#include "Behaviours/Spawner.h"

#include "Particles/ParticleFactory.h"
#include "Particles/ParticleGrid.h"

Spawner::Spawner(Particle& particle, Element element, sf::Vector2i offset)
    : Behaviour(particle)
    , offset(offset)
    , element(element)
{}

void Spawner::step() {
    // spawn sand below if possible
    sf::Vector2i position = {particle.position.x + offset.x, particle.position.y + offset.y};
    if (grid.inBounds(position) && grid.get(position)->element == Element::EMPTY) {
        grid.set(position, factoryMakeParticle(element, grid));
    }
}
