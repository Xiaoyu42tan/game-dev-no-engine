#pragma once

#include <SFML/Graphics/Color.hpp>
#include <stdexcept>

enum class Element {
    EMPTY,
    SAND,
    DEBUG_SOLID,
    SAND_SOURCE,


    // make sure this is at bottom so we can cast to int to see number of elements
    NUM_ELEMENTS 
};

inline sf::Color getElementColor(Element element) {
    switch (element) {
        case Element::EMPTY:        return sf::Color::Transparent;
        case Element::SAND:         return sf::Color(194, 178, 128); // a sand-like tan
        case Element::DEBUG_SOLID:  return sf::Color::Magenta;
        case Element::SAND_SOURCE:  return sf::Color::White;
    }

    throw std::runtime_error("ERROR getElementColor() : element color not defined!");
}


