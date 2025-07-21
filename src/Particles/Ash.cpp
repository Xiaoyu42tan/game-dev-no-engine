#include "Particles/Ash.h"

#include "Particles/Element.h"
#include "Particles/ParticleGrid.h"

Ash::Ash(ParticleGrid& grid)
    : Particle(Element::ASH, Ash::DEFAULT_COLOR, grid)
{
    behaviourSet.add<PowderLike>(std::make_shared<PowderLike>(*this, ASH_ACCELERATION, ASH_MAX_VELOCITY));
}

void Ash::step() {
    behaviourSet.get<PowderLike>()->step();
}


