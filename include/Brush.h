#pragma once

#include "Events/EventListener.h" // needed bc is member var
#include "Particles/Element.h" // needed bc is member var
#include "Util/Hashes.h" // needed for hash

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>

#include <unordered_set>

// forward decls
class World;

class Brush {
public:
    Brush(unsigned int radius);

    void onEvent(const sf::Event& event);

    void onKeyPressed(const sf::Event::KeyPressed& event);

    // paint an element onto world
    void paint(Element element, World& world);

    // default to painting the currently selected element
    void paint(World& world);
    
    inline void nextElement() { selectedElement = static_cast<Element>((static_cast<int>(selectedElement) + 1) % (static_cast<int>(Element::NUM_ELEMENTS))); }

    inline unsigned int getRadius() const { return radius; }

    void setRadius(unsigned int newRadius);

    inline std::unordered_set<sf::Vector2i, Vector2iHash> getBrushMask() const { return brushMask; }

    inline Element getSelectedElement() const { return selectedElement; }
private:
    // has all coordinates of where particles will be spawn upon the next time we paint
    std::unordered_set<sf::Vector2i, Vector2iHash> brushMask;

    unsigned int radius = 1;
    EventListener eventListener;

    Element selectedElement = Element::SAND;
};