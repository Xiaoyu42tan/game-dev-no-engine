#include "Particles/Sand.h"

#include "Particles/Element.h"
#include "ParticleGrid.h"

Sand::Sand(ParticleGrid& grid)
    : Particle(Element::SAND, getElementColor(Element::SAND), grid)
    , hasGravity(*this, SAND_ACCELERATION, SAND_MAX_VELOCITY)
{}

void Sand::step() {
    hasGravity.step();
}


