#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
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
#include "Source.h"
#include "Msgbox.h"
#include "MsgAssistant.h"

class Game{
    //Size and View
    float WORLD_WIDTH  = 800.f;
    float WORLD_HEIGHT = 600.f;
    sf::View worldView;

    //Time
    sf::Clock frameClock;
    sf::Time dt;
    float delta;
    int frameCount=0;
    float fps=0.f;
    float elapsed=0.f;

    //Status
    bool updated;
    int room_idx;
    bool idx_change=true;
    bool player_status;
    int unfixed_gates=0;

    //Window
    Msgbox msgbox;
    MsgAssistant msgassistant;
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    std::unique_ptr<sf::Sprite> backgroundSprite;
    sf::Music currentMusic;
    bool music_change=true;
    sf::Music acoustics;
    std::unique_ptr<Room> currentRoom;

    //Main Elements
    Player* player;
    std::vector<Judgement> judgements;
    std::vector<Transport> transports;
    std::vector<Wall> walls;
    std::vector<Electronic> electronics;
    std::vector<OR> orgates;
    std::vector<AND> andgates;
    std::vector<NOT> notgates;
    std::vector<XOR> xorgates;
    std::vector<Source> sources;

    //Function

    //Time
    void Frame();

    void resizeBackground();
    void set_based_on_map();
    void vector_clear();
    void setAcoustics(std::string s);
    void processEvents();
    void call_update();
    void update();
    bool call_Press(sf::Keyboard::Key key);
    void render();
    void loadBackground(int idx);
    void wallrender();
    void electronicrender();
    void gaterender();
    void playerrender();
    void transrender();
    void judgementrender();
    void sourcerender();
    void msgboxrender();

public:
    Game(unsigned w=800,unsigned int h=600);
    void run();
};