#include "Behaviours/PowderLike.h"

#include "Behaviours/LiquidLike.h"
#include "Particles/Element.h"
#include "Particles/ParticleGrid.h"

#include "Util/Random.h"

#include <cstdlib>

PowderLike::PowderLike(Particle& particle, float acceleration, float maxVelocity)
    : Behaviour(particle)
    , acceleration(acceleration)
    , maxVelocity(maxVelocity)
{}

void PowderLike::step() {
    velocity += acceleration;
    if (abs(velocity) > abs(maxVelocity)) velocity = maxVelocity;

    int numSteps = std::abs(stochasticRound(velocity));
    for (int i = 0; i < numSteps; i++) {
        stepHelper();
    }
}

void PowderLike::stepHelper() {
    if (velocity == 0.f) return;

    int direction = 1;
    if (velocity < 0) direction = -1;
    
    sf::Vector2i vertical = {particle.position.x, particle.position.y + direction};
    sf::Vector2i verticalLeft = {particle.position.x - 1, particle.position.y + direction};
    sf::Vector2i verticalRight = {particle.position.x + 1, particle.position.y + direction};
        
    if (canSwapWith(vertical)) {
        grid.swap(particle.position, vertical);
    } else if (canSwapWith(verticalLeft)) {
        grid.swap(particle.position, verticalLeft);
    } else if (canSwapWith(verticalRight)) {
        grid.swap(particle.position, verticalRight);
    } else {
        velocity = 0.f;
    }
}

bool PowderLike::canSwapWith(const sf::Vector2i& position) const {
    if (!grid.inBounds(position)) return false;

    auto otherParticle = grid.get(position);
    if (otherParticle->element == Element::EMPTY) return true;

    if (otherParticle->behaviourSet.has<LiquidLike>()) {
        // 33% chance to swap with liquid
        return rand() % 3 == 0;
    }

    return false;

}

