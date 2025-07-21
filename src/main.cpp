#include "Engine.h"
#include "Particles/Particle.h"

#include <iostream>

int main() {
    {
        Engine engine({1920 / 2, 1080 / 2}, "Some name for the window");
        engine.run();
    }

    // Naive way to check for memory leak
    std::cout << "Particles created: " << Particle::numCreated << ", Particles deleted: " << Particle::numDeleted << "\n";
    assert(Particle::numCreated == Particle::numDeleted);
}

