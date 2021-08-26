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
}
void Player::playerFollowMouse() {
    
    this->x += (this->getMousePosition().x - this->x) / 5;
    this->y += (this->getMousePosition().y - this->y) / 5;
}
void Player::playerShootBullet() {

    if(Player::mouseCheck(sf::Mouse::Button::Left) && this->player_shoot_delay < 0) {

        this->createBullet();

        this->player_shoot_delay = this->player_shoot_firerate;
    }
    else this->player_shoot_delay --;
}

//Bullets
void Player::createBullet() {

    Bullet* bullet = new Bullet();
    bullet->create();
    bullet->setRenderWindow(this->getRenderWindow());
    bullet->setPosition(this->getPosition().x, this->getPosition().y - 20);
    bullet->setBulletSpeed(10);
    bullet->setBulletDirection(-90);

    this->bullets.push_back(bullet);
}
void Player::updateBullet() {

    for(int i = 0; i < this->bullets.size(); i++) {

        this->bullets.at(i)->update();
    }
}
void Player::renderBullet() {

    for(int i = 0; i < this->bullets.size(); i++) {
   
        this->bullets.at(i)->render();
    }
}   
void Player::deleteBullet() {

    for(int i = 0; i < this->bullets.size(); i++) {

        if(this->bullets.at(i)->isOutOfRenderWindow()) {

            this->bullets.erase(this->bullets.begin() + i);
        }
    }
}

//Functions
void Player::create() {

    this->player_speed_h = 0;
    this->player_speed_v = 0;
    this->player_speed = 6;

    this->player_shoot_delay = 0;
    this->player_shoot_firerate = 10;

    this->setPosition(32, 32);
    this->setSprite("../resource/Player.png");
}
void Player::update() {
    
    //Player
    this->playerFollowMouse();
    this->playerShootBullet();

    this->setPosition(this->x, this->y);
    
    //Bullets
    this->updateBullet();
    this->deleteBullet();
}
void Player::render() {

    //Player
    this->drawSelf();

    //Bullets
    this->renderBullet();
}