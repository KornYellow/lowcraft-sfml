#pragma once

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Entity {

    private :  

        //RenderWindow
        sf::RenderWindow* render_window;

        //Sprite and Texture
        sf::Sprite* sprite;
        sf::Texture* texture;
        int sprite_width;
        int sprite_height;

        //Entity
        sf::Vector2f position;

        //Initialize
        void initVariables();
        void initSpriteAndTexture();

    public : 

        //Constructor and Destructor
        Entity();
        virtual ~Entity();

        //Accessor
        void setRenderWindow(sf::RenderWindow* render_window);
        sf::RenderWindow* getRenderWindow();

        void setSprite(std::string sprite_path);
        sf::Sprite* getSprite();

        void setPosition(sf::Vector2f position);
        sf::Vector2f getPosition();

        //Functions
        virtual void create();
        virtual void update();
        virtual void render();

        void drawSelf();
};