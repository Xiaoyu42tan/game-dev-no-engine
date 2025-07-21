#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle
#include "Behaviours/PowderLike.h" // needed because is member variable

#include <memory>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

// forward decls
class ParticleGrid;


constexpr float ASH_ACCELERATION = 0.1f;
constexpr float ASH_MAX_VELOCITY = 0.2f;

class Ash : public Particle {
public:
    static constexpr sf::Color DEFAULT_COLOR = sf::Color(150, 150, 150); // light gray
    Ash(ParticleGrid& grid);
    void step() override;
    ~Ash() override = default;
private:
};

