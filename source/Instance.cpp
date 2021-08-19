#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Instance.h"

using namespace std;
using namespace sf;

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

double Instance::getX() {

    return this->x;
}

double Instance::getY() {

    return this->y;
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