#include "Wall.h"
#include <iostream>

sf::Texture Wall::wallTexture("assets/wall.png");

Wall::Wall(float x, float y, float width, float height) : wallSprite(wallTexture) {
    shape.setSize({width, height});
    shape.setPosition({x, y});

    wallSprite.setPosition({x, y});
    sf::Vector2u textureSize = wallTexture.getSize();
    sf::Vector2f windowSize = shape.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    wallSprite.setScale(scale);
}
