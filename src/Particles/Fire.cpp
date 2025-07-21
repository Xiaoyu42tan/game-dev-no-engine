#include "Particles/Fire.h"

#include "Particles/Element.h"
#include "Particles/ParticleGrid.h"

#include "Behaviours/Temporary.h"
#include "Behaviours/Flammable.h"

#include "Util/Random.h"

Fire::Fire(ParticleGrid& grid, unsigned int lifetime, std::optional<unsigned int> timeLeft)
    : Particle(Element::FIRE, Fire::DEFAULT_COLOR, grid)
{
    behaviourSet.add<Temporary>(std::make_shared<Temporary>(*this, lifetime, FIRE_LIFETIME_VARIANCE, timeLeft, FIRE_TURNS_INTO, FIRE_TURNS_INTO_CHANCE));
}

void Fire::step() {
    behaviourSet.get<Temporary>()->step();

    sf::Vector2i up = {position.x, position.y - 1};
    sf::Vector2i left = {position.x - 1, position.y};
    sf::Vector2i right = {position.x + 1, position.y};
    sf::Vector2i down = {position.x, position.y + 1};


    if (canSpread(up, upLifetimeDissipation())) {
        grid.set(up, std::make_shared<Fire>(grid, behaviourSet.get<Temporary>()->totalLifetime, upLifetimeDissipation()));
    }
    if (canSpread(left, horizontalLifetimeDissipation())) {
        grid.set(left, std::make_shared<Fire>(grid, behaviourSet.get<Temporary>()->totalLifetime, horizontalLifetimeDissipation()));
    }
    if (canSpread(right, horizontalLifetimeDissipation())) {
        grid.set(right, std::make_shared<Fire>(grid, behaviourSet.get<Temporary>()->totalLifetime, horizontalLifetimeDissipation()));
    }
    if (canSpread(down, downLifetimeDissipation())) {
        grid.set(down, std::make_shared<Fire>(grid, behaviourSet.get<Temporary>()->totalLifetime, horizontalLifetimeDissipation()));
    }

    if (shouldIgnite(up)) {
        grid.get(up)->behaviourSet.get<Flammable>()->ignited = true;
    }
    if (shouldIgnite(down)) {
        grid.get(down)->behaviourSet.get<Flammable>()->ignited = true;
    }
    if (shouldIgnite(left)) {
        grid.get(left)->behaviourSet.get<Flammable>()->ignited = true;
    }
    if (shouldIgnite(right)) {
        grid.get(right)->behaviourSet.get<Flammable>()->ignited = true;
    }
}

bool Fire::shouldIgnite(const sf::Vector2i& position) const {
    return grid.inBounds(position) && grid.get(position)->behaviourSet.has<Flammable>() && randomChance(behaviourSet.get<Temporary>()->getPercent());
}

bool Fire::canSpread(const sf::Vector2i& position, int newLifetime) const {
    return grid.inBounds(position) && grid.get(position)->element == Element::EMPTY && newLifetime > 0;
}

int Fire::upLifetimeDissipation() const {
    return static_cast<int>(std::max(0.f, static_cast<float>(behaviourSet.get<Temporary>()->timeLeft) / 1.35f));
}

int Fire::downLifetimeDissipation() const {
    return static_cast<int>(std::max(0.f, static_cast<float>(behaviourSet.get<Temporary>()->timeLeft) / 5.f));
}

int Fire::horizontalLifetimeDissipation() const {
    return static_cast<int>(std::max(0.f, static_cast<float>(behaviourSet.get<Temporary>()->timeLeft) / 2.5f));
}