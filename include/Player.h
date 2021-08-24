#pragma once

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "include/Entity.h"

class Player : public Entity {

    private :

        double player_speed;
        double player_speed_h;
        double player_speed_v;

        //Movement
        void playerMovement(double player_speed);
        void playerFollowMouse();

    public :

        //Functions
        void create();
        void update();
        void render();
};  