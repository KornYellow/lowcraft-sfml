#include "include/EnemyWave.h"

//Functions
void EnemyWave::create() {

    //EnemyWave
    this->enemy_variation = 1;
    this->enemy_wave_move_direction = 1;

    this->enemy_wave_x_togo = this->x;
    this->enemy_wave_y_togo = this->y;

    //Enemy
    for(int i = 0; i < this->enemy_count_column * this->enemy_count_row; i++) {

        this->createEnemy(this->x, this->y);
    }

    //EnemyWave
    this->wave_gap = 25;
    this->enemy_size = this->enemies.at(0)->getSpriteWidth();
    int window_width = this->getRenderWindow()->getSize().x;
    int enemy_wave_x = (((enemy_size * this->enemy_count_column) + (this->wave_gap * this->enemy_count_column - 1)) / 2);
    this->enemy_wave_x_togo = (window_width / 2) - enemy_wave_x + (enemy_size / 2) + (this->wave_gap / 2) - 1;
    this->x = this->enemy_wave_x_togo;

    this->wave_border_left = (window_width / 2) - enemy_wave_x;
    this->wave_border_right = (window_width / 2) + enemy_wave_x;

    this->wave_border_max_left = 200;
    this->wave_border_max_right = window_width - 200;

    this->enemy_wave_speed = enemy_size + this->wave_gap;

    this->createParticleCircle(window_width / 2, -8, 255, 255, 255, 255, 255, 85, 85);
}
void EnemyWave::update() {

    //Particle
    this->updateParticle();
    this->deleteParticle();

    //EnemyWave
    this->x += (this->enemy_wave_x_togo - this->x) / 6;
    this->y += (this->enemy_wave_y_togo - this->y) / 6;

    for(int i = 0; i < this->enemy_count_row; i++) {
        for(int j = 0; j < this->enemy_count_column; j++) {
            
            int index = (this->enemy_count_column * i) + j;

            int var_y = 5 * this->enemy_variation;
            if(index % 2 == 0 && index % (this->enemy_count_column * 2) < this->enemy_count_column) var_y *= -1;
            else if(index % 2 == 1 && index % (this->enemy_count_column * 2) >= this->enemy_count_column) var_y *= -1;

            this->enemies.at(index)->setPositionTogo(this->x + (j * (this->enemy_size + this->wave_gap)), this->y + (i * (this->enemy_size + this->wave_gap)) + var_y);
        }
    }

    //Enemy
    this->updateEnemy();
}
void EnemyWave::render() {

    //Particle
    this->renderParticle();

    //Enemy
    this->renderEnemy();
}

//Accessors
void EnemyWave::setPlayer(Player* player) {

    this->player = player;
}
Player* EnemyWave::getPlayer() {

    return this->player;
}
void EnemyWave::setEnemyCountColumn(int enemy_count_column) {

    this->enemy_count_column = enemy_count_column;
}
void EnemyWave::setEnemyCountRow(int enemy_count_row) {

    this->enemy_count_row = enemy_count_row;
}
void EnemyWave::setWaveGap(int wave_gap) {

    this->wave_gap = wave_gap;
}

//Movement
void EnemyWave::moveEnemyWave(double x, double y) {

    this->enemy_wave_x_togo += x;
    this->enemy_wave_y_togo += y;

    this->wave_border_left += x;
    this->wave_border_left += x;
}
void EnemyWave::moveEnemyWave() {

    int move_x = this->enemy_wave_speed * this->enemy_wave_move_direction;
    if(this->wave_border_right + move_x > this->wave_border_max_right || this->wave_border_left + move_x < this->wave_border_max_left) {

        this->enemy_wave_move_direction = -this->enemy_wave_move_direction;

        this->enemy_wave_y_togo += this->enemy_wave_speed / 2;
    }
    else {

        this->enemy_wave_x_togo += move_x;

        this->wave_border_left += move_x;
        this->wave_border_right += move_x;
    }

    this->enemy_variation = -this->enemy_variation;
} 

//Enemy
std::vector <Enemy*> EnemyWave::getEnemies() {

    return this->enemies;
}
void EnemyWave::createEnemy(double x, double y) {

    Enemy* enemy = new Enemy();
    enemy->setRenderWindow(this->getRenderWindow());
    enemy->setPosition(x, y);
    enemy->create();

    this->enemies.push_back(enemy);
}
void EnemyWave::updateEnemy() {

    for(int i = 0; i < this->enemies.size(); i++) {

        this->enemies.at(i)->update();

        //Create Bullet
        /*
        if(Randomize::randomInt(500) == 0) {

            this->player->createBulletEnemy(this->enemies.at(i)->x, this->enemies.at(i)->y, 7, 90, "Rectangle");
        }
        */

        //Do bullet hit enemies
        for(int j = 0; j < this->player->getBulletsPlayer().size(); j++) {

            //Collision
            if(this->player->getBulletsPlayer().at(j)->x > this->enemies.at(i)->x - 32 && this->player->getBulletsPlayer().at(j)->x < this->enemies.at(i)->x + 32) {

                if(this->player->getBulletsPlayer().at(j)->y > this->enemies.at(i)->y - 32 && this->player->getBulletsPlayer().at(j)->y < this->enemies.at(i)->y + 32) {

                    this->enemies.at(i)->enemyHurt();
                    this->player->getBulletsPlayer().at(j)->setBulletSpeed(99999); 
                }
            } 
        }
    }
}
void EnemyWave::renderEnemy() {

    for(int i = 0; i < this->enemies.size(); i++) {

        this->enemies.at(i)->render();
    }

    //Debug
    /*
    sf::RectangleShape line;
    line.setSize(sf::Vector2f(2, 1080));
    line.setOrigin(sf::Vector2f(1, 0));
    line.setFillColor(sf::Color::White);

    line.setPosition(this->wave_border_left, 0);
    this->getRenderWindow()->draw(line);

    line.setPosition(this->wave_border_right, 0);
    this->getRenderWindow()->draw(line);
    
    line.setPosition(this->wave_border_max_left, 0);
    this->getRenderWindow()->draw(line);

    line.setPosition(this->wave_border_max_right, 0);
    this->getRenderWindow()->draw(line);

    line.setPosition(this->getRenderWindow()->getSize().x / 2, 0);
    this->getRenderWindow()->draw(line);
    */
}
void EnemyWave::deleteEnemy() {

}