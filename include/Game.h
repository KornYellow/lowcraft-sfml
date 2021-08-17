#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Game {

    private:

        RenderWindow window;
        int window_width;
        int window_height;

    public:
    
        Game(int window_width, int window_height);
        
        int getWindowWidth();   
        int getWindowHeight();

        void run();
        void update();
        void draw();
};