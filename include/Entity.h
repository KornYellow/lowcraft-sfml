#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "include/Particle.h"
#include "include/ParticleCircle.h"

class Entity {

    private :  

        //RenderWindow
        sf::RenderWindow* render_window;

        //Particles
        std::vector <Particle*> particles;

        //Sprite and Texture
        sf::Sprite* sprite;
        sf::Texture texture;
        int sprite_width;
        int sprite_height;

        //Keyboard and Mouse
        std::vector <int> is_key_pressed;
        std::vector <int> is_mouse_pressed;

        //Initialize
        void initVariables();

    public : 

        //Entity
        double x;
        double y;
        double rotation;

        //Constructor and Destructor
        Entity();
        virtual ~Entity();

        //Accessor
        int getSpriteWidth();
        int getSpriteHeight();

        void setRenderWindow(sf::RenderWindow* render_window);
        sf::RenderWindow* getRenderWindow();

        void setSprite(std::string sprite_path);
        sf::Sprite* getSprite();

        void setPosition(double x, double y);
        sf::Vector2f getPosition();

        //Functions
        virtual void create();
        virtual void update();
        virtual void render();

        void drawSelf();

        //Keyboard and Mouse
        bool keyboardCheck(sf::Keyboard::Key key);
        bool keyboardCheckPressed(sf::Keyboard::Key key);
        bool mouseCheck(sf::Mouse::Button key);
        bool mouseCheckPressed(sf::Mouse::Button key);
        sf::Vector2f getMousePosition();

        //Particles
        std::vector <Particle*> getParticles();
        void createParticleCircle(double x, double y, int radius, int r, int g, int b, int target_r, int target_g, int target_b);
        void setParticlePosition(double x, double y);
        void updateParticle();
        void renderParticle();
        void deleteParticle();

        //Bounding Box
        bool isOutOfRenderWindow();
};