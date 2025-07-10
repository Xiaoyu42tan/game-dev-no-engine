#include <cstdlib>
#include <cmath>
#include <cassert>

/*
turns float into integer stochastically. only works for positive numbers

EXAMPLE: stochasticRound(3.14) = 3 + "14% chance of 1"
*/
unsigned int stochasticRound(float value) {
    assert(value >= 0);

    unsigned int base = static_cast<unsigned int>(std::floor(value));
    float fraction = value - base;

    // Generate a random float between 0 and 1
    float r = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);

    return base + (r < fraction ? 1 : 0);
}


