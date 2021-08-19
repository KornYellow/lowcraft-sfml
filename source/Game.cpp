#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Game.h"
#include "include/Player.h"

using namespace std;
using namespace sf;

Game::Game(int window_width, int window_height) : 
window(VideoMode(window_width, window_height), "Lowcraft -- 1.0.0", Style::Close),
object("obj_Player", &this->window) {

    this->window_width = window_width;
    this->window_height = window_height;
    Game::create();
}

void Game::create() {

    Player player1;
    player1.setPosition(32, 32);
    this->object.addInstance(player1);

    Player player2;
    player2.setPosition(64, 64);
    this->object.addInstance(player2);
}

void Game::update() {
    
    this->object.update();
}

void Game::draw() {

    this->object.draw();
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