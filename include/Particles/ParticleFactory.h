#pragma once

#include "Particles/Particle.h"
#include "Particles/Element.h"

// forward decl
class ParticleGrid;

std::shared_ptr<Particle> factoryMakeParticle(Element element, ParticleGrid& grid);

