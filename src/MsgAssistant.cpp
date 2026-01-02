#include "MsgAssistant.h"

MsgAssistant::MsgAssistant(int cnt,int w,int h) : msg(0.25*w,0,0.5*w,0.125*h) {
    messages.assign(cnt,"");
    ref_cnt.assign(cnt,0);
}