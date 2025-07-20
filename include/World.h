#pragma once

#include "Particles/ParticleGrid.h" // needed because ParticleGrid is a member var
#include "Brush.h" // needed because Brush is a member var

#include <vector>
#include <memory>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class World {
public:
    World(const sf::Vector2u& dimensions, sf::RenderWindow& window);
    
    // Perform a single simulation step
    void step();

    // for rendering
    sf::Sprite gridSprite;
    
    // grid holding particle data
    ParticleGrid particleGrid;

    // spawn a particle at a position
    void spawn(const sf::Vector2i& position, std::shared_ptr<Particle> particle);

    inline bool inBounds(const sf::Vector2i& position) const { return position.x >= 0 && position.x < dimensions.x && position.y >= 0 && position.y < dimensions.y; };

    inline sf::Vector2f getMouseWorldPosition() const { return convertWindowToWorldPosition(sf::Mouse::getPosition(window)); }

    inline sf::Vector2f convertWindowToWorldPosition(const sf::Vector2i& windowPosition) const { return window.mapPixelToCoords(windowPosition); }

    inline sf::Vector2i getLocalPosition(const sf::Vector2f& worldPosition) const {
        return {static_cast<int>(worldPosition.x - gridSprite.getPosition().x), static_cast<int>(worldPosition.y - gridSprite.getPosition().y)};
    }

    bool isPaused = false;

private:
    // update the actual sprite image so our particles can be displayed onscreen
    void render();

    // play around here
    void testFunction();
    void testCreateBorder();

    // paint brush
    Brush brush;

    // rendering stuff
    sf::Texture gridTexture;
    sf::Image gridImage;

    sf::RenderWindow& window;

    sf::Vector2i dimensions;

    /*
    We insert particles into toBeProcessed when we call step(). Particles are processed in a randomised order.

    We use weak_ptr here because some particle behaviours may delete/replace OTHER particles when we process their simulation steps.
        - this means the deleted/replaced particle no longer exists. We need to use a non-owning weak_ptr to only simulate a particle if it still exists.
        - EXAMPLE: SandSource replaces the space below it with a Sand particle. We can no longer call step() on the particle that was previously below the SandSource.
    */
    std::vector<std::weak_ptr<Particle>> toBeProcessed;
};

