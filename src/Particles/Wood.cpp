#include "Particles/Wood.h"

#include "Particles/Element.h"
#include "Particles/ParticleGrid.h"

#include "Behaviours/Flammable.h"
#include "Behaviours/Temporary.h"
#include "Behaviours/Spawner.h"

Wood::Wood(ParticleGrid& grid)
    : Particle(Element::WOOD, Wood::DEFAULT_COLOR, grid)
{
    behaviourSet.add<Flammable>(std::make_shared<Flammable>(*this, WOOD_FLAMMABILITY));
    behaviourSet.add<Temporary>(std::make_shared<Temporary>(
        *this,
        WOOD_FLAMMABLE_LIFETIME,
        WOOD_FLAMMABLE_LIFETIME_VARIANCE,
        std::nullopt,
        WOOD_BURNED_TURNS_INTO,
        WOOD_BURNED_TURNS_INTO_CHANCE,
        WOOD_FADE_AWAY_WHILE_BURNING
    ));

    behaviourSet.add<Spawner>(std::make_shared<Spawner>(*this, WOOD_BURNING_SPAWNS, WOOD_BURNING_SPAWN_DIRECTION));
}

void Wood::step() {
    behaviourSet.get<Flammable>()->step();

    if (behaviourSet.get<Flammable>()->ignited) {
        behaviourSet.get<Spawner>()->step();
        behaviourSet.get<Temporary>()->step();
    }
}


