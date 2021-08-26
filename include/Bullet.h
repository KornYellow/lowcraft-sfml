#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "include/Entity.h"

class Bullet : public Entity {

    private :

        double bullet_speed;
        double bullet_direction;

        //Movement
        void bulletMovement(double bullet_speed, double bullet_direction);

    public :

        //Accessors
        void setBulletSpeed(double bullet_speed);
        double getBulletSpeed();
        void setBulletDirection(double bullet_direction);
        double getBulletDirection();

        //Functions
        void create();
        void update();
        void render();
};  