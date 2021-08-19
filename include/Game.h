#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Room.h"

using namespace std;
using namespace sf;

class Game {

    private:

        RenderWindow window;
        int window_width;
        int window_height;

        int selected_room;
        vector <Room> rooms;

    public:
    
        Game(int window_width, int window_height);
        
        int getWindowWidth();   
        int getWindowHeight();

        void addRoom(Room room);

        void setSelectedRoom(int index);
        int getSelectedRoom();
        
        Room getRoom(int index);
        Room getFirstRoom();
        Room getLastRoom();

        vector <Room> getRooms();

        void run();
        void update();
        void draw();
};