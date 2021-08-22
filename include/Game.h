#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Room.h"

using namespace std;
using namespace sf;

class Room;

class Game {

    private:

        //Game
        void create();
        void update();
        void draw();

        //RenderWindow
        RenderWindow render_window;
        int render_window_width;
        int render_window_height;

        //Room
        vector <Room> rooms;

    public: Game(int render_window_width, int render_window_height);

        //Game Functions
        void run();

        //RenderWindow
        int getRenderWindowWidth();   
        int getRenderWindowHeight();

        //Room
        void createRoom(string room_name);
        Room* getRoom(string room_name);

        void printRooms();
};