#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "include/Entity.h"
#include "include/BulletPlayer.h"
#include "include/BulletEnemy.h"
#include "include/Randomize.h"
#include "include/Enemy.h"
#include "include/EnemyWave.h"

class EnemyWave;
class Player : public Entity {

    private :

        double player_speed;
        double player_speed_h;
        double player_speed_v;

        double player_shoot_delay;
        double player_shoot_firerate;

        //Enemies
        std::vector <EnemyWave*> enemy_waves;
        std::vector <Enemy*> enemies;

        //Bullets
        std::vector <BulletPlayer*> bullets_player;
        std::vector <BulletEnemy*> bullets_enemy;

        //Movement
        void playerMovement(double player_speed);
        void playerFollowMouse();
        void playerShootBullet();

    public :

        //EnemyWave
        void moveEnemyWave(double x, double y);
        void moveEnemyWave();
        void createEnemyWave(double x, double y, int enemy_count, int enemy_count_row, int wave_gap);
        void updateEnemyWave();
        void renderEnemyWave();

        //Enemies
        void createEnemy(double x, double y);
        void updateEnemy();
        void renderEnemy();
        void deleteEnemy();

        //Bullets
        std::vector <BulletPlayer*> getBulletsPlayer();
        void createBulletPlayer(double x, double y, double speed, int direction);
        void updateBulletPlayer();
        void renderBulletPlayer();
        void deleteBulletPlayer();

        void createBulletEnemy(double x, double y, double speed, int direction, std::string type);
        void updateBulletEnemy();
        void renderBulletEnemy();
        void deleteBulletEnemy();

        void createBulletEnemyCircle(double x, double y, double speed, int quality, std::string type);

        //Functions
        void create();
        void update();
        void render();
};  