#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Object.h"

using namespace std;
using namespace sf;

/*
void Object::setObjectName(string object_name) {

    this->object_name = object_name;
}

string Object::getObjectName() {

    return this->object_name;
}

string Object::getRoomName() {

    return this->room_name;
}

void Object::setRoomName(string room_name) {

    this->room_name = room_name;
}

RenderWindow* Object::getRenderWindow() {

    return this->window;
}

void Object::setRenderWindow(RenderWindow* window) {

    this->window = window;
}

void Object::addInstance(Instance* instance) {

    instance->create();

    instance->setObjectName(this->object_name);
    instance->setRenderWindow(this->window);
    this->instances.push_back(instance);
}

Instance* Object::getInstance(int index) {

    return this->instances.at(index);
}

void Object::update() {

    for(int i = 0; i < this->instances.size(); i++) {

        this->instances.at(i)->update();
    }
}

void Object::draw() {

    for(int i = 0; i < this->instances.size(); i++) {

        this->instances.at(i)->draw();
    }
}
*/