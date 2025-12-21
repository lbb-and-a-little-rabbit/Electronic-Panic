#include "Room.h"
#include <cstring>

Room::Room(int idx) : idx(idx),maze(idx) {
    auto& src=maze.get_map(idx);
    std::memcpy(map,src,sizeof(map));
}