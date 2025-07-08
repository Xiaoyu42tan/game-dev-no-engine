#include "Engine.h"

#include "Particles/Sand.h"
#include "Particles/Element.h"
#include "Particles/ParticleFactory.h"
#include "Events/EventDispatcher.h"

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <iostream>
#include <cmath>

constexpr int WORLDSIZE = 101;

constexpr sf::Vector2f DEFAULT_VIEW_CENTRE = {50.f, 50.f};
constexpr sf::Vector2f DEFAULT_VIEW_SIZE = {1920.f / 8.f, 1080.f / 8.f};

Engine::Engine(const sf::Vector2u& windowResolution, const std::string& windowName)
    : window(sf::VideoMode(windowResolution), windowName)
    , view(DEFAULT_VIEW_CENTRE, DEFAULT_VIEW_SIZE)
    , world({WORLDSIZE, WORLDSIZE}, window)
    , eventListener([this](const sf::Event& e) -> void { onEvent(e); })
{
    window.setFramerateLimit(60);
    window.setView(view);
}

void Engine::run() {
    // main game loop
    while (window.isOpen()) {
        // dispatch events
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::MouseMovedRaw>()) continue; // this is premature optimisation lol

            EventDispatcher::getInstance().notify(*event);
        }

        // process a simulation step
        if (!world.isPaused) world.step();

        // render
        render();
    }
    
    std::cout << "Program successfully quit!\n";
}

void Engine::render() {


    // Clear screen
    window.clear();

    // Draw things
    window.draw(world.gridSprite);

    // Update the window
    window.display();
}

void Engine::onEvent(const sf::Event& event) {
    // Close window: exit
    if (event.is<sf::Event::Closed>()) {
        onWindowClosed();
    }
    // Keyboard input
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        onKeyPressed(*keyPressed);
    }
    // Window resize
    if (const auto* resized = event.getIf<sf::Event::Resized>()) {
        onWindowResize(*resized);
    }
    // Mouse button pressed
    if (const auto* mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        onMouseButtonPressed(*mouseButtonPressed);
    }
    // Mouse wheel scrolled
    if (const auto* mouseWheelScrolled = event.getIf<sf::Event::MouseWheelScrolled>()) {
        onMouseWheelScrolled(*mouseWheelScrolled);
    }
}

void Engine::onKeyPressed(const sf::Event::KeyPressed& keyPressed) {
    switch (keyPressed.code) {
        // WASD camera movement
        case sf::Keyboard::Key::W:
        view.move({0, -3});
        window.setView(view);
        break;
        case sf::Keyboard::Key::A:
        view.move({-3, 0});
        window.setView(view);
        break;
        case sf::Keyboard::Key::S:
        view.move({0, 3});
        window.setView(view);
        break;
        case sf::Keyboard::Key::D:
        view.move({3, 0});
        window.setView(view);
        break;

        // debug
        case sf::Keyboard::Key::Space:
        world.isPaused = !world.isPaused;
        break;
    }
}

void Engine::onWindowClosed() {
    std::cout << "Quitting program...\n";
    window.close();
}

void Engine::onWindowResize(const sf::Event::Resized& resized) {
    // Maintain aspect ratio
    float windowRatio = static_cast<float>(resized.size.x) / static_cast<float>(resized.size.y);
    float viewRatio = view.getSize().x / view.getSize().y;

    float width = 1.f;
    float height = 1.f;

    if (windowRatio > viewRatio) {
        width = viewRatio / windowRatio;
    } else {
        height = windowRatio / viewRatio;
    }
    view.setViewport(sf::FloatRect({(1 - width) / 2, (1 - height) / 2}, {width, height}));

    window.setView(view);
}

void Engine::onMouseButtonPressed(const sf::Event::MouseButtonPressed& mouseButtonPressed) {
    switch (mouseButtonPressed.button) {
        // do something
    }
}

void Engine::onMouseWheelScrolled(const sf::Event::MouseWheelScrolled& mouseWheelScrolled) {
    switch (mouseWheelScrolled.wheel) {
        case sf::Mouse::Wheel::Vertical:
        // zoom in
        if (mouseWheelScrolled.delta > 0) {
            view.zoom(0.9f);
            window.setView(view);
        }
        // zoom out
        else {
            view.zoom(1.1f);
            window.setView(view);
        }
        break;
    }
}

