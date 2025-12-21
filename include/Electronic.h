#pragma once

#include <SFML/Graphics.hpp>

class Electronic{
    bool positive;
    sf::CircleShape shape;
    static sf::Texture positive_electronicTexture;
    static sf::Texture negative_electronicTexture;
    sf::Sprite electronicSprite;
    friend class Game;

public:
    Electronic(float x,float y,float r,bool positive);
};