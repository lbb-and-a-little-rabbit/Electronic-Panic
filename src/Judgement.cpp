#include "Judgement.h"

sf::Texture Judgement::judgeTexture("assets/judgement.jpg");

Judgement::Judgement(float x, float y, float width, float height,bool judge) : judge(judge=='*'),judgeSprite(judgeTexture) {
    shape.setSize({width, height});
    shape.setPosition({x, y});

    judgeSprite.setPosition({x, y});
    sf::Vector2u textureSize = judgeTexture.getSize();
    sf::Vector2f windowSize = shape.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    judgeSprite.setScale(scale);
}