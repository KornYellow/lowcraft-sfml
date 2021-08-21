#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Player.h"

using namespace std;
using namespace sf;

void Instance::create() {

    Instance::setTexture("../resource/Player.png");
}

void Instance::update() {

}

void Instance::draw() {

    Instance::drawSelf();
}