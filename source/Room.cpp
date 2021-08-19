#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Room.h"

using namespace std;
using namespace sf;

Room::Room(string room_name, int room_id, int room_width, int room_height) {

    this->room_name = room_name;
    this->room_id = room_id;
    this->room_width = room_width;
    this->room_height = room_height;

    cout << "Room " << room_name << " created with an index of # " << room_id << "." << endl;
}

int Room::getRoomID() {

    return this->room_id;
}

string Room::getRoomName() {

    return this->room_name;
}

int Room::getRoomWidth() {

    return this->room_width;
}   

int Room::getRoomHeight() {

    return this->room_height;
}