#pragma once

#include <SFML\Graphics.hpp>
#include "Gate.h"

class NOT : public Gate{
    sf::RectangleShape shape;
    static sf::Texture notTexture;
    sf::Sprite notSprite;
    friend class Game;
    friend class Player;

public:
    NOT(float x, float y, float width, float height);
};