#include "Particles/DebugSolid.h"

#include "Particles/Element.h"
#include "ParticleGrid.h"

DebugSolid::DebugSolid(ParticleGrid& grid)
    : Particle(Element::DEBUG_SOLID, getElementColor(Element::DEBUG_SOLID), grid)
{}

void DebugSolid::step() { /*do nothing*/ }
