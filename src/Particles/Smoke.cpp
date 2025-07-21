#include "Particles/Smoke.h"

#include "Behaviours/Temporary.h"
#include "Behaviours/LiquidLike.h"

Smoke::Smoke(ParticleGrid& grid)
    : Particle(Element::SMOKE, Smoke::DEFAULT_COLOR, grid)
{
    behaviourSet.add<Temporary>(std::make_shared<Temporary>(*this, SMOKE_LIFETIME, SMOKE_LIFETIME_VARIANCE));
    behaviourSet.add<LiquidLike>(std::make_shared<LiquidLike>(*this, SMOKE_ACCELERATION, SMOKE_MAX_VELOCITY, 0.1f));
}

void Smoke::step() {
    behaviourSet.get<LiquidLike>()->step();
    behaviourSet.get<Temporary>()->step();
}
