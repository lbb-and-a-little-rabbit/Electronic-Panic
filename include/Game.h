#pragma once

#include <SFML/Graphics.hpp>
#include "Room.h"
#include "Wall.h"
#include "Electronic.h"

class Game{
    bool updated;
    int room_idx;
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    std::unique_ptr<sf::Sprite> backgroundSprite;
    std::unique_ptr<Room> currentRoom;
    std::vector<Wall> walls;
    std::vector<Electronic> electronics;

    void processEvents();
    void update();
    void render();
    void loadBackground(int idx);
    void wallrender();
    void electronicrender();

public:
    Game(unsigned w=800,unsigned int h=600);
    void run();
};