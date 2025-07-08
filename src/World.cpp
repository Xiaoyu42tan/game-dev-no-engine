#include "World.h"

void World::testFunction() {
    particleGrid.set(dimensions.x / 2, dimensions.y / 2, Material::SAND_SOURCE);

    testCreateBorder();
}

void World::testCreateBorder() {
    for (int x = 0; x < dimensions.x; x++) {
        particleGrid.set(x, 0, Material::DEBUG_BORDER);
        particleGrid.set(x, dimensions.y - 1, Material::DEBUG_BORDER);
    }
    for (int y = 0; y < dimensions.y; y++) {
        particleGrid.set(0, y, Material::DEBUG_BORDER);
        particleGrid.set(dimensions.x - 1, y, Material::DEBUG_BORDER);
    }
}

void World::SetPositionMaterial(unsigned int x, unsigned int y, Material material) {
    if(x > dimensions.x || y > dimensions.y)
        return;
    particleGrid.set(x, y, material);
}

World::World(const sf::Vector2u& dimensions) 
    : dimensions(dimensions)
    , particleGrid(dimensions)
    , gridImage(dimensions)
    , gridSprite(gridTexture)
{
    bool success = gridTexture.loadFromImage(gridImage);
    gridSprite = sf::Sprite(gridTexture); // sprite to draw

    // testFunction(); // DEBUG

    gridTexture.update(gridImage);

    render();
}

void World::render() {
    // update grid image
    for (unsigned int x = 0; x < dimensions.x; x++)
        for (unsigned int y = 0; y < dimensions.y; y++)
            gridImage.setPixel({x, y}, getMaterialColor(particleGrid.get(x, y).material));
    
    // update grid texture
    gridTexture.update(gridImage);

    // grid sprite automatically gets updated when the texture gets updated
}

void World::step() {
    particleGrid.resetDirty();

    for (unsigned int y = 0; y < dimensions.y; y++) {
        for (unsigned int x = 0; x < dimensions.x; x++) {
            // do not step the particle if its dirty
            if (particleGrid.get(x, y).isDirty) continue;

            switch (particleGrid.get(x, y).material) {
                case Material::NONE:
                    break;
                case Material::SAND:
                    stepSand(x, y);
                    break;
                case Material::SAND_SOURCE:
                    stepSandSource(x, y);
                    break;
                case Material::WATER:
                    stepWater(x, y);
                    break;
            }
        }
    }

    render();
}

void World::stepSand(unsigned int x, unsigned int y) {
    // down
    if (inBounds(x, y + 1) && particleGrid.get(x, y + 1).material == Material::NONE) {
        particleGrid.set(x, y, Material::NONE);
        particleGrid.set(x, y + 1, Material::SAND);
    }
    // down left
    else if (inBounds(x - 1, y + 1) && particleGrid.get(x - 1, y + 1).material == Material::NONE) {
        particleGrid.set(x, y, Material::NONE);
        particleGrid.set(x - 1, y + 1, Material::SAND);
    }
    // down right
    else if (inBounds(x + 1, y + 1) && particleGrid.get(x + 1, y + 1).material == Material::NONE) {
        particleGrid.set(x, y, Material::NONE);
        particleGrid.set(x + 1, y + 1, Material::SAND);
    }
}

void World::stepWater(unsigned int x, unsigned int y) {
    float rng = static_cast<float>(rand())/RAND_MAX;

    // down
    if (inBounds(x, y + 1) && particleGrid.get(x, y + 1).material == Material::NONE) {
        particleGrid.set(x, y, Material::NONE);
        particleGrid.set(x, y + 1, Material::WATER);
    } else if(rng > 0.5) {
        // left
        if (inBounds(x - 1, y) && particleGrid.get(x - 1, y).material == Material::NONE) {
            particleGrid.set(x, y, Material::NONE);
            particleGrid.set(x - 1, y, Material::WATER);
        }
        //right
        else if (inBounds(x + 1, y) && particleGrid.get(x + 1, y).material == Material::NONE) {
            particleGrid.set(x, y, Material::NONE);
            particleGrid.set(x + 1, y, Material::WATER);
        }
    } else {
        //right
        if (inBounds(x + 1, y) && particleGrid.get(x + 1, y).material == Material::NONE) {
            particleGrid.set(x, y, Material::NONE);
            particleGrid.set(x + 1, y, Material::WATER);
        }
        // left
        else if (inBounds(x - 1, y) && particleGrid.get(x - 1, y).material == Material::NONE) {
            particleGrid.set(x, y, Material::NONE);
            particleGrid.set(x - 1, y, Material::WATER);
        }
    }
}

void World::stepSandSource(unsigned int x, unsigned int y) {
    // spawn sand below if possible
    if (inBounds(x, y + 1) && particleGrid.get(x, y + 1).material == Material::NONE) {
        particleGrid.set(x, y + 1, Material::SAND);
    }
}
