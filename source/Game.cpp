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
room("rm_Game", &this->window) {

    this->window_width = window_width;
    this->window_height = window_height;
    Game::create();
}

void Game::create() {

    Object object("obj_Player", &this->window);

    Player player;
    player.setPosition(32, 32);
    
    object.addInstance(player);
    this->room.addObject(object);
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