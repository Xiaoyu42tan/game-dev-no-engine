#pragma once

#include <vector>
#include <iostream>
#include <unordered_map>

#include "Particle.h"
#include "ParticleGrid.h"

class World {
public:
    World(const sf::Vector2u& dimensions);
    
    // Perform a single simulation step
    void step();

    inline sf::Sprite getGridSprite() const { return gridSprite; }
    void SetPositionMaterial(unsigned int x, unsigned int y, Material material);
    sf::Vector2u getWorldDimensions() { return dimensions; }

private:
    inline bool inBounds(unsigned int x, unsigned int y) const { return x < dimensions.x && y < dimensions.y; };

    // update the actual sprite image so our particles can be displayed onscreen
    void render();

    // play around here
    void testFunction();
    void testCreateBorder();

    // Simulation rules per Particle material.
    void stepSand(unsigned int x, unsigned int y);
    void stepSandSource(unsigned int x, unsigned int y);

    // rendering stuff
    sf::Texture gridTexture;
    sf::Sprite gridSprite;
    sf::Image gridImage;

    // grid holding particle data
    ParticleGrid particleGrid;


    sf::Vector2u dimensions;
};

