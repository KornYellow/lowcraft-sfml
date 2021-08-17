#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Game.h"

using namespace std;
using namespace sf;

Game::Game(int window_width, int window_height):
window(VideoMode(window_width, window_height), "Lowcraft - 1.0.0", Style::Close) {

    this->window_width = window_width;
    this->window_height = window_height;

    cout << "Camera initialized with dimension of (" << window_width << "x" << window_height << ")." << endl;
}

int Game::getWindowWidth() {

    return this->window_width;
}

int Game::getWindowHeight() {

    return this->window_height;
}

void Game::run() {

    while (this->window.isOpen()) {
        
        Event event;
        while (this->window.pollEvent(event)) {
            
            switch(event.type) {
                
                case Event::Closed :
                    this->window.close();
                    break;

                default : break;
            }
        }

        this->window.clear();
        this->window.display();
    }
}