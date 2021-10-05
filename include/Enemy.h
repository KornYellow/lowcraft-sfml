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

class Enemy : public Entity {

    private :

        int flash;
        int health;
        bool is_dead;

        double enemy_x_togo;
        double enemy_y_togo;

        double enemy_speed_h;
        double enemy_speed_v;

    public :

        //Accessor
        void setEnemyHealth(int health);
        int getEnemyHealth();
        void setIsDead(bool is_dead);
        bool getIsDead();

        //Movement
        void setPositionTogo(double x, double y);

        //Enemy Hurt
        void enemyHurt();

        //Functions
        void create();
        void update();
        void render();
};  