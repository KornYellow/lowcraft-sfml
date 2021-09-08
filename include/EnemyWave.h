#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "include/Entity.h"
#include "include/Randomize.h"
#include "include/Enemy.h"
#include "include/Player.h"

class Player;
class EnemyWave : public Entity {

    private :

        double enemy_wave_x_togo;
        double enemy_wave_y_togo;
        double enemy_wave_speed;
        int enemy_wave_move_direction;
        
        double wave_border_left;
        double wave_border_right;
        double wave_border_max_left;
        double wave_border_max_right;
        double wave_gap;

        int enemy_count_column;
        int enemy_count_row;
        int enemy_size;
        int enemy_variation;

        //Player
        Player* player;

        //Enemies
        std::vector <Enemy*> enemies;

    public :

        //Accessors
        void setPlayer(Player* player);
        Player* getPlayer();
        void setEnemyCountColumn(int enemy_count_column);
        void setEnemyCountRow(int enemy_count_row);
        void setWaveGap(int wave_gap);

        //Movement
        void moveEnemyWave();
        void moveEnemyWave(double x, double y);

        //Enemies
        std::vector <Enemy*> getEnemies();
        void createEnemy(double x, double y);
        void updateEnemy();
        void renderEnemy();
        void deleteEnemy();

        //Functions
        void create();
        void update();
        void render();
};  