#include "Particles/ParticleFactory.h"

#include "Particles/ParticleGrid.h"
#include "Particles/DebugSolid.h"
#include "Particles/Empty.h"
#include "Particles/Sand.h"
#include "Particles/SandSource.h"
#include "Particles/Water.h"
#include "Particles/Smoke.h"
#include "Particles/Fire.h"
#include "Particles/Wood.h"
#include "Particles/Ash.h"

#include <memory>
#include <stdexcept>

std::shared_ptr<Particle> factoryMakeParticle(Element element, ParticleGrid& grid) {
    switch (element) {
        case Element::EMPTY:            return std::make_shared<Empty>(grid);
        case Element::SAND:             return std::make_shared<Sand>(grid);
        case Element::DEBUG_SOLID:      return std::make_shared<DebugSolid>(grid);
        case Element::SAND_SOURCE:      return std::make_shared<SandSource>(grid);
        case Element::WATER:            return std::make_shared<Water>(grid);
        case Element::SMOKE:            return std::make_shared<Smoke>(grid);
        case Element::FIRE:             return std::make_shared<Fire>(grid);
        case Element::WOOD:             return std::make_shared<Wood>(grid);
        case Element::ASH:             return std::make_shared<Ash>(grid);
    }

    throw std::runtime_error("ERROR factoryMakeParticle() : element does not exist!");
}

sf::Color factoryGetColor(Element element) {
    switch (element) {
        case Element::EMPTY:            return Empty::DEFAULT_COLOR;
        case Element::SAND:             return Sand::DEFAULT_COLOR;
        case Element::DEBUG_SOLID:      return DebugSolid::DEFAULT_COLOR;
        case Element::SAND_SOURCE:      return SandSource::DEFAULT_COLOR;
        case Element::WATER:            return Water::DEFAULT_COLOR;
        case Element::SMOKE:            return Smoke::DEFAULT_COLOR;
        case Element::FIRE:             return Fire::DEFAULT_COLOR;
        case Element::WOOD:             return Wood::DEFAULT_COLOR;
        case Element::ASH:             return Ash::DEFAULT_COLOR;
    }

    throw std::runtime_error("ERROR factoryGetColor() : element color not defined!");
}
