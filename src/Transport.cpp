#include "Transport.h"

sf::Texture Transport::transTexture("assets/transport.jpg");

Transport::Transport(float x, float y, float width, float height,int towards) : towards(towards),transSprite(transTexture) {
    shape.setSize({width, height});
    shape.setPosition({x, y});

    transSprite.setPosition({x, y});
    sf::Vector2u textureSize = transTexture.getSize();
    sf::Vector2f windowSize = shape.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    transSprite.setScale(scale);
}