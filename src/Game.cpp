#include "Game.h"
#include <optional>
#include <iostream>

Game::Game(unsigned int w,unsigned int h) : window(sf::VideoMode({w,h}),"Electronic Panic") {
    if (!backgroundTexture.loadFromFile("assets/CPU.png")) {
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

}

void Game::render(){
    window.clear(sf::Color(50, 50, 50));
    window.draw(*backgroundSprite); 
    window.display();
}