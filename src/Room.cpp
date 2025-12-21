#include "Room.h"
#include <cstring>
#include <vector>

Room::Room(int idx) : idx(idx),maze(idx),map(maze.get_map(idx)) {}

void Room::render(){

}

void Room::set(int x,int y,char ch){
    map[x][y]=ch;
}