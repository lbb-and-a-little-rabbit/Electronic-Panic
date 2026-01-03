#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class Msgbox{
    static sf::Font font;
    sf::RectangleShape shape;
    static sf::Texture msgTexture;
    sf::Sprite msgSprite;
    sf::Text text;
    friend class Game;
    friend class MsgAssistant;

public:
    Msgbox(float x, float y, float width, float height);
    bool nulltext();
    void set(std::string s);
};