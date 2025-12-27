#include "XOR.h"

sf::Texture XOR::xorTexture("assets/xor.png");

XOR::XOR(float x, float y, float width, float height) : xorSprite(xorTexture) {
    shape.setSize({width, height});
    shape.setPosition({x, y});

    xorSprite.setPosition({x, y});
    sf::Vector2u textureSize = xorTexture.getSize();
    sf::Vector2f windowSize = shape.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    xorSprite.setScale(scale);
} 