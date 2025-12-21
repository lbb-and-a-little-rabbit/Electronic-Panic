#include "Game.h"
#include <optional>

Game::Game(unsigned int w,unsigned int h) : window(sf::VideoMode({w,h}),"Electronic Panic") {}

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
    window.display();
}