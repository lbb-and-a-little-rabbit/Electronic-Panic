#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Room.h"
#include "Wall.h"
#include "Electronic.h"
#include "OR.h"
#include "AND.h"
#include "NOT.h"
#include "XOR.h"
#include "Player.h"
#include "Transport.h"
#include "Judgement.h"

class Game{
    bool updated;
    int room_idx;
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    std::unique_ptr<sf::Sprite> backgroundSprite;
    sf::Music currentMusic;
    std::unique_ptr<Room> currentRoom;
    Player* player;
    std::vector<Judgement> judgements;
    std::vector<Transport> transports;
    std::vector<Wall> walls;
    std::vector<Electronic> electronics;
    std::vector<OR> orgates;
    std::vector<AND> andgates;
    std::vector<NOT> notgates;
    std::vector<XOR> xorgates;

    void set_based_on_map();
    void vector_clear();
    void processEvents();
    void call_update();
    void update();
    void render();
    void loadBackground(int idx);
    void wallrender();
    void electronicrender();
    void gaterender();
    void playerrender();
    void transrender();
    void judgementrender();

public:
    Game(unsigned w=800,unsigned int h=600);
    void run();
};