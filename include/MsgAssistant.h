#pragma once

#include "Msgbox.h"
#include <vector>
#include <string>

class MsgAssistant{
    Msgbox msg;
    std::vector<int> ref_cnt;
    std::vector<std::string> messages;

public:
    MsgAssistant(int cnt,int w,int h);
};