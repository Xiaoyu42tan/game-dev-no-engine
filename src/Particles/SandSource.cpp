#include "Particles/SandSource.h"

#include "Particles/Element.h"
#include "Particles/ParticleFactory.h"
#include "Particles/Sand.h"
#include "ParticleGrid.h"

SandSource::SandSource()
    : Particle(Element::SAND_SOURCE, getElementColor(Element::SAND_SOURCE))
{}

void SandSource::step(const sf::Vector2i& position, ParticleGrid& grid) {
    // spawn sand below if possible
    sf::Vector2i down = {position.x, position.y + 1};
    if (grid.inBounds(down) && grid.get(down)->element == Element::EMPTY) {
        grid.set(down, factoryMakeParticle(Element::SAND));
    }
}