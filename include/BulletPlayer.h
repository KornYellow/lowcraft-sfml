#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "include/Bullet.h"

class BulletPlayer : public Bullet {

    private :

    public :

        //Functions
        void create();
        void update();
        void render();
};  