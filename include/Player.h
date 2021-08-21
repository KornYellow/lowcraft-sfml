#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Instance.h"

using namespace std;
using namespace sf;

class Player : public Instance {

    private:
        
        //Player Movement
        double player_speed_h;
        double player_speed_v;
        double player_speed;

    public:

        //Player Movement
        void setPlayerSpeed(double player_speed);
        double getPlayerSpeed();

        void playerMovement(double player_speed);

        //Base functions
        void create();
        void update();
        void draw();
};