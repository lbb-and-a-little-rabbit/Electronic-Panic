#pragma once

#include <SFML/Graphics.hpp>
#include "Maze.h"

class Room{
    int idx;
    Maze maze;
    char (&map)[15][21];
    friend class Game;

public:
    Room(int idx);
    void render();
    void set(int x,int y,char ch);
};