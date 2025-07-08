#include "Particles/DebugSolid.h"

#include "Particles/Element.h"
#include "ParticleGrid.h"

DebugSolid::DebugSolid()
    : Particle(Element::DEBUG_SOLID, getElementColor(Element::DEBUG_SOLID))
{}

void DebugSolid::step(const sf::Vector2i& position, ParticleGrid& grid) { /*do nothing*/ }
