#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Electronic{
    //Time
    //Time
    float elapsedTime = 0.f;
    int currentFrame = 0;
    const float switchTime = 0.25f; // 每 0.25 秒切换一次

    bool positive;
    sf::CircleShape shape;
    static std::vector<sf::Texture> positive_electronicTexture;
    static std::vector<sf::Texture> negative_electronicTexture;
    sf::Sprite electronicSprite;
    friend class Game;
    friend class Player;

public:
    Electronic(float x,float y,float r,bool positive);
    void update(float dt);
};