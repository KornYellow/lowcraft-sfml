#include "include/Enemy.h"

void Enemy::enemyHurt() {

    this->flash = 5;  
    this->health --;
}

//Functions
void Enemy::setPositionTogo(double x, double y) {

    this->enemy_x_togo = x;
    this->enemy_y_togo = y;
}
void Enemy::create() {

    this->flash = 0;
    this->enemy_speed_h = 0;
    this->enemy_speed_v = 0;
    this->health = 10;

    this->x = this->getRenderWindow()->getSize().x / 2;
    this->y = -64;
    this->enemy_x_togo = this->x;
    this->enemy_y_togo = this->y;

    this->setSprite("../resource/EnemyNormal_1.png");
}
void Enemy::update() {

    //Particle
    this->setParticlePosition(this->x, this->y);
    this->updateParticle();
    this->deleteParticle();

    //Enemy
    this->x += (this->enemy_x_togo - this->x) / 6;
    this->y += (this->enemy_y_togo - this->y) / 6;

    this->setPosition(this->x, this->y);
}
void Enemy::render() {

    //Particle
    this->renderParticle();

    //Enemy
    if(this->flash > 0) {

        this->flash --;
        sf::Shader shader;
        shader.loadFromFile("shader/tint.frag", sf::Shader::Fragment);
        shader.setUniform("flashColor", sf::Glsl::Vec4(1, 1, 1, 1));

        this->getSprite()->setPosition(this->x, this->y);
        this->getRenderWindow()->draw(*this->getSprite(), &shader);
    }
    else {
        
        this->setAlpha(1);
        if(!this->is_dead) this->drawSelf();
    }
}

//Accessors
void Enemy::setEnemyHealth(int health) {

    this->health = health;
}
int Enemy::getEnemyHealth() {

    return this->health;
}
void Enemy::setIsDead(bool is_dead) {

    this->is_dead = is_dead;
}
bool Enemy::getIsDead() {

    return this->is_dead;
}