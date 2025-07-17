#include "Particles/Behaviours/HasGravity.h"

#include "Particles/Element.h"
#include "ParticleGrid.h"

#include "Util/StochasticRound.h"

HasGravity::HasGravity(Particle& particle, float acceleration, float maxVelocity)
    : Behaviour(particle)
    , acceleration(acceleration)
    , maxVelocity(maxVelocity)
{}

void HasGravity::step() {
    velocity += acceleration;
    if (abs(velocity) > abs(maxVelocity)) velocity = maxVelocity;

    int numSteps = std::abs(stochasticRound(velocity));
    for (int i = 0; i < numSteps; i++) {
        stepHelper();
    }
}

void HasGravity::stepHelper() {
    if (velocity == 0.f) return;

    int direction = 1;
    if (velocity < 0) direction = -1;
    
    sf::Vector2i vertical = {particle.position.x, particle.position.y + direction};
    sf::Vector2i verticalLeft = {particle.position.x - 1, particle.position.y + direction};
    sf::Vector2i verticalRight = {particle.position.x + 1, particle.position.y + direction};
        
    if (grid.inBounds(vertical) && grid.get(vertical)->element == Element::EMPTY) {
        grid.swap(particle.position, vertical);
    } else if (grid.inBounds(verticalLeft) && grid.get(verticalLeft)->element == Element::EMPTY) {
        grid.swap(particle.position, verticalLeft);
    } else if (grid.inBounds(verticalRight) && grid.get(verticalRight)->element == Element::EMPTY) {
        grid.swap(particle.position, verticalRight);
    } else {
        velocity = 0.f;
    }
}
