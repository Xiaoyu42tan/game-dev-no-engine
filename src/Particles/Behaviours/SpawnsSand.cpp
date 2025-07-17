#include "Particles/Behaviours/SpawnsSand.h"

#include "Particles/ParticleFactory.h"
#include "ParticleGrid.h"

SpawnsSand::SpawnsSand(Particle& particle)
    : Behaviour(particle)
{}

void SpawnsSand::step() {
    // spawn sand below if possible
    sf::Vector2i down = {particle.position.x, particle.position.y + 1};
    if (grid.inBounds(down) && grid.get(down)->element == Element::EMPTY) {
        grid.set(down, factoryMakeParticle(Element::SAND, grid));
    }
}
