#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>

#include "World.h"


class Engine {
public:
    Engine(const sf::Vector2u& windowResolution, const std::string& windowName);

    void run();

private:
    void onKeyPressed(const sf::Event::KeyPressed& keyPressed);
    void onMouseButton(const sf::Mouse::Button& buttonHeld);

    sf::RenderWindow window;
    sf::View view;

    Material selectedMaterial;
    World world;
};
