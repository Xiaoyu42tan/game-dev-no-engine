#include "Particles/SandSource.h"

#include "Particles/Element.h"
#include "Particles/ParticleFactory.h"
#include "Particles/Sand.h"
#include "Particles/ParticleGrid.h"

SandSource::SandSource(ParticleGrid& grid)
    : Particle(Element::SAND_SOURCE, getElementColor(Element::SAND_SOURCE), grid)
{
    behaviourSet.add<SpawnsSand>(std::make_shared<SpawnsSand>(*this));
}

void SandSource::step() {
    behaviourSet.get<SpawnsSand>()->step();
}
