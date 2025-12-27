#include "Source.h"

sf::Texture Source::sourceTexture("assets/source.png");

Source::Source(float x, float y, float width, float height) : sourceSprite(sourceTexture) {
    shape.setSize({width, height});
    shape.setPosition({x, y});

    sourceSprite.setPosition({x, y});
    sf::Vector2u textureSize = sourceTexture.getSize();
    sf::Vector2f windowSize = shape.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    sourceSprite.setScale(scale);
}