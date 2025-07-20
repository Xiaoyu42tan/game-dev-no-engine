#include "Behaviours/LiquidLike.h"

#include "Particles/Element.h"
#include "Particles/ParticleGrid.h"

#include "Util/StochasticRound.h"

LiquidLike::LiquidLike(Particle& particle, float acceleration, float viscosity, float density)
    : Behaviour(particle)
    , acceleration(acceleration)
    , viscosity(std::abs(viscosity))
    , density(density)
{}

void LiquidLike::step() {
    velocity += acceleration;
    if (abs(velocity) > viscosity) velocity = viscosity;

    int numSteps = std::abs(stochasticRound(velocity));
    for (int i = 0; i < numSteps; i++) {
        stepHelper();
    }
}

void LiquidLike::stepHelper() {
    if (velocity == 0.f) return;

    int direction = 1;
    if (velocity < 0) direction = -1;
    
    sf::Vector2i vertical = {particle.position.x, particle.position.y + direction};
    sf::Vector2i verticalLeft = {particle.position.x - 1, particle.position.y + direction};
    sf::Vector2i verticalRight = {particle.position.x + 1, particle.position.y + direction};
    sf::Vector2i left = {particle.position.x - 1, particle.position.y};
    sf::Vector2i right = {particle.position.x + 1, particle.position.y};

    if (canSwapWith(vertical)) {
        grid.swap(particle.position, vertical);
    } else if (canSwapWith(verticalLeft)) {
        grid.swap(particle.position, verticalLeft);
    } else if (canSwapWith(verticalRight)) {
        grid.swap(particle.position, verticalRight);
    } else if (canSwapWith(left) || canSwapWith(right)) {
        if (rand() % 2 == 0) {
            // right goes first
            if (canSwapWith(right)) {
                grid.swap(particle.position, right);
            } else if (canSwapWith(left)) {
                grid.swap(particle.position, left);
            }
        } else {
            // left goes first
            if (canSwapWith(left)) {
                grid.swap(particle.position, left);
            } else if (canSwapWith(right)) {
                grid.swap(particle.position, right);
            }
        }
    } else {
        velocity = 0.f;
    }
}

bool LiquidLike::canSwapWith(const sf::Vector2i& position) const {
    if (!grid.inBounds(position)) return false;

    auto otherParticle = grid.get(position);
    if (otherParticle->element == Element::EMPTY) return true;

    // no point in swapping
    if (otherParticle->element == particle.element) return false;

    if (otherParticle->behaviourSet.has<LiquidLike>()) {
        // chance to swap is based on how much denser we are than the other particle
        float otherDensity = otherParticle->behaviourSet.get<LiquidLike>()->density;
        if (density < otherDensity) return false;

        float diff = density - otherDensity;
        float chance = diff / (density + otherDensity);  // normalized between 0 and 1

        return static_cast<float>(std::rand()) / RAND_MAX < chance;
    }

    return false;
}