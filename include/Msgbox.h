#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class Msgbox{
    //Time
    sf::Clock textclock;
    float displayTime=0.f;
    bool clocking=false;

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
    void settime(std::string s,float time);
    void update();
};