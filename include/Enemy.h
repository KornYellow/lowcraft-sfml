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

        double enemy_x_togo;
        double enemy_y_togo;

        double enemy_speed_h;
        double enemy_speed_v;

    public :

        //Movement
        void setPositionTogo(double x, double y);

        void enemyHurt();

        //Functions
        void create();
        void update();
        void render();
};  