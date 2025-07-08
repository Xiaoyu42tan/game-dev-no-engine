#include "Brush.h"

#include "World.h"
#include "Particles/ParticleFactory.h"

#include <queue>
#include <array>
#include <iostream>

Brush::Brush(unsigned int radius)
    : radius(radius)
    , eventListener([this](const sf::Event& e) -> void { onEvent(e); })
{
    setRadius(radius);
}

void Brush::onEvent(const sf::Event& event) {
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        onKeyPressed(*keyPressed);
    }
}

void Brush::onKeyPressed(const sf::Event::KeyPressed& event) {
    switch (event.code) {
        // change brush size
        case sf::Keyboard::Key::Period:
        setRadius(getRadius() + 1);
        break;
        case sf::Keyboard::Key::Comma:
        if (getRadius() != 0) {
            setRadius(getRadius() - 1);
        }
        break;
    }
}

void Brush::paint(Element element, World& world) {
    sf::Vector2i position = static_cast<sf::Vector2i>(world.getMouseWorldPosition());

    for (const sf::Vector2i& offset : brushMask) {
        if (world.inBounds(position + offset)) {
            /*
            ISSUE: allocating heap one by one for each individual shared_ptr is slow. unfortunately cpp doesnt have a bulk make_shared.

            TODO: make custom bulk make_shared. the idea is that you specify you want N new instances of something. then this class returns that in a vector.
                  the API might looks something like `std::vector<ParticlePtr> sandParticles = bulk_make_shared<Sand>(20)`

            basically this is faster because heap allocating B bytes N times is much slower than heap allocating B * N bytes just 1 time.
            it would probably be clean to make our own shared_ptr at this point too.
            */
            world.spawn(position + offset, factoryMakeParticle(element));
        }
    }
}

void Brush::paint(World& world) {
    paint(selectedElement, world);
}

void Brush::setRadius(unsigned int newRadius) {
    radius = newRadius;

    brushMask.clear();
    
    // BFS
    std::queue<sf::Vector2i> bfsQueue;
    bfsQueue.push({0, 0});

    static constexpr std::array<sf::Vector2i, 4> directions = {
        sf::Vector2i(1, 0),
        sf::Vector2i(-1, 0),
        sf::Vector2i(0, 1),
        sf::Vector2i(0, -1)
    };

    while (!bfsQueue.empty()) {
        auto position = bfsQueue.front(); bfsQueue.pop();

        // skip if already visited
        if (brushMask.find(position) != brushMask.end()) continue;

        // only insert if within circle
        if (position.x * position.x + position.y * position.y > static_cast<int>(radius * radius)) continue;

        brushMask.insert(position);

        for (const auto& dir : directions) {
            auto newPosition = dir + position;
            bfsQueue.push(newPosition);
        }
    }
}


