#include "msgbox.h"

sf::Texture Msgbox::msgTexture("assets/msgbox.png");
sf::Font Msgbox::font("assets/ScreenMatrix-1.ttf");

Msgbox::Msgbox(float x, float y, float width, float height) : msgSprite(msgTexture),text(font) {
    text.setString("");
    shape.setSize({width, height});
    shape.setPosition({x, y});

    msgSprite.setPosition({x, y});
    sf::Vector2u textureSize = msgTexture.getSize();
    sf::Vector2f windowSize = shape.getSize();
    sf::Vector2f scale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );
    msgSprite.setScale(scale);

    text.setFillColor(sf::Color::Green);
    text.setCharacterSize(25.f);
    text.setPosition({x-0.25f*width,y+0.25f*height});
}

bool Msgbox::nulltext(){
    return text.getString()=="";
}

void Msgbox::set(std::string s){
    if(clocking) return;
    text.setString(s);
}

void Msgbox::settime(std::string s, float time) {
    text.setString(s);      // 设置文字
    displayTime = time;     // 设置显示时间
    textclock.restart();    // 重新计时
    clocking=true;
}

void Msgbox::update() {
    if(!clocking) return;
    if (!nulltext() && textclock.getElapsedTime().asSeconds() >= displayTime) {
        text.setString("");  // 时间到，清空文字
        clocking=false;
    }
}