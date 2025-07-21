#include "Particles/Empty.h"

#include "Particles/Element.h"
#include "Particles/ParticleGrid.h"

Empty::Empty(ParticleGrid& grid)
    : Particle(Element::EMPTY, Empty::DEFAULT_COLOR, grid)
{}

void Empty::step() { /*do nothing*/ }