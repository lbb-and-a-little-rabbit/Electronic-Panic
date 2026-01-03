#pragma once

#include "Msgbox.h"
#include <vector>
#include <string>

class MsgAssistant{
    Msgbox msg;
    std::vector<int> vis_time;
    std::vector<int> ref_cnt;
    std::vector<std::vector<std::string>> messages;
    friend class Game;

    void msgset();
public:
    MsgAssistant(int cnt,int w,int h);
    void show(int idx);
    void inc_vis(int idx);
};