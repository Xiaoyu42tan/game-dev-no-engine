#include "Particles/ParticleFactory.h"

#include "Particles/DebugSolid.h"
#include "Particles/Empty.h"
#include "Particles/Sand.h"
#include "Particles/SandSource.h"
#include "Particles/Water.h"
#include "Particles/ParticleGrid.h"

#include <memory>
#include <stdexcept>

std::shared_ptr<Particle> factoryMakeParticle(Element element, ParticleGrid& grid) {
    switch (element) {
        case Element::DEBUG_SOLID:
        return std::make_shared<DebugSolid>(grid);
        break;
        
        case Element::EMPTY:
        return std::make_shared<Empty>(grid);
        break;

        case Element::SAND:
        return std::make_shared<Sand>(grid);
        break;

        case Element::SAND_SOURCE:
        return std::make_shared<SandSource>(grid);
        break;

        case Element::WATER:
        return std::make_shared<Water>(grid);
        break;
    }

    throw std::runtime_error("ERROR factoryMakeParticle() : element does not exist!");
}
