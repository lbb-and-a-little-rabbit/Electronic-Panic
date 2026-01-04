#include "Player.h"
sf::Texture p1("assets/p1.png");
sf::Texture p2("assets/p2.png");
sf::Texture p3("assets/p3.png");
std::vector<sf::Texture> Player::p_playerTexture;

sf::Texture n1("assets/n1.png");
sf::Texture n2("assets/n2.png");
sf::Texture n3("assets/n3.png");
std::vector<sf::Texture> Player::n_playerTexture;

Player::Player(float x,float y,float r,bool status) : r(r),pos(x,y),physicalR(0.7*r),status(status),playerSprite(status?p1:n1) {
    if(p_playerTexture.size()<3){
        p_playerTexture.push_back(p1);
        p_playerTexture.push_back(p2);
        p_playerTexture.push_back(p3);
    }
    if(n_playerTexture.size()<3){
        n_playerTexture.push_back(n1);
        n_playerTexture.push_back(n2);
        n_playerTexture.push_back(n3);
    }

    // 设置位置和缩放（r 为半径/大小）
    sf::Vector2u ts = playerSprite.getTexture().getSize();
    // 缩放成直径 2*r
    playerSprite.setScale(sf::Vector2f((2*r)/ts.x, (2*r)/ts.y));
    // 设置中心原点
    playerSprite.setOrigin(sf::Vector2f(ts.x/2.f, ts.y/2.f));
    // 设置位置
    playerSprite.setPosition(pos);
}

void Player::update(float dt) {
    if(status){
        elapsedTime += dt;
        if(elapsedTime >= switchTime) {
            elapsedTime = 0.f;
            currentFrame = (currentFrame + 1) % p_playerTexture.size();
            playerSprite.setTexture(p_playerTexture[currentFrame]);
        }
    }
    else{
        elapsedTime += dt;
        if(elapsedTime >= switchTime) {
            elapsedTime = 0.f;
            currentFrame = (currentFrame + 1) % n_playerTexture.size();
            playerSprite.setTexture(n_playerTexture[currentFrame]);
        }
    }
}

void Player::control(std::vector<Wall> &walls,std::vector<Electronic> &electronics,std::vector<OR> &ors,std::vector<AND> &ands,std::vector<NOT> &nots,std::vector<XOR> &xors){
    sf::Vector2f old_pos = pos;
    sf::Vector2f movement{0.f, 0.f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.y -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.x += speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += speed;

    pos+=movement;
    if(touchWall(walls) || touchGate(ors,ands,nots,xors)) pos=old_pos;
    playerSprite.setPosition(pos);

    if(touchElectronic(electronics)){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)){
            if(!acous.openFromFile("assets/change.mp3")){
                std::cerr << "acoustics load fail!";
                exit(-1);
            }
            acous.setLooping(false);
            acous.play();
            changeStatus();
        }
    }
}

bool Player::touchWall(std::vector<Wall> &walls){
    sf::FloatRect trueBound = getHitbox();
    for (auto wall : walls) {
        if (trueBound.findIntersection(wall.wallSprite.getGlobalBounds())) {
            return true;
        }
    }
    return false;
}

bool Player::touchElectronic(std::vector<Electronic> &electronics){
    sf::FloatRect PlayBound = playerSprite.getGlobalBounds();
    for (auto e : electronics) {
        if (PlayBound.findIntersection(e.electronicSprite.getGlobalBounds())) {
            return e.positive!=status;
        }
    }
    return false;
}

Info_Transport Player::touchtransport(std::vector<Transport> &transports){
    sf::FloatRect trueBound = getHitbox();
    Info_Transport res;
    for (auto &t : transports) {
        if (trueBound.findIntersection(t.transSprite.getGlobalBounds())) {
            res.towards=t.towards;
            res.posx=t.mappos_x;
            res.posy=t.mappos_y;
            return res;
        }
    }
    return res;
}

Info_Judgement Player::touchjudgement(std::vector<Judgement> &judgements){
    Info_Judgement res;
    sf::FloatRect trueBound = getHitbox();
    for(auto &j : judgements){
        if (trueBound.findIntersection(j.judgeSprite.getGlobalBounds())) {
            res.judge=j.judge;
            res.mappos_x=j.mappos_x;
            res.mappos_y=j.mappos_y;
            return res;
        }
    }
    return res;
}

bool Player::touchGate(std::vector<OR> &ors,std::vector<AND> &ands,std::vector<NOT> &nots,std::vector<XOR> &xors){
    sf::FloatRect trueBound = getHitbox();
    for(auto &g : ors){
        if (trueBound.findIntersection(g.orSprite.getGlobalBounds())) {
            return true;
        }
    }
    for(auto &g : ands){
        if (trueBound.findIntersection(g.andSprite.getGlobalBounds())) {
            return true;
        }
    }
    for(auto &g : nots){
        if (trueBound.findIntersection(g.notSprite.getGlobalBounds())) {
            return true;
        }
    }
    for(auto &g : xors){
        if (trueBound.findIntersection(g.xorSprite.getGlobalBounds())) {
            return true;
        }
    }
    return false;
}

void Player::changeStatus(){
    status = !status;

    // 切换纹理，但保持当前缩放
    sf::Vector2f currentScale = playerSprite.getScale();
    playerSprite.setTexture(status ? p1 : n1);
    playerSprite.setScale(currentScale);  // 保持缩放

    // 设置中心原点
    sf::Vector2u ts = playerSprite.getTexture().getSize();
    playerSprite.setOrigin({ts.x/2.f, ts.y/2.f});

    playerSprite.setPosition(pos);
}

bool Player::getstatus(){
    return status;
}

/*
sf::FloatRect Player::getHitbox(){
    sf::FloatRect PlayBound = playerSprite.getGlobalBounds();
    sf::FloatRect trueBound;
    trueBound.position=PlayBound.position;
    trueBound.size.x=PlayBound.size.x*0.8;
    trueBound.size.y=PlayBound.size.y*0.8;
    return trueBound;
}
*/

sf::FloatRect Player::getHitbox(){
    sf::FloatRect PlayBound = playerSprite.getGlobalBounds();
    sf::FloatRect trueBound;
    trueBound.position = pos - sf::Vector2f(physicalR, physicalR);
    trueBound.size = sf::Vector2f(physicalR*2, physicalR*2);
    return trueBound;
}