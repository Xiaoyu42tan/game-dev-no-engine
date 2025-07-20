#include "Behaviours/Behaviour.h"

#include "Particles/Particle.h"
#include "Particles/ParticleGrid.h"

Behaviour::Behaviour(Particle& particle)
    : particle(particle)
    , grid(particle.grid)
{}