#include "OR.h"

sf::Texture OR::orTexture("assets/or.png");

OR::OR(float x, float y, float width, float height) : orSprite(orTexture) {
    shape.setSize({width, height});
    shape.setPosition({x, y});

    orSprite.setPosition({x, y});
    sf::Vector2u textureSize = orTexture.getSize();
    sf::Vector2f windowSize = shape.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    orSprite.setScale(scale);
}   