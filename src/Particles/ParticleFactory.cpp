#include "Particles/ParticleFactory.h"

#include "Particles/DebugSolid.h"
#include "Particles/Empty.h"
#include "Particles/Sand.h"
#include "Particles/SandSource.h"

#include <memory>
#include <stdexcept>

ParticlePtr factoryMakeParticle(Element element) {
    switch (element) {
        case Element::DEBUG_SOLID:
        return std::make_shared<DebugSolid>();
        break;
        
        case Element::EMPTY:
        return std::make_shared<Empty>();
        break;

        case Element::SAND:
        return std::make_shared<Sand>();
        break;

        case Element::SAND_SOURCE:
        return std::make_shared<SandSource>();
        break;
    }

    throw std::runtime_error("ERROR factoryMakeParticle() : element does not exist!");
}
