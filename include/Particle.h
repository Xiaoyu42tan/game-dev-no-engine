#pragma once

#include <unordered_map>

#include <SFML/Graphics.hpp>

enum class Material {    
    NONE,
    SAND,
    DEBUG_BORDER,
    DEBUG_HIGHLIGHT,
    SAND_SOURCE
};

struct Particle {
    Material material;

    // dirty means its already been updated in the simulation step 
    bool isDirty;
};

sf::Color getMaterialColor(Material material);