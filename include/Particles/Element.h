#pragma once

#include <SFML/Graphics/Color.hpp>
#include <stdexcept>

enum class Element {
    EMPTY,
    SAND,
    DEBUG_SOLID,
    SAND_SOURCE,
    WATER,
    SMOKE,
    FIRE,
    WOOD,
    ASH,

    // make sure this is at bottom so we can cast to int to see number of elements
    NUM_ELEMENTS 
};

