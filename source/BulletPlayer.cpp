#include "include/BulletPlayer.h"

//Functions
void BulletPlayer::create() {

    this->setSprite("../resource/Bullet.png");
}
void BulletPlayer::update() {

    this->bulletMovement(this->bullet_speed, this->bullet_direction);

    this->setPosition(this->x, this->y);
}
void BulletPlayer::render() {

    this->drawSelf();
}