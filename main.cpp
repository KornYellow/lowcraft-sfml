#include "include/Game.h"

int main() {

    Game game;

    //Game Loop
    while(game.isGameRunning()) {

        //Game Update
        game.update();

        //Game Render
        game.render();
    }

    return 0;
}