#include <iostream>

#include "include/Game.h"
#include "include/Room.h"

using namespace std;

Game game(1080, 720);

int main() {

    Room room("rm_Game", 0, 1080, 720);

    game.run();

    return 0;
}