#include "Particles/Empty.h"

#include "Particles/Element.h"
#include "ParticleGrid.h"

Empty::Empty()
    : Particle(Element::EMPTY, getElementColor(Element::EMPTY))
{}

void Empty::step(const sf::Vector2i& position, ParticleGrid& grid) { /*do nothing*/ }