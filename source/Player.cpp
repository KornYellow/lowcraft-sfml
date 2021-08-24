#include "include/Player.h"

//Functions
void Player::create() {

    std::cout << "Player created." << std::endl;

    this->setPosition(sf::Vector2f(32, 32));
    this->setSprite("../resource/Player.png");
}
void Player::update() {

}
void Player::render() {

    this->drawSelf();
}