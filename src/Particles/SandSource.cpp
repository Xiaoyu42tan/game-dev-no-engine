#include "Particles/SandSource.h"

#include "Particles/Element.h"
#include "Particles/ParticleFactory.h"
#include "Particles/Sand.h"
#include "ParticleGrid.h"

SandSource::SandSource(ParticleGrid& grid)
    : Particle(Element::SAND_SOURCE, getElementColor(Element::SAND_SOURCE), grid)
    , spawner(*this)
{}

void SandSource::step() {
    spawner.step();
}