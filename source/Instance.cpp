#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Instance.h"

using namespace std;
using namespace sf;

string Instance::getObjectName() {

    return this->object_name;
}

void Instance::setObjectName(string object_name) {

    this->object_name = object_name;
}

void Instance::setTexture(string filename) {

    this->texture.loadFromFile(filename);
    this->sprite.setTexture(this->texture);

    this->sprite_width = this->texture.getSize().x;
    this->sprite_height = this->texture.getSize().y;
}

int Instance::getSpriteWidth() {

    return this->sprite_width;
}

int Instance::getSpriteHeight() {

    return this->sprite_height;
}

void Instance::setPosition(double x, double y) {

    this->x = x;
    this->y = y;
}

void Instance::setOrigin(double x, double y) {

    this->sprite.setOrigin(Vector2f(x, y));
}

void Instance::drawSelf() {
    
    this->sprite.setPosition(Vector2f(this->x, this->y));
    this->window->draw(this->sprite);
}

RenderWindow* Instance::getRenderWindow() {

    return this->window;
}

void Instance::setRenderWindow(RenderWindow* window) {

    this->window = window;
}   

void Instance::create() {

}

void Instance::update() {

}

void Instance::draw() {

}

bool Instance::keyboardCheck(Keyboard::Key key) {

    return Keyboard::isKeyPressed(key);
}

bool Instance::keyboardCheckPressed(Keyboard::Key key) {

    if(Instance::keyboardCheck(key) && !this->is_key_pressed.at(Keyboard::Key::A)) {
        
        this->is_key_pressed.at(Keyboard::Key::A) = true;
        return true;
    }
    else if(!Instance::keyboardCheck(key)) {

        this->is_key_pressed.at(Keyboard::Key::A) = false;
    }
    return false;
}