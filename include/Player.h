#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "include/Entity.h"
#include "include/Bullet.h"

class Player : public Entity {

    private :

        double player_speed;
        double player_speed_h;
        double player_speed_v;

        double player_shoot_delay;
        double player_shoot_firerate;

        //Bullets
        std::vector <Bullet*> bullets;

        //Movement
        void playerMovement(double player_speed);
        void playerFollowMouse();
        void playerShootBullet();

        //Bullets
        void createBullet();
        void updateBullet();
        void renderBullet();
        void deleteBullet();

    public :

        //Functions
        void create();
        void update();
        void render();
};  