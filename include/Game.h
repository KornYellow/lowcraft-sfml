#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Object.h"

using namespace std;
using namespace sf;

class Game {

    private:

        //RenderWindow
        RenderWindow window;
        int window_width;
        int window_height;

        //Object
        Object object;

        //Game Functions
        void create();
        void update();
        void draw();

    public: Game(int window_width, int window_height);
        
        int getWindowWidth();   
        int getWindowHeight();

        void run();
};