#pragma once

#include <SFML\Graphics.hpp>

class Source{
    sf::RectangleShape shape;
    static sf::Texture sourceTexture;
    sf::Sprite sourceSprite;
    friend class Game;

public:
    Source(float x, float y, float width, float height);
};