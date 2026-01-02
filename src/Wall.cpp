#include "Wall.h"
#include <iostream>

sf::Texture t1("assets/wall1.png");
sf::Texture t2("assets/wall2.png");
std::vector<sf::Texture> Wall::wallTextures;

Wall::Wall(float x, float y, float width, float height) : wallSprite(t1) {
    if(wallTextures.size()<2){
        wallTextures.push_back(t1);
        wallTextures.push_back(t2);
    }

    shape.setSize({width, height});
    shape.setPosition({x, y});

    wallSprite.setPosition({x, y});
    sf::Vector2u textureSize = wallTextures[0].getSize();
    sf::Vector2f windowSize = shape.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    wallSprite.setScale(scale);
}

void Wall::update(float dt) {
    elapsedTime += dt;
    if(elapsedTime >= switchTime) {
        elapsedTime = 0.f;
        currentFrame = (currentFrame + 1) % wallTextures.size();
        wallSprite.setTexture(wallTextures[currentFrame]);
    }
}
