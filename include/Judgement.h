#pragma once

#include <SFML\Graphics.hpp>

class Judgement{
    bool judge;
    sf::RectangleShape shape;
    static sf::Texture judgeTexture;
    sf::Sprite judgeSprite;
    friend class Game;
    friend class Player;

public:
    Judgement(float x, float y, float width, float height,bool judge);
};