#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Camera {

    private:

        RenderWindow window;
        int window_width;
        int window_height;

    public:
    
        Camera(int window_width, int window_height);
        
        int getWindowWidth();
        int getWindowHeight();

        void run();
};