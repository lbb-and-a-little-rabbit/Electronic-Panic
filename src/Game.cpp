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

std::vector<std::string> music_path={
    "assets/CPU.ogg",
    "assets/dive.ogg",
    "assets/dive.ogg",
    "assets/dive.ogg",
    "assets/dive.ogg",
};

Game::Game(unsigned int w,unsigned int h) : player(nullptr),updated(false),room_idx(0),window(sf::VideoMode({w,h}),"Electronic Panic"),msgbox(0.25*w,0,0.5*w,0.125*h) {
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

    //set music
    if (!currentMusic.openFromFile(music_path[room_idx])) {
        std::cerr << "Music Loading Failed!\n";
        exit(-1);
    }
    currentMusic.setLooping(true);

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
    judgements.clear();
    sources.clear();
}

void Game::set_based_on_map(){
    vector_clear();
    //set vectors
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
            else if(currentRoom->map[y][x]=='*'||currentRoom->map[y][x]=='/'){
                judgements.emplace_back(x*cellSize,y*cellSize,cellSize,cellSize,currentRoom->map[y][x]);
            }
            else if(currentRoom->map[y][x]=='S'){
                sources.emplace_back(x*cellSize,y*cellSize,cellSize,cellSize);
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

    //set music
    // 淡出旧音乐
    while(currentMusic.getVolume() > 0){
        currentMusic.setVolume(currentMusic.getVolume() - 1);
        sf::sleep(sf::milliseconds(10));
    }
    currentMusic.stop();
    if(!currentMusic.openFromFile(music_path[idx])){
        std::cerr << "Music Loading Failed!\n";
        exit(-1);
    }
    currentMusic.setVolume(100);
    currentMusic.setLooping(true);
    currentMusic.play();
}


void Game::run(){
    currentMusic.play();
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
    player->control(walls,electronics,orgates,andgates,notgates,xorgates);
    call_update();
}

void Game::call_update(){
    int towards=player->touchtransport(transports);
    if(towards!=-1){
        msgbox.set("Press Space to Change the Room");
        if(call_Press(sf::Keyboard::Key::Space)){
            updated=true;
            room_idx=towards;
        }
    }
    else{
        msgbox.set("");
    }
}

void Game::update(){
    if(!updated) return;
    updated=false;
    loadBackground(room_idx);
    currentRoom=std::make_unique<Room>(room_idx); 
    set_based_on_map();
}

bool Game::call_Press(sf::Keyboard::Key key){
    return sf::Keyboard::isKeyPressed(key);
}

void Game::render(){
    window.clear(sf::Color(50, 50, 50));
    window.draw(*backgroundSprite); 
    wallrender();
    sourcerender();
    electronicrender();
    transrender();
    judgementrender();
    gaterender();
    playerrender();

    //temp for test
    msgboxrender();
    //tem for test

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
    for(AND &g:andgates) window.draw(g.andSprite);
    for(NOT &g:notgates) window.draw(g.notSprite);
    for(XOR &g:xorgates) window.draw(g.xorSprite);
}

void Game::playerrender(){
    window.draw(player->playerSprite);
}

void Game::transrender(){
    for(Transport &t:transports) window.draw(t.transSprite);
}

void Game::judgementrender(){
    for(Judgement &j:judgements) window.draw(j.judgeSprite);
}

void Game::sourcerender(){
    for(Source &s:sources) window.draw(s.sourceSprite);
}

void Game::msgboxrender(){
    //window.draw(msgbox.msgSprite);
    window.draw(msgbox.text);
}