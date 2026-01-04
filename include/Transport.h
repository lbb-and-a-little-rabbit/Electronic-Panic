#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

struct Info_Transport{
    int towards;
    int posx;
    int posy;

    Info_Transport() : towards(-1),posx(-1),posy(-1) {};
};

class Transport{
    //Time
    float elapsedTime = 0.f;
    int currentFrame = 0;
    const float switchTime = 0.75f; // 每 0.75 秒切换一次

    int towards;
    int mappos_x;
    int mappos_y;
    sf::RectangleShape shape;
    static std::vector<sf::Texture> transTexture;
    sf::Sprite transSprite;
    friend class Game;
    friend class Player;

public:
    Transport(float x, float y, float width, float height,int towards,int posx,int posy);
    void update(float dt);
};