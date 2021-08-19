#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Instance {

    private:

        //General
        double x;
        double y;
        bool is_visible;

        //Movement and Position
        double direction;
        double h_speed;
        double v_speed;
        double speed;

        //Window
        RenderWindow *window;

        //Sprite and Texture
        Texture texture;
        Sprite sprite;

        int sprite_width;
        int sprite_height;

    public:
        
        //Sprite and Texture
        void setTexture(string filename);
        Texture getTexture();
        int getSpriteWidth();
        int getSpriteHeight();

        //Window
        RenderWindow* getRenderWindow();  
        void setRenderWindow(RenderWindow* window); 

        //Instances functions
        void create();
        void update();
        void draw();

        void drawSelf();
        void setOrigin(double x, double y);

        //Movement and Position functions
        void setPosition(double x, double y);
        double getX();
        double getY();
};