#include "Transport.h"

sf::Texture trans1("assets/transport1.jpg");
sf::Texture trans2("assets/transport2.png");
std::vector<sf::Texture> Transport::transTexture;

Transport::Transport(float x, float y, float width, float height,int towards,int posx,int posy) : mappos_x(posx),mappos_y(posy),towards(towards),transSprite(trans1) {
    if(transTexture.size()<2){
        transTexture.push_back(trans1);
        transTexture.push_back(trans2);
    }

    shape.setSize({width, height});
    shape.setPosition({x, y});

    transSprite.setPosition({x, y});
    sf::Vector2u textureSize = transTexture[0].getSize();
    sf::Vector2f windowSize = shape.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    transSprite.setScale(scale);
}

void Transport::update(float dt){
    elapsedTime += dt;
    if(elapsedTime >= switchTime) {
        elapsedTime = 0.f;
        currentFrame = (currentFrame + 1) % transTexture.size();
        transSprite.setTexture(transTexture[currentFrame]);
    }
}