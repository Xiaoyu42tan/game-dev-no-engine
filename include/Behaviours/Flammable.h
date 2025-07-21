#pragma once

#include "Behaviours/Behaviour.h"

#include <SFML/System/Vector2.hpp>

class Particle;

// TODO
class Flammable : public Behaviour {
public:
    Flammable(Particle& particle, float spreadChance);

    void step() override;
    
    bool ignited = false;
private:
    void renderParticleColor();
    bool shouldSpread(const sf::Vector2i& position) const;

    float spreadChance;

};


