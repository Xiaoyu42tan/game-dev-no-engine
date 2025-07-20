#pragma once

#include "Particles/Particle.h" // needed because we are inheriting from Particle
#include "Behaviours/SpawnsSand.h" // needed because its a member var

#include <memory>

#include <SFML/System/Vector2.hpp>

// forward decls
class ParticleGrid;

class SandSource : public Particle {
public:
    SandSource(ParticleGrid& grid);
    void step() override;
    ~SandSource() override = default;
private:
};

