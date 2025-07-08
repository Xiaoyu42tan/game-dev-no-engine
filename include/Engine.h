#pragma once

#include "World.h" // needed because we declare world by value
#include "Events/EventListener.h" // needed because event listener is a member var

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

class Engine {
public:
    Engine(const sf::Vector2u& windowResolution, const std::string& windowName);

    void run();

private:
    void render();

    void onEvent(const sf::Event& event);
    
    void onKeyPressed(const sf::Event::KeyPressed& keyPressed);

    void onWindowClosed();

    void onWindowResize(const sf::Event::Resized& resized);

    void onMouseButtonPressed(const sf::Event::MouseButtonPressed& mouseButtonPressed);

    void onMouseWheelScrolled(const sf::Event::MouseWheelScrolled& mouseWheelScrolled);

    sf::RenderWindow window;
    sf::View view;

    World world;

    EventListener eventListener;
};
