#include "Electronic.h"

sf::Texture Electronic::positive_electronicTexture("assets/positive_e.png");
sf::Texture Electronic::negative_electronicTexture("assets/negative_e.png");

Electronic::Electronic(float x,float y,float r,bool positive) : positive(positive),electronicSprite(positive?positive_electronicTexture:negative_electronicTexture) {
    // 设置位置和缩放（r 为半径/大小）
    sf::Vector2u ts = electronicSprite.getTexture().getSize();
    // 缩放成直径 2*r
    electronicSprite.setScale(sf::Vector2f((2*r)/ts.x, (2*r)/ts.y));
    // 设置中心原点
    electronicSprite.setOrigin(sf::Vector2f(ts.x/2.f, ts.y/2.f));
    // 设置位置
    electronicSprite.setPosition(sf::Vector2f(x, y));
}