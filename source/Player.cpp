#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Player.h"

using namespace std;
using namespace sf;

void Player::playerMovement(double player_speed) {
    
    bool key_right = Player::keyboardCheck(Keyboard::Key::D);
    bool key_left = Player::keyboardCheck(Keyboard::Key::A);
    bool key_down = Player::keyboardCheck(Keyboard::Key::S);
    bool key_up = Player::keyboardCheck(Keyboard::Key::W);

    int move_h = key_right - key_left;
    int move_v = key_down - key_up;

    this->player_speed_h = move_h * player_speed;
    this->player_speed_v = move_v * player_speed;

    this->x += this->player_speed_h;
    this->y += this->player_speed_v;

    Player::setPosition(this->x, this->y);
}

void Player::create() {
    
    this->player_speed_h = 0;
    this->player_speed_v = 0;
    this->player_speed = 10;

    Player::setTexture("../resource/Player.png");
}

void Player::update() {

    Player::playerMovement(this->player_speed);
}   

void Player::draw() {

    Player::drawSelf();
}