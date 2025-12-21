#pragma once

#include <SFML\Graphics.hpp>

#define MAP_CNT 5

class Maze{
    static char map[MAP_CNT][15][21];
    int idx;

public:
    Maze(int idx);
    static char (&get_map(int idx))[15][21];
};