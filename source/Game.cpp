#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Game.h"
#include "include/Object.h"
#include "include/Player.h"

using namespace std;
using namespace sf;

Game::Game(int window_width, int window_height) : 
window(VideoMode(window_width, window_height), "Lowcraft -- 1.0.0", Style::Close),
room("rm_Game", &this->window), 
object("obj_Player", &this->window) {

    window.setFramerateLimit(75);

    this->window_width = window_width;
    this->window_height = window_height;
    Game::create();
}

void Game::create() {

    this->player.setPosition(32, 32);
    this->object.addInstance(&this->player);
    this->room.addObject(&this->object);
}

void Game::update() {
    
    this->room.update();
}

void Game::draw() {

    this->room.draw();
}

void Game::run() {

    while(this->window.isOpen()) {
        
        Event event;
        while(this->window.pollEvent(event)) {
            
            switch(event.type) {
                
                case Event::Closed :
                    this->window.close();
                    break;

                default : break;
            }
        }

        //Game Update
        Game::update();

        //Game Draw
        this->window.clear();
        Game::draw();
        this->window.display();
    }
}