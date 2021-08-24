#include "include/Player.h"

//Movement
void Player::playerMovement(double player_speed) {
    
    bool key_right = Player::keyboardCheck(sf::Keyboard::Key::Right);
    bool key_left = Player::keyboardCheck(sf::Keyboard::Key::Left);
    bool key_down = Player::keyboardCheck(sf::Keyboard::Key::Down);
    bool key_up = Player::keyboardCheck(sf::Keyboard::Key::Up);

    int move_h = key_right - key_left;
    int move_v = key_down - key_up;

    this->player_speed_h = move_h * this->player_speed;
    this->player_speed_v = move_v * this->player_speed;

    this->x += this->player_speed_h;
    this->y += this->player_speed_v;

    this->setPosition(this->x, this->y);
}

//Functions
void Player::create() {

    std::cout << "Player created." << std::endl;

    this->player_speed_h = 0;
    this->player_speed_v = 0;
    this->player_speed = 6;

    this->setPosition(32, 32);
    this->setSprite("../resource/Player.png");
}
void Player::update() {
    
    this->playerMovement(this->player_speed);
}
void Player::render() {

    this->drawSelf();
}