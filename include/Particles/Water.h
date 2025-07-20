#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle
#include "Behaviours/LiquidLike.h" // needed because is member variable

#include <memory>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

// forward decls
class ParticleGrid;

constexpr float WATER_ACCELERATION = 2.0f;
constexpr float WATER_VISCOSITY = 3.5f;
constexpr float WATER_DENSITY = 1.f;

class Water : public Particle {
public:
    Water(ParticleGrid& grid);
    void step() override;
    ~Water() override = default;
private:
};

