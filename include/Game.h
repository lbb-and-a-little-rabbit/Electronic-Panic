#pragma once

#include <SFML\Graphics.hpp>

class Game{
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    std::unique_ptr<sf::Sprite> backgroundSprite;

    void processEvents();
    void update();
    void render();

public:
    Game(unsigned w=800,unsigned int h=600);
    void run();
};