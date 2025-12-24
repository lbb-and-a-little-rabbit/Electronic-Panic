#pragma once

#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Electronic.h"
#include "Transport.h"

class Player{
    float speed = 0.1;
    sf::Vector2f pos;
    float physicalR; 
    float r;
    bool status;
    sf::CircleShape shape;
    static sf::Texture p_playerTexture;
    static sf::Texture n_playerTexture;
    sf::Sprite playerSprite; 
    friend class Game;

public:
    Player(float x,float y,float r,bool status);
    void control(std::vector<Wall> &walls,std::vector<Electronic> &electronics);
    bool touchWall(std::vector<Wall> &walls);
    bool touchElectronic(std::vector<Electronic> &electronics);
    int touchtransport(std::vector<Transport> &transports);
    void changeStatus();
    bool getstatus();
};