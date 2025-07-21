#include "Particles/DebugSolid.h"

#include "Particles/Element.h"
#include "Particles/ParticleGrid.h"

DebugSolid::DebugSolid(ParticleGrid& grid)
    : Particle(Element::DEBUG_SOLID, DebugSolid::DEFAULT_COLOR, grid)
{}

void DebugSolid::step() { /*do nothing*/ }
