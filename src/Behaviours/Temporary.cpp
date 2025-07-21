#include "Behaviours/Temporary.h"

#include "Particles/ParticleFactory.h"
#include "Particles/ParticleGrid.h"
#include "Particles/Element.h"

#include "Util/Random.h"

#include <algorithm>
#include <iostream>

Temporary::Temporary(
    Particle& particle,
    int lifetime,
    int lifetimeVariance,
    std::optional<int> timeLeft,
    Element turnsInto,
    float turnsIntoChance,
    bool fadeAway
)
    : Behaviour(particle)
    , totalLifetime(std::max(0, lifetime + randomInt(-lifetimeVariance, lifetimeVariance)))
    , turnsInto(turnsInto)
    , turnsIntoChance(turnsIntoChance)
    , fadeAway(fadeAway)
{
    if (timeLeft) {
        this->timeLeft = *timeLeft;
    } else {
        this->timeLeft = totalLifetime;
    }

    if (fadeAway) renderParticleFade();
}

void Temporary::step() {
    timeLeft--;
    if (timeLeft <= 0) {
        if (randomChance(turnsIntoChance)) {
            // use delayedSet here because if we set our own current position to another particle
            // ... then WE will get deleted. weird things will happen, idek if the function will return etc.
            grid.delayedSet(particle.position, factoryMakeParticle(turnsInto, grid));
        } else {
            grid.delayedSet(particle.position, factoryMakeParticle(Element::EMPTY, grid));
        }
    }

    if (fadeAway) renderParticleFade();
}

void Temporary::renderParticleFade() {
    particle.color.a = static_cast<uint8_t>(255.f * getPercent());
}

void Temporary::refreshLifetime() {
    timeLeft = totalLifetime;
}

float Temporary::getPercent() const {
    return std::clamp(static_cast<float>(timeLeft) / static_cast<float>(totalLifetime), 0.0f, 1.0f);
}