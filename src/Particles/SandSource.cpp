#include "Particles/SandSource.h"

#include "Particles/Element.h"
#include "Particles/ParticleFactory.h"
#include "Particles/Sand.h"
#include "Particles/ParticleGrid.h"

SandSource::SandSource(ParticleGrid& grid)
    : Particle(Element::SAND_SOURCE, SandSource::DEFAULT_COLOR, grid)
{
    behaviourSet.add<Spawner>(std::make_shared<Spawner>(*this, Element::SAND, SPAWN_OFFSET));
}

void SandSource::step() {
    behaviourSet.get<Spawner>()->step();
}
