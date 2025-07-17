#pragma once

#include <SFML/System/Vector2.hpp>

class ParticleGrid;
class Particle;

class Behaviour {
public:
    Behaviour(Particle& particle);

    virtual void step() = 0;

    Particle& particle;
    ParticleGrid& grid;
};