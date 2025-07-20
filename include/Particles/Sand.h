#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle
#include "Behaviours/PowderLike.h" // needed because is member variable

#include <memory>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

// forward decls
class ParticleGrid;

constexpr float SAND_ACCELERATION = 0.3f;
constexpr float SAND_MAX_VELOCITY = 3.f;

class Sand : public Particle {
public:
    Sand(ParticleGrid& grid);
    void step() override;
    ~Sand() override = default;
private:
};

