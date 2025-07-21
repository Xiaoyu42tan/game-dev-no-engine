#pragma once

#include "Behaviours/Behaviour.h"
#include "Particles/Element.h"

#include <optional>

class Particle;

class Temporary : public Behaviour {
public:
    Temporary(
        Particle& particle,
        int lifetime,
        int lifetimeVariance,
        std::optional<int> timeLeft = std::nullopt,
        Element turnsInto = Element::EMPTY,
        float turnsIntoChance = 1.f,
        bool fadeAway = true
    );

    void step() override;
    void refreshLifetime();

    // returns the percentage of how much time is left
    float getPercent() const;

    int timeLeft;
    const int totalLifetime;
private:
    void renderParticleFade();

    const Element turnsInto;
    const float turnsIntoChance;
    const bool fadeAway;
};

