#pragma once

#include "Particles/Particle.h"
#include "Particles/Element.h"

// forward decl
class ParticleGrid;

ParticlePtr factoryMakeParticle(Element element, ParticleGrid& grid);

