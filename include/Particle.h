#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Particle {

    private :

        //RenderWindow
        sf::RenderWindow* render_window;

        //Sprite and Texture
        sf::Sprite sprite;
        sf::Texture texture;
        int sprite_width;
        int sprite_height;

        //Initialize
        void initVariables();

    public :

        //Movement and Position
        double x;
        double y;
        double scale;
        double alpha;
        double rotation;

        //Constructor and Destructor
        Particle();
        virtual ~Particle();

        //Accessor
        int getSpriteWidth();
        int getSpriteHeight();

        void setRenderWindow(sf::RenderWindow* render_window);
        sf::RenderWindow* getRenderWindow();

        void setSprite(std::string sprite_path);
        sf::Sprite getSprite();

        void setPosition(double x, double y);
        sf::Vector2f getPosition();

        //Functions
        virtual void update();
        virtual void render();

        void drawSelf();
};  