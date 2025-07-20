#include "Particles/Empty.h"

#include "Particles/Element.h"
#include "Particles/ParticleGrid.h"

Empty::Empty(ParticleGrid& grid)
    : Particle(Element::EMPTY, getElementColor(Element::EMPTY), grid)
{}

void Empty::step() { /*do nothing*/ }