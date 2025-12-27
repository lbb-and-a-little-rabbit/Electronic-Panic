#include "NOT.h"

sf::Texture NOT::notTexture("assets/not.png");

NOT::NOT(float x, float y, float width, float height) : notSprite(notTexture) {
    shape.setSize({width, height});
    shape.setPosition({x, y});

    notSprite.setPosition({x, y});
    sf::Vector2u textureSize = notTexture.getSize();
    sf::Vector2f windowSize = shape.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    notSprite.setScale(scale);
} 