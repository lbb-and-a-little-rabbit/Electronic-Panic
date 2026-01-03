#include "Menu.h"
#include "Game.h"

int main(){
    Menu menu;
    MenuResult result = menu.run();

    if (result == MenuResult::StartGame) {
        Game game;
        game.run();
    }
}