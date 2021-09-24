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

    if(this->bullet_type == "Rectangle Tiny") {
        
        this->setSprite("../resource/RectangleTiny.png");
        this->createParticleCircle(this->x, this->y, 32, 255, 255, 255, 255, 85, 85);
    }
    else if(this->bullet_type == "Rectangle Small") {
        
        this->setSprite("../resource/RectangleSmall.png");
        this->createParticleCircle(this->x, this->y, 48, 255, 255, 255, 255, 85, 85);
    }
    else if(this->bullet_type == "Rectangle") {
        
        this->setSprite("../resource/Rectangle.png");
        this->createParticleCircle(this->x, this->y, 64, 255, 255, 255, 255, 85, 85);
    }
    else if(this->bullet_type == "Rectangle Large") {
        
        this->setSprite("../resource/RectangleLarge.png");
        this->createParticleCircle(this->x, this->y, 96, 255, 255, 255, 255, 85, 85);
    }
    else if(this->bullet_type == "Rectangle Huge") {
        
        this->setSprite("../resource/RectangleHuge.png");
        this->createParticleCircle(this->x, this->y, 144, 255, 255, 255, 255, 85, 85);
    }
    else {

        std::cout << "ERROR: bullet type not found." << std::endl;
        abort();
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
    this->rotation += (double)60 / (double)this->getSpriteWidth();
    this->drawSelf();
}