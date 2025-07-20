#pragma once

#include "Behaviours/Behaviour.h"

#include <SFML/System/Vector2.hpp>

class ParticleGrid;

// TODO
class Flammable : public Behaviour {
public:
    Flammable(Particle& particle);

    void step() override;
private:


};


