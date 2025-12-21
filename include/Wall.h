#pragma once

#include <SFML/Graphics.hpp>

class Wall {
    sf::RectangleShape shape;
    static sf::Texture wallTexture;
    sf::Sprite wallSprite;
    friend class Game;

public:
    Wall(float x, float y, float width, float height);
};