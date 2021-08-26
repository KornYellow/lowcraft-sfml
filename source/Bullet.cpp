#include "include/Bullet.h"

//Movement
void Bullet::bulletMovement(double bullet_speed, double bullet_direction) {

    double move_x = this->x + (bullet_speed * cos(bullet_direction * M_PI / 180));
    double move_y = this->y + (bullet_speed * sin(bullet_direction * M_PI / 180));

    this->setPosition(move_x, move_y);
}

//Accessors
void Bullet::setBulletSpeed(double bullet_speed) {

    this->bullet_speed = bullet_speed;
}
double Bullet::getBulletSpeed() {

    return this->bullet_speed;
}
void Bullet::setBulletDirection(double bullet_direction) {

    this->bullet_direction = bullet_direction;
}
double Bullet::getBulletDirection() {

    return this->bullet_direction;
}

//Functions
void Bullet::create() {

    this->setSprite("../resource/Bullet.png");
}
void Bullet::update() {
    
    this->bulletMovement(this->bullet_speed, this->bullet_direction);

    this->setPosition(this->x, this->y);
}
void Bullet::render() {

    this->drawSelf();
}