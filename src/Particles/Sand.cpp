#include "Particles/Sand.h"

#include "Particles/Element.h"
#include "ParticleGrid.h"

Sand::Sand()
    : Particle(Element::SAND, getElementColor(Element::SAND))
{}

void Sand::step(const sf::Vector2i& position, ParticleGrid& grid) {
    sf::Vector2i down = {position.x, position.y + 1};
    sf::Vector2i downLeft = {position.x - 1, position.y + 1};
    sf::Vector2i downRight = {position.x + 1, position.y + 1};
    if (grid.inBounds(down) && grid.get(down)->element == Element::EMPTY) {
        grid.swap(position, down);
    } else if (grid.inBounds(downLeft) && grid.get(downLeft)->element == Element::EMPTY) {
        grid.swap(position, downLeft);
    } else if (grid.inBounds(downRight) && grid.get(downRight)->element == Element::EMPTY) {
        grid.swap(position, downRight);
    }
}


