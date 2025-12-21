#pragma once

#include <SFML/Graphics.hpp>
#include "Maze.h"

class Room{
    int idx;
    Maze maze;
    char map[15][21];

public:
    Room(int idx);
};