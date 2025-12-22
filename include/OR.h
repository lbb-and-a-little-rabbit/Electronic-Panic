#pragma once

#include <SFML\Graphics.hpp>
#include "Gate.h"

class OR : public Gate{
    sf::RectangleShape shape;
    static sf::Texture orTexture;
    sf::Sprite orSprite;
    friend class Game;

public:
    OR(float x, float y, float width, float height);
};