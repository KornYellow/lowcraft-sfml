#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Wall.h"

using namespace std;
using namespace sf;

void Wall::create() {
    
    Wall::setTexture("../resource/Wall.png");
}

void Wall::update() {

}   

void Wall::draw() {

    Wall::drawSelf();
}