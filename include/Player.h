#pragma once

#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Electronic.h"
#include "Transport.h"
#include "Judgement.h"
#include "OR.h"
#include "AND.h"
#include "NOT.h"
#include "XOR.h"

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
    void control(std::vector<Wall> &walls,std::vector<Electronic> &electronics,std::vector<OR> &ors,std::vector<AND> &ands,std::vector<NOT> &nots,std::vector<XOR> &xors);
    bool touchWall(std::vector<Wall> &walls);
    bool touchElectronic(std::vector<Electronic> &electronics);
    int touchtransport(std::vector<Transport> &transports);
    Info_Judgement touchjudgement(std::vector<Judgement> &judgements);
    bool touchGate(std::vector<OR> &ors,std::vector<AND> &ands,std::vector<NOT> &nots,std::vector<XOR> &xors);
    void changeStatus();
    bool getstatus();
    sf::FloatRect getHitbox();
};