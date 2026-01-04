#include "Electronic.h"

sf::Texture pe1("assets/positive_e1.png");
sf::Texture pe2("assets/positive_e2.png");
sf::Texture pe3("assets/positive_e3.png");
sf::Texture pe4("assets/positive_e4.png");
std::vector<sf::Texture> Electronic::positive_electronicTexture;

sf::Texture ne1("assets/negative_e1.png");
sf::Texture ne2("assets/negative_e2.png");
sf::Texture ne3("assets/negative_e3.png");
sf::Texture ne4("assets/negative_e4.png");
std::vector<sf::Texture> Electronic::negative_electronicTexture;

Electronic::Electronic(float x,float y,float r,bool positive) : positive(positive),electronicSprite(positive?pe1:ne1) {
    if(positive_electronicTexture.size()<4){
        positive_electronicTexture.push_back(pe1);
        positive_electronicTexture.push_back(pe2);
        positive_electronicTexture.push_back(pe3);
        positive_electronicTexture.push_back(pe4);

        negative_electronicTexture.push_back(ne1);
        negative_electronicTexture.push_back(ne2);
        negative_electronicTexture.push_back(ne3);
        negative_electronicTexture.push_back(ne4);
    }
    // 设置位置和缩放（r 为半径/大小）
    sf::Vector2u ts = electronicSprite.getTexture().getSize();
    // 缩放成直径 2*r
    electronicSprite.setScale(sf::Vector2f((2*r)/ts.x, (2*r)/ts.y));
    // 设置中心原点
    electronicSprite.setOrigin(sf::Vector2f(ts.x/2.f, ts.y/2.f));
    // 设置位置
    electronicSprite.setPosition(sf::Vector2f(x, y));
}

void Electronic::update(float dt) {
    if(positive){
        elapsedTime += dt;
        if(elapsedTime >= switchTime) {
            elapsedTime = 0.f;
            currentFrame = (currentFrame + 1) % positive_electronicTexture.size();
            electronicSprite.setTexture(positive_electronicTexture[currentFrame]);
        }
    }
    else{
        elapsedTime += dt;
        if(elapsedTime >= switchTime) {
            elapsedTime = 0.f;
            currentFrame = (currentFrame + 1) % negative_electronicTexture.size();
            electronicSprite.setTexture(negative_electronicTexture[currentFrame]);
        }
    }
}