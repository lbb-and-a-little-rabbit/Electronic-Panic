#include "AND.h"

sf::Texture AND::andTexture("assets/and.png");

AND::AND(float x, float y, float width, float height) : andSprite(andTexture) {
    shape.setSize({width, height});
    shape.setPosition({x, y});

    andSprite.setPosition({x, y});
    sf::Vector2u textureSize = andTexture.getSize();
    sf::Vector2f windowSize = shape.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    andSprite.setScale(scale);
} 