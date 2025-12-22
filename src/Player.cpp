#include "Player.h"

sf::Texture Player::p_playerTexture("assets/player_positive.png");
sf::Texture Player::n_playerTexture("assets/player_negative.png");

Player::Player(float x,float y,float r,bool status) : x(x),y(y),r(r),status(status),playerSprite(status?p_playerTexture:n_playerTexture) {
    // 设置位置和缩放（r 为半径/大小）
    sf::Vector2u ts = playerSprite.getTexture().getSize();
    // 缩放成直径 2*r
    playerSprite.setScale(sf::Vector2f((2*r)/ts.x, (2*r)/ts.y));
    // 设置中心原点
    playerSprite.setOrigin(sf::Vector2f(ts.x/2.f, ts.y/2.f));
    // 设置位置
    playerSprite.setPosition(sf::Vector2f(x, y));
}

void Player::control(std::vector<Wall> &walls,std::vector<Electronic> &electronics){
    sf::Vector2f old_pos = playerSprite.getPosition();
    sf::Vector2f movement{0.f, 0.f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.x += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += speed;

    //shape.move(movement);
    playerSprite.move(movement);
    if(touchWall(walls)) shape.setPosition(old_pos),playerSprite.setPosition(old_pos);
    x=playerSprite.getPosition().x;
    y=playerSprite.getPosition().y;

    if(touchElectronic(electronics)){
        changeStatus();
    }
}

bool Player::touchWall(std::vector<Wall> &walls){
    sf::FloatRect PlayBound = playerSprite.getGlobalBounds();
    for (auto wall : walls) {
        if (PlayBound.findIntersection(wall.wallSprite.getGlobalBounds())) {
            return true;
        }
    }
    return false;
}

bool Player::touchElectronic(std::vector<Electronic> &electronics){
    sf::FloatRect PlayBound = playerSprite.getGlobalBounds();
    for (auto e : electronics) {
        if (PlayBound.findIntersection(e.electronicSprite.getGlobalBounds())) {
            if(e.positive!=status){
                e.positive=!e.positive;
                return true;
            }
            else return false;
        }
    }
    return false;
}

void Player::changeStatus(){
    status=!status;
    playerSprite.setTexture(status?p_playerTexture:n_playerTexture);
    // 设置位置和缩放（r 为半径/大小）
    sf::Vector2u ts = playerSprite.getTexture().getSize();
    // 缩放成直径 2*r
    playerSprite.setScale(sf::Vector2f((2*r)/ts.x, (2*r)/ts.y));
    // 设置中心原点
    playerSprite.setOrigin(sf::Vector2f(ts.x/2.f, ts.y/2.f));
    // 设置位置
    playerSprite.setPosition(sf::Vector2f(x, y));
}

bool Player::getstatus(){
    return status;
}