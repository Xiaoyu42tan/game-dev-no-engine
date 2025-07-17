#include "Particles/Empty.h"

#include "Particles/Element.h"
#include "ParticleGrid.h"

Empty::Empty(ParticleGrid& grid)
    : Particle(Element::EMPTY, getElementColor(Element::EMPTY), grid)
{}

void Empty::step() { /*do nothing*/ }