#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "include/Particle.h"

class ParticleCircle : public Particle {

    private :

        //Shape
        sf::CircleShape circle_shape;

    public :

        //Properties
        int radius;
        int r;
        int g;
        int b;
        int target_r;
        int target_g;
        int target_b;

        //Functions
        void update();
        void render();
};  