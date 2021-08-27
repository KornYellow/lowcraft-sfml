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

class Player : public Entity {

    private :

        double player_speed;
        double player_speed_h;
        double player_speed_v;

        double player_shoot_delay;
        double player_shoot_firerate;

        //Bullets
        std::vector <BulletPlayer*> bullets_player;
        std::vector <BulletEnemy*> bullets_enemy;
        
        //Movement
        void playerMovement(double player_speed);
        void playerFollowMouse();
        void playerShootBullet();

    public :

        //Bullets
        void createBulletPlayer();
        void updateBulletPlayer();
        void renderBulletPlayer();
        void deleteBulletPlayer();

        void createBulletEnemy(double x, double y, double speed, int direction, std::string type);
        void updateBulletEnemy();
        void renderBulletEnemy();
        void deleteBulletEnemy();

        //Functions
        void create();
        void update();
        void render();
};  