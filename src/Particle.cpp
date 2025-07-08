#include "Particle.h"

sf::Color getMaterialColor(Material material) {
    switch (material) {
        case Material::NONE: return sf::Color::Transparent;
        case Material::SAND: return sf::Color(194, 178, 128);
        case Material::SAND_SOURCE: return sf::Color(255, 255, 255);
        case Material::DEBUG_HIGHLIGHT: return sf::Color(0, 255, 0);
        case Material::STONE: return sf::Color(80, 80, 80);
        default: return sf::Color::Magenta;
    }
}

