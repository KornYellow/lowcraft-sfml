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

    public :

        //Movement
        double bullet_speed;
        double bullet_direction;
        
        void bulletMovement(double bullet_speed, double bullet_direction);

        //Accessors
        void setBulletSpeed(double bullet_speed);
        double getBulletSpeed();
        void setBulletDirection(double bullet_direction);
        double getBulletDirection();

        //Functions
        virtual void create();
        virtual void update();
        virtual void render();
};  