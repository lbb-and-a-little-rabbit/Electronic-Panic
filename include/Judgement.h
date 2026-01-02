#pragma once

#include <SFML\Graphics.hpp>

struct Info_Judgement{
    int mappos_x;
    int mappos_y;
    bool judge;

    Info_Judgement() : mappos_x(-1),mappos_y(-1),judge(false) {};
};

class Judgement{
    bool judge;
    sf::RectangleShape shape;
    static sf::Texture judgeTexture;
    sf::Sprite judgeSprite;
    int mappos_x;
    int mappos_y;
    friend class Game;
    friend class Player;

public:
    Judgement(float x, float y, float width, float height,char judge,int posx,int posy);
};