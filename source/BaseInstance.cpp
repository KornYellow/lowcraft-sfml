#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/BaseInstance.h"

using namespace std;
using namespace sf;

void BaseInstance::create() {
    
    BaseInstance::setTexture("../resource/Player.png");
}

void BaseInstance::update() {

}   

void BaseInstance::draw() {

    BaseInstance::drawSelf();
}