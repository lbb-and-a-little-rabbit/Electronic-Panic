#include "Game.h"
#include <optional>
#include <iostream>

std::vector<std::string> background_path={
    "assets/CPU.png",
    "assets/CPU.png"
};

Game::Game(unsigned int w,unsigned int h) : updated(false),room_idx(1),window(sf::VideoMode({w,h}),"Electronic Panic") {
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
}

void Game::update(){
    if(!updated) return;
    updated=false;
    loadBackground(room_idx);
    currentRoom=std::make_unique<Room>(room_idx); 
}

void Game::render(){
    window.clear(sf::Color(50, 50, 50));
    window.draw(*backgroundSprite); 
    wallrender();
    electronicrender();
    gaterender();
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