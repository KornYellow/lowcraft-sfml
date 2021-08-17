#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Game.h"

using namespace std;
using namespace sf;

class Room {

    private:

        Game* game;

        int room_id;
        string room_name;
        int room_width;
        int room_height;
        int room_speed;

    public: Room(string room_name, int room_id, int room_width, int room_height);

        int getRoomID();
        string getRoomName();
        int getRoomWidth();
        int getRoomHeight();
};