#include "include/Player.h"

//Functions
void Player::create() {

    this->player_speed_h = 0;
    this->player_speed_v = 0;
    this->player_speed = 6;

    this->player_shoot_delay = 0;
    this->player_shoot_firerate = 5;

    this->setPosition(32, 32);
    this->setSprite("../resource/Player.png");
}
void Player::update() {
    
    //Player
    this->playerFollowMouse();
    this->playerShootBullet();

    this->setPosition(this->x, this->y);
    
    //Bullets
    this->updateBulletPlayer();
    this->deleteBulletPlayer();

    this->updateBulletEnemy();
    this->deleteBulletEnemy();
}
void Player::render() {

    //Bullets
    this->renderBulletEnemy();
    this->renderBulletPlayer();

    //Player
    this->drawSelf();
}

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

        int bullet_x = Randomize::randomIntRange(this->x - 5, this->x + 5);
        this->createBulletPlayer(bullet_x, this->y - 20, 15, -90);

        this->player_shoot_delay = this->player_shoot_firerate;
    }
    else this->player_shoot_delay --;
}

//Bullets
void Player::createBulletPlayer(double x, double y, double speed, int direction) {

    BulletPlayer* bullet = new BulletPlayer();
    bullet->create();
    bullet->setRenderWindow(this->getRenderWindow());
    bullet->setPosition(x, y);
    bullet->setBulletSpeed(speed);
    bullet->setBulletDirection(direction);

    this->bullets_player.push_back(bullet);
}
void Player::updateBulletPlayer() {

    for(int i = 0; i < this->bullets_player.size(); i++) {

        this->bullets_player.at(i)->update();
    }
}
void Player::renderBulletPlayer() {

    for(int i = 0; i < this->bullets_player.size(); i++) {
   
        this->bullets_player.at(i)->render();
    }
}   
void Player::deleteBulletPlayer() {

    for(int i = 0; i < this->bullets_player.size(); i++) {

        if(this->bullets_player.at(i)->isOutOfRenderWindow()) {

            this->bullets_player.erase(this->bullets_player.begin() + i);
        }
    }
}
void Player::createBulletEnemy(double x, double y, double speed, int direction, std::string type) {

    BulletEnemy* bullet = new BulletEnemy();
    bullet->setRenderWindow(this->getRenderWindow());
    bullet->setPosition(x, y);
    bullet->setBulletSpeed(speed);
    bullet->setBulletDirection(direction);
    bullet->setBulletType(type);

    bullet->create();

    this->bullets_enemy.push_back(bullet);
}
void Player::updateBulletEnemy() {

    for(int i = 0; i < this->bullets_enemy.size(); i++) {

        this->bullets_enemy.at(i)->update();
    }
}
void Player::renderBulletEnemy() {

    for(int i = 0; i < this->bullets_enemy.size(); i++) {
   
        this->bullets_enemy.at(i)->render();
    }
}   
void Player::deleteBulletEnemy() {

    for(int i = 0; i < this->bullets_enemy.size(); i++) {

        if(this->bullets_enemy.at(i)->isOutOfRenderWindow()) {

            this->bullets_enemy.erase(this->bullets_enemy.begin() + i);
        }
    }
}