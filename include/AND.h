#pragma once

#include <SFML\Graphics.hpp>
#include "Gate.h"

class AND : public Gate{
    sf::RectangleShape shape;
    static sf::Texture andTexture;
    sf::Sprite andSprite;
    friend class Game;
    friend class Player;

public:
    AND(float x, float y, float width, float height);
};