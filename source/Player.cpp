#include "include/Player.h"

//Functions
void Player::create() {

    this->player_speed_h = 0;
    this->player_speed_v = 0;
    this->player_speed = 6;

    this->player_shoot_delay = 0;
    this->player_shoot_firerate = 5;

    this->setSprite("../resource/Player.png");
}
void Player::update() {
    
    //Particle
    this->updateParticle();
    this->deleteParticle();

    //Player
    this->playerFollowMouse();
    this->playerShootBullet();

    this->setPosition(this->x, this->y);
    
    //Bullets
    this->updateBulletPlayer();
    this->deleteBulletPlayer();

    this->updateBulletEnemy();
    this->deleteBulletEnemy();

    //Enemy
    this->updateEnemyWave();
    this->updateEnemy();
}
void Player::render() {

    //Particle
    this->renderParticle();

    //Bullets
    this->renderBulletEnemy();
    this->renderBulletPlayer();

    //Enemy
    this->renderEnemyWave();
    this->renderEnemy();

    //Player
    this->drawSelf();
}

//EnemyWave
void Player::moveEnemyWave(double x, double y) {

    for(int i = 0; i < this->enemy_waves.size(); i++) {

        this->enemy_waves.at(i)->moveEnemyWave(x, y);
    }
}
void Player::moveEnemyWave() {

    for(int i = 0; i < this->enemy_waves.size(); i++) {

        this->enemy_waves.at(i)->moveEnemyWave();
    }
}
void Player::createEnemyWave(double x, double y, int enemy_count, int enemy_count_row, int wave_gap) {

    EnemyWave* enemy_wave = new EnemyWave();
    enemy_wave->setPlayer(this);
    enemy_wave->setRenderWindow(this->getRenderWindow());
    enemy_wave->setEnemyCountColumn(enemy_count);
    enemy_wave->setEnemyCountRow(enemy_count_row);
    enemy_wave->setWaveGap(wave_gap);
    enemy_wave->setPosition(x, y);
    enemy_wave->create();
    
    this->enemy_waves.push_back(enemy_wave);
}
void Player::updateEnemyWave() {

    for(int i = 0; i < this->enemy_waves.size(); i++) {
        
        this->enemy_waves.at(i)->update();
    }
}
void Player::renderEnemyWave() {

    for(int i = 0; i < this->enemy_waves.size(); i++) {
        
        this->enemy_waves.at(i)->render();
    }
}

//Enemy
void Player::createEnemy(double x, double y) {

    Enemy* enemy = new Enemy();
    enemy->create();
    enemy->setRenderWindow(this->getRenderWindow());
    enemy->setPosition(x, y);

    this->enemies.push_back(enemy);
}
void Player::updateEnemy() {

    for(int i = 0; i < this->enemies.size(); i++) {

        this->enemies.at(i)->update();
    }
}
void Player::renderEnemy() {

    for(int i = 0; i < this->enemies.size(); i++) {

        this->enemies.at(i)->render();
    }
}
void Player::deleteEnemy() {

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
std::vector <BulletPlayer*> Player::getBulletsPlayer() {

    return this->bullets_player;
}
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
        
        //Do bullet hit enemies
        for(int j = 0; j < this->enemies.size(); j++) {

            //Collision
            if(this->bullets_player.at(i)->x > this->enemies.at(j)->x - 32 && this->bullets_player.at(i)->x < this->enemies.at(j)->x + 32) {

                if(this->bullets_player.at(i)->y > this->enemies.at(j)->y - 32 && this->bullets_player.at(i)->y < this->enemies.at(j)->y + 32) {

                    this->enemies.at(j)->enemyHurt();
                    this->bullets_player.erase(this->bullets_player.begin() + i);
                }
            } 
        }
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

void Player::createBulletEnemyCircle(double x, double y, double speed, int quality, std::string type) {

    double start_direction = atan2((this->y - y), (this->x - x)) * (180 / M_PI);
    for(int i = 0; i < (float)360 * (quality / (float)100); i++) {
        this->createBulletEnemy(x, y, speed, start_direction + (float)i * ((float)100 / quality), type);
    }
}