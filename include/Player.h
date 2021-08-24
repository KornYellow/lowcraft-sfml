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

    public :

        //Functions
        void create();
        void update();
        void render();

};