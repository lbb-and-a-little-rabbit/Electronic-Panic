#pragma once

#include <SFML/Graphics.hpp>
#include "Room.h"
#include "Wall.h"
#include "Electronic.h"
#include "OR.h"
#include "AND.h"
#include "NOT.h"
#include "XOR.h"
#include "Player.h"

class Game{
    bool updated;
    int room_idx;
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    std::unique_ptr<sf::Sprite> backgroundSprite;
    std::unique_ptr<Room> currentRoom;
    Player* player;
    std::vector<Wall> walls;
    std::vector<Electronic> electronics;
    std::vector<OR> orgates;


    void processEvents();
    void update();
    void render();
    void loadBackground(int idx);
    void wallrender();
    void electronicrender();
    void gaterender();
    void playerrender();

public:
    Game(unsigned w=800,unsigned int h=600);
    void run();
};