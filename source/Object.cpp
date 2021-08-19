#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Object.h"

using namespace std;
using namespace sf;

Object::Object(string object_name, RenderWindow* window ) {

    this->object_name = object_name;
    this->window = window;
}

void Object::update() {

    for(int i = 0; i < this->instances.size(); i++) {

        this->instances.at(i).update();
    }
}

void Object::draw() {

    for(int i = 0; i < this->instances.size(); i++) {

        this->instances.at(i).draw();
    }
}

void Object::addInstance(Instance instance) {

    instance.create();
    instance.setRenderWindow(this->window);
    this->instances.push_back(instance);
}

Instance Object::getInstance(int index) {

    return this->instances.at(index);
}