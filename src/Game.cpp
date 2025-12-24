#include "Game.h"
#include <optional>
#include <iostream>

std::vector<std::string> background_path={
    "assets/CPU.png",
    "assets/room1.jpg",
    "assets/room2.jpeg",
    "assets/CPU.png",
    "assets/CPU.png"
};

Game::Game(unsigned int w,unsigned int h) : player(nullptr),updated(false),room_idx(0),window(sf::VideoMode({w,h}),"Electronic Panic") {
    //set sprite
    if (!backgroundTexture.loadFromFile(background_path[room_idx])) {
        std::cerr << "Background Loading Failed!\n";
        exit(-1);
    }
    backgroundSprite=std::make_unique<sf::Sprite>(backgroundTexture);
    // 缩放铺满窗口
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    backgroundSprite->setScale(scale);

    //set rooms
    currentRoom=std::make_unique<Room>(room_idx);

    //set vector
    set_based_on_map();
    
}

void Game::vector_clear(){
    walls.clear();
    electronics.clear();
    orgates.clear();
    if(player) delete player;
    transports.clear();
}

void Game::set_based_on_map(){
    vector_clear();
    //set walls,electronics
    const float cellSize=40.0f; // 每个格子的大小
    for(int y=0;y<15;y++){
        for(int x=0;x<21;x++){
            if(currentRoom->map[y][x]=='#'){
                walls.emplace_back(x*cellSize,y*cellSize,cellSize,cellSize);
            }
            else if(currentRoom->map[y][x]=='+'){
                electronics.emplace_back(x*cellSize+cellSize/2,y*cellSize+cellSize/2,cellSize/2,true);
            }
            else if(currentRoom->map[y][x]=='-'){
                electronics.emplace_back(x*cellSize+cellSize/2,y*cellSize+cellSize/2,cellSize/2,false);
            }
            else if(currentRoom->map[y][x]=='t'){
                orgates.emplace_back(x*cellSize,y*cellSize,cellSize,cellSize);       
            }
            else if(currentRoom->map[y][x]=='B'){
                player=new Player(x*cellSize+cellSize/2,y*cellSize+cellSize/2,cellSize/2.7,true);
            }
            else if(currentRoom->map[y][x]-'0'>=0&&currentRoom->map[y][x]-'0'<MAP_CNT){
                transports.emplace_back(x*cellSize,y*cellSize,cellSize,cellSize,currentRoom->map[y][x]-'0');
            }
        }
    }
}

void Game::loadBackground(int idx) {
    if (!backgroundTexture.loadFromFile(background_path[idx])) {
        std::cerr << "Background Loading Failed!\n";
        std::exit(-1);
    }

    backgroundSprite->setTexture(backgroundTexture, true);

    sf::Vector2u ts = backgroundTexture.getSize();
    sf::Vector2u ws = window.getSize();
    sf::Vector2f scale(
        float(ws.x) / ts.x,
        float(ws.y) / ts.y
    );
    backgroundSprite->setScale(scale);
}


void Game::run(){
    while(window.isOpen()){
        processEvents();
        update();
        render();
    }
}

void Game::processEvents(){
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
    player->control(walls,electronics);
    call_update();
}

void Game::call_update(){
    int towards=player->touchtransport(transports);
    if(towards!=-1){
        updated=true;
        room_idx=towards;
    }
}

void Game::update(){
    if(!updated) return;
    updated=false;
    loadBackground(room_idx);
    currentRoom=std::make_unique<Room>(room_idx); 
    set_based_on_map();
}

void Game::render(){
    window.clear(sf::Color(50, 50, 50));
    window.draw(*backgroundSprite); 
    wallrender();
    electronicrender();
    transrender();
    gaterender();
    playerrender();
    window.display();
}

void Game::wallrender(){
    for(Wall &wall:walls) window.draw(wall.wallSprite);
}

void Game::electronicrender(){
    for(Electronic &e:electronics) window.draw(e.electronicSprite);
}

void Game::gaterender(){
    for(OR &g:orgates) window.draw(g.orSprite);
}

void Game::playerrender(){
    window.draw(player->playerSprite);
}

void Game::transrender(){
    for(Transport &t:transports) window.draw(t.transSprite);
}