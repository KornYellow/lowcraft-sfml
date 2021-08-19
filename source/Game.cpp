#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Game.h"

using namespace std;
using namespace sf;

Game::Game(int window_width, int window_height):
window(VideoMode(window_width, window_height), "Lowcraft -- 1.0.0", Style::Close) {

    this->window_width = window_width;
    this->window_height = window_height;

    cout << "Game initialized with a dimension of " << window_width << " by " << window_height << "." << endl;
    
    this->selected_room = 0;
}

void Game::update() {
    
}

void Game::draw() {

}

void Game::addRoom(Room room) {

    this->rooms.push_back(room);
}

void Game::setSelectedRoom(int index) {
    
    this->selected_room = index;
}

int Game::getSelectedRoom() {
    
    return this->selected_room;
}

Room Game::getRoom(int index) {

    return this->rooms.at(index);
}

Room Game::getFirstRoom() {

    return this->rooms.at(0);
}

Room Game::getLastRoom() {

    return this->rooms.at(this->rooms.size() - 1);
}

vector <Room> Game::getRooms() {

    return this->rooms;
}

int Game::getWindowWidth() {

    return this->window_width;
}

int Game::getWindowHeight() {

    return this->window_height;
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

        Game::update();

        this->window.clear();
        Game::draw();
        this->window.display();
    }
}