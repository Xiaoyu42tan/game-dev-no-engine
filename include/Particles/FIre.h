#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle

#include <optional>

#include <SFML/System/Vector2.hpp>

constexpr unsigned int FIRE_DEFAULT_LIFETIME = 30;
constexpr unsigned int FIRE_LIFETIME_VARIANCE = static_cast<unsigned int>(static_cast<float>(FIRE_DEFAULT_LIFETIME) / 10);

constexpr Element FIRE_TURNS_INTO = Element::SMOKE;
constexpr float FIRE_TURNS_INTO_CHANCE = 0.05f;

class Fire : public Particle {
public:
    static constexpr sf::Color DEFAULT_COLOR = sf::Color(255, 165, 0); // orange

    Fire(ParticleGrid& grid, unsigned int lifetime = FIRE_DEFAULT_LIFETIME, std::optional<unsigned int> timeLeft = std::nullopt);
    void step() override;
    ~Fire() override = default;
private:
    bool canSpread(const sf::Vector2i& position, int newLifetime) const;
    bool shouldIgnite(const sf::Vector2i& position) const;

    int upLifetimeDissipation() const;
    int downLifetimeDissipation() const;
    int horizontalLifetimeDissipation() const;
};
