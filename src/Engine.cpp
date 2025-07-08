#include "Engine.h"

constexpr int WORLDSIZE = 101;

constexpr sf::Vector2f DEFAULT_VIEW_CENTRE = {50.f, 25.f};
constexpr sf::Vector2f DEFAULT_VIEW_SIZE = {200.f, 200.f};


Engine::Engine(const sf::Vector2u& windowResolution, const std::string& windowName)
    : window(sf::VideoMode(windowResolution), windowName)
    , world({WORLDSIZE, WORLDSIZE})
    , view(DEFAULT_VIEW_CENTRE, DEFAULT_VIEW_SIZE)
{
    window.setFramerateLimit(60);
}

void Engine::run() {

    window.setView(view);

    // main game loop
    while (window.isOpen()) {
        // Process event queue
        while (const auto event = window.pollEvent()) {
            // Close window: exit
            if (event->is<sf::Event::Closed>()) {
                std::cout << "Quitting program...\n";
                window.close();
            }

            const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
            if (keyPressed != nullptr) {
                onKeyPressed(*keyPressed);
            }

            const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>();
            if (mousePressed != nullptr) {
                onMousePressed(*mousePressed);
            }

        }
        // process a simulation step
        world.step();

        // Clear screen
        window.clear();

        // Draw things
        window.draw(world.getGridSprite());

        // Update the window
        window.display();
    }
    
    std::cout << "Program successfully quit!\n";
}

void Engine::onMousePressed(const sf::Event::MouseButtonPressed& mousePressed) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f worldPosition = window.mapPixelToCoords(mousePosition, view);
    int wx = static_cast<int>(worldPosition.x);
    int wy = static_cast<int>(worldPosition.y);

    switch (mousePressed.button) {
        case sf::Mouse::Button::Left:
        world.SetPositionMaterial(wx, wy, Material::SAND_SOURCE);
        break;
    }
}

void Engine::onKeyPressed(const sf::Event::KeyPressed& keyPressed) {
    switch (keyPressed.code) {
        // zoom in
        case sf::Keyboard::Key::X:
        view.zoom(0.9f);
        window.setView(view);
        break;
        // zoom out
        case sf::Keyboard::Key::Z:
        view.zoom(1.1f);
        window.setView(view);
        break;
        // WASD camera movement
        case sf::Keyboard::Key::W:
        view.move({0, 3});
        window.setView(view);
        break;
        case sf::Keyboard::Key::A:
        view.move({3, 0});
        window.setView(view);
        break;
        case sf::Keyboard::Key::S:
        view.move({0, -3});
        window.setView(view);
        break;
        case sf::Keyboard::Key::D:
        view.move({-3, 0});
        window.setView(view);
        break;
        // debug step
        case sf::Keyboard::Key::K:
        world.step();
        break;



    }
}


