#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle

#include <SFML/System/Vector2.hpp>

// forward decls
class ParticleGrid;

class DebugSolid : public Particle {
public:
    DebugSolid(ParticleGrid& grid);
    void step() override;
    ~DebugSolid() override = default;
};

