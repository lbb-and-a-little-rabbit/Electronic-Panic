#pragma once

#include <SFML\Graphics.hpp>
#include "Gate.h"

class XOR : public Gate{
    sf::RectangleShape shape;
    static sf::Texture xorTexture;
    sf::Sprite xorSprite;
    friend class Game;
    friend class Player;

public:
    XOR(float x, float y, float width, float height);
};