#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Game.h"
#include "include/Object.h"
#include "include/Player.h"

using namespace std;
using namespace sf;

Game::Game(int render_window_width, int render_window_height) : 
render_window(VideoMode(render_window_width, render_window_height), "Lowcraft -- 1.0.0", Style::Close) {

    render_window.setFramerateLimit(75);

    this->render_window_width = render_window_width;
    this->render_window_height = render_window_height;
    Game::create();
}

//Game
void Game::create() {


}
void Game::update() {
    

}
void Game::draw() {


}
void Game::run() {

    while(this->render_window.isOpen()) {
        
        Event event;
        while(this->render_window.pollEvent(event)) {
            
            switch(event.type) {
                
                case Event::Closed :
                    this->render_window.close();
                    break;

                default : break;
            }
        }

        //Game Update
        Game::update();

        //Game Draw
        this->render_window.clear();
        Game::draw();
        this->render_window.display();
    }
}

//RenderWindow
int Game::getRenderWindowWidth() { return this->render_window_width; }
int Game::getRenderWindowHeight() { return this->render_window_height; }

//Room
void Game::createRoom(string room_name) {

    Room room;
    room.setGame(this);
    room.setRenderWindow(&this->render_window);
    room.setRoomName(room_name);

    rooms.push_back(room);
}

Room* Game::getRoom(string room_name) {

    Room* room;
    bool is_found = false;

    for(int i = 0; i < this->rooms.size(); i++) {

        if(this->rooms.at(i).getRoomName() == room_name) {

            room = &this->rooms.at(i);
            is_found = true;
        }   
    }
    
    if(!is_found) {

        throw "ERROR: \'" + room_name + "\' has not been created yet."; 
    }

    return room;
}