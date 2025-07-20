#include "Particles/Water.h"

#include "Particles/Element.h"
#include "Particles/ParticleGrid.h"

Water::Water(ParticleGrid& grid)
    : Particle(Element::WATER, getElementColor(Element::WATER), grid)
{
    behaviourSet.add<LiquidLike>(std::make_shared<LiquidLike>(*this, WATER_ACCELERATION, WATER_VISCOSITY, WATER_DENSITY));
}

void Water::step() {
    behaviourSet.get<LiquidLike>()->step();
}


