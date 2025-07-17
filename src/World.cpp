#include "World.h"

#include "Particles/SandSource.h"
#include "Particles/DebugSolid.h"
#include "Particles/Element.h"
#include "Particles/ParticleFactory.h"

#include <cstdlib>
#include <iostream>

void World::testFunction() {
    particleGrid.set({dimensions.x / 2, dimensions.y / 2}, factoryMakeParticle(Element::SAND_SOURCE, particleGrid));

    testCreateBorder();
}

void World::testCreateBorder() {
    for (int x = 0; x < dimensions.x; x++) {
        particleGrid.set({x, 0}, factoryMakeParticle(Element::DEBUG_SOLID, particleGrid));
        particleGrid.set({x, dimensions.y - 1}, factoryMakeParticle(Element::DEBUG_SOLID, particleGrid));
    }
    for (int y = 0; y < dimensions.y; y++) {
        particleGrid.set({0, y}, factoryMakeParticle(Element::DEBUG_SOLID, particleGrid));
        particleGrid.set({dimensions.x - 1, y}, factoryMakeParticle(Element::DEBUG_SOLID, particleGrid));
    }
}

World::World(const sf::Vector2u& dimensions, sf::RenderWindow& window) 
    : dimensions(dimensions)
    , window(window)
    , particleGrid(dimensions)
    , gridImage(dimensions)
    , gridSprite(gridTexture)
    , brush(0)
{
    bool success = gridTexture.loadFromImage(gridImage);
    gridSprite = sf::Sprite(gridTexture); // sprite to draw

    testFunction(); // DEBUG

    gridTexture.update(gridImage);

    render();
}

void World::render() {
    // update grid image
    sf::Vector2i position = {0, 0};
    for (position.x = 0; position.x < dimensions.x; position.x++) {
        for (position.y = 0; position.y < dimensions.y; position.y++) {
            gridImage.setPixel(static_cast<sf::Vector2u>(position), particleGrid.get(position)->color);
        }
    }
    
    // update brush overlay
    sf::Vector2i brushPosition = static_cast<sf::Vector2i>(getMouseWorldPosition());
    for (const sf::Vector2i& offset : brush.getBrushMask()) {
        if (inBounds(brushPosition + offset)) {
            gridImage.setPixel(static_cast<sf::Vector2u>(brushPosition + offset), getElementColor(brush.getSelectedElement()));
        }
    }

    // update grid texture
    gridTexture.update(gridImage);

    // grid sprite automatically gets updated when the texture gets updated
}

void World::spawn(const sf::Vector2i& position, std::shared_ptr<Particle> particle) {
    particleGrid.set(position, particle);
    gridImage.setPixel(static_cast<sf::Vector2u>(position), particle->color);

    // update grid texture
    gridTexture.update(gridImage);
}

void World::step() {
    // prepare all particles to be processed
    for (sf::Vector2i position = {0, 0}; position.y < dimensions.y; position.y++) {
        for (position.x = 0; position.x < dimensions.x; position.x++) {
            toBeProcessed.emplace_back(particleGrid.get(position));
        }
    }

    // process in random order
    while (!toBeProcessed.empty()) {
        int randIndex = std::rand() % toBeProcessed.size();
        std::swap(toBeProcessed[randIndex], toBeProcessed.back());
        
        if (auto particle = toBeProcessed.back().lock()) {
            particle->step();
        }

        toBeProcessed.pop_back();
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        brush.paint(*this);
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
        brush.paint(Element::EMPTY, *this);
    }

    render();
}
