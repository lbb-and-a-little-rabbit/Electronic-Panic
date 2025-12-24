#pragma once

#include <SFML/Graphics.hpp>

class Transport{
    int towards;
    sf::RectangleShape shape;
    static sf::Texture transTexture;
    sf::Sprite transSprite;
    friend class Game;
    friend class Player;

public:
    Transport(float x, float y, float width, float height,int towards);
};