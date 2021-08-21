#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Room.h"

using namespace std;
using namespace sf;

class Game {

    private:

        //RenderWindow
        RenderWindow window;
        int window_width;
        int window_height;

        //Room
        Room room;

        //Game Functions
        void create();
        void update();
        void draw();

    public: Game(int window_width, int window_height);
        
        //Window
        int getWindowWidth();   
        int getWindowHeight();

        //Game Functions
        void run();
};