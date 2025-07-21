#pragma once

#include "Behaviours/Behaviour.h"

#include <SFML/System/Vector2.hpp>

class Particle;

class PowderLike : public Behaviour {
public:
    PowderLike(Particle& particle, float acceleration, float maxVelocity);

    void step() override;
private:
    void stepHelper();

    bool canSwapWith(const sf::Vector2i& position) const;

    // velocity in terms of units per simulation step
    float velocity = 0.f;
    const float maxVelocity;
    
    // acceleration due to gravity. can be negative (floats instead of sinks). in terms of units per simulation step squared
    const float acceleration;
    
};


