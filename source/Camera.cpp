#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Camera.h"

using namespace std;
using namespace sf;

Camera::Camera(int window_width, int window_height):
window(VideoMode(window_width, window_height), "SFML window") {

    this->window_width = window_width;
    this->window_height = window_height;

    cout << "Camera initialize with dimension of " << window_width << "x" << window_height << endl;
}

void Camera::run() {

    while (window.isOpen()) {
        
        Event event;
        while (window.pollEvent(event)) {
            
            switch(event.type) {
                
                case Event::Closed :
                    window.close();
                    break;

                default : break;
            }
        }

        window.clear();
        window.display();
    }
}