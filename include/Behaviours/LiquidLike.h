#pragma once

#include "Behaviours/Behaviour.h"

#include <SFML/System/Vector2.hpp>

class Particle;

class LiquidLike : public Behaviour {
public:
    LiquidLike(Particle& particle, float acceleration, float maxVelocity, float density);

    void step() override;
private:
    void stepHelper();

    bool canSwapWith(const sf::Vector2i& position) const;

    // velocity in terms of units per simulation step
    float velocity = 0.f;
    
    // how quickly liquid reaches max velocity. can be negative (floats instead of sinks). in terms of units per simulation step squared
    const float acceleration;
    
    // how fast can the liquid move (basically maxVelocity)
    const float maxVelocity;

    // liquid will float above others if it has less density
    const float density;
};


