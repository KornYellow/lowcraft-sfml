#include "include/BulletEnemy.h"

//Accessors
void BulletEnemy::setBulletType(std::string type) {

    this->bullet_type = type;
}
std::string BulletEnemy::getBulletType() {

    return this->bullet_type;
} 

//Functions
void BulletEnemy::create() {

    if(this->bullet_type == "Rectangle") {
        
        this->setSprite("../resource/Rectangle.png");
    }
}
void BulletEnemy::update() {

    this->bulletMovement(this->bullet_speed, this->bullet_direction);

    this->setPosition(this->x, this->y);
}
void BulletEnemy::render() {

    this->drawSelf();
}