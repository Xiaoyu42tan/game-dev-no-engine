#include "Particles/Sand.h"

#include "Particles/Element.h"
#include "Particles/ParticleGrid.h"

Sand::Sand(ParticleGrid& grid)
    : Particle(Element::SAND, getElementColor(Element::SAND), grid)
{
    behaviourSet.add<PowderLike>(std::make_shared<PowderLike>(*this, SAND_ACCELERATION, SAND_MAX_VELOCITY));
}

void Sand::step() {
    behaviourSet.get<PowderLike>()->step();
}


