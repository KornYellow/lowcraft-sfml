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

    //Select room
    Game::setSelectedRoom(-1);
    if(Game::getRooms().size() != 0) {

        Game::setSelectedRoom(0);
        Room room = Game::getRoom(Game::getSelectedRoom());
        cout << "Room " << room.getRoomName() << " (" << room.getRoomID() << ") selected." << endl;
    }

    //Run the game loop
    if(Game::getSelectedRoom() != -1) {

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
    else {

        cout << "Cannot run the game, because cannot find any room." << endl;
    }
}