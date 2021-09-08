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
        this->createParticleCircle(this->x, this->y, 64, 255, 255, 255, 255, 85, 85);
    }
    this->rotation = Randomize::randomInt(360);
}
void BulletEnemy::update() {

    this->bulletMovement(this->bullet_speed, this->bullet_direction);

    this->setPosition(this->x, this->y);

    //Particles
    this->setParticlePosition(this->x, this->y);
    this->updateParticle();
    this->deleteParticle();
}
void BulletEnemy::render() {

    //Particles
    this->renderParticle();

    //BulletEnemy
    this->getSprite()->setRotation(this->rotation);
    this->rotation+= 2;
    this->drawSelf();
}