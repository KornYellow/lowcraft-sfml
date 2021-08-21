#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Room.h"

using namespace std;
using namespace sf;

Room::Room(string room_name, RenderWindow* window) {

    this->room_name = room_name;
    this->window = window;
}

void Room::update() {

    for(int i = 0; i < this->objects.size(); i++) {

        this->objects.at(i).update();
    }
}

void Room::draw() {

    for(int i = 0; i < this->objects.size(); i++) {

        this->objects.at(i).draw();
    }
}

void Room::addObject(Object object) {

    object.setRoomName(this->room_name);
    object.setRenderWindow(this->window);
    this->objects.push_back(object);
}

Object Room::getObject(int index) {

    return this->objects.at(index);
}