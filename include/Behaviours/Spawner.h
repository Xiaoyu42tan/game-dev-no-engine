#pragma once

#include "Behaviours/Behaviour.h"
#include "Particles/Element.h"

#include <SFML/System/Vector2.hpp>

class Particle;

class Spawner : public Behaviour {
public:
    Spawner(Particle& particle, Element element, sf::Vector2i offset);

    void step() override;
private:
    Element element;
    sf::Vector2i offset;
};
