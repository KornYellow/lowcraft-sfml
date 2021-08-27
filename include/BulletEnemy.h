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

class BulletEnemy : public Bullet {

    private :

        //Type
        std::string bullet_type;

    public :

        //Accesssors
        void setBulletType(std::string type);
        std::string getBulletType(); 

        //Functions
        void create();
        void update();
        void render();
};  