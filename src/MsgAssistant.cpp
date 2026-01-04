#include "MsgAssistant.h"

MsgAssistant::MsgAssistant(int cnt,int w,int h) : msg(0.25*w,0.75*h,0.5*w,0.125*h) {
    messages.assign(cnt,{});
    vis_time.assign(cnt,0);
    ref_cnt.assign(cnt,0);
    msgset();
}

void MsgAssistant::msgset(){
    messages[0].push_back("This is the Core of CPU!");
    messages[0].push_back("Some units seem to be destroyed!");
    messages[0].push_back("Let's Fix Them!");
    
    messages[1].push_back("This is a OR Gate House!");
    messages[1].push_back("Remember the Following Rules:");
    messages[1].push_back("only 0 | 0 = 0!");
    messages[1].push_back("Have A Nice Trip!");

    messages[2].push_back("This is a AND Gate House!");
    messages[2].push_back("Remember the Following Rules:");
    messages[2].push_back("only 1 & 1 = 1!");
    messages[2].push_back("Have A Nice Trip!");

    messages[3].push_back("This is a XOR Gate House!");
    messages[3].push_back("Remember the Following Rules:");
    messages[3].push_back("only 0 ^ 1 = 1!");
    messages[3].push_back("Have A Nice Trip!");

    messages[4].push_back("This is a NOT Gate House!");
    messages[4].push_back("Remember the Following Rules:");
    messages[4].push_back("Just Be Different");
    messages[4].push_back("Have A Nice Trip!");
}

void MsgAssistant::show(int idx){
    if(idx==messages.size()){
        msg.set("You've fixed all the gates here!");
        return;
    }
    if(!vis_time[idx]&&ref_cnt[idx]<messages[idx].size()){
        msg.set(messages[idx][ref_cnt[idx]]);
        ref_cnt[idx]++;
    }
    else{
        msg.set("");
    }
}

void MsgAssistant::inc_vis(int idx){
    vis_time[idx]++;
}