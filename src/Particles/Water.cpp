#include "Particles/Water.h"

#include "Particles/Element.h"
#include "Particles/ParticleGrid.h"

Water::Water(ParticleGrid& grid)
    : Particle(Element::WATER, Water::DEFAULT_COLOR, grid)
{
    behaviourSet.add<LiquidLike>(std::make_shared<LiquidLike>(*this, WATER_ACCELERATION, WATER_MAX_VELOCITY, WATER_DENSITY));
}

void Water::step() {
    behaviourSet.get<LiquidLike>()->step();
}


