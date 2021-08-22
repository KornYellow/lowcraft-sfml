#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Object.h"

using namespace std;
using namespace sf;

class Instance {

    private:

        //Instance
        bool is_visible;

        double direction;
        double h_speed;
        double v_speed;
        double speed;

        Texture texture;
        Sprite sprite;

        int sprite_width;
        int sprite_height;

        //RenderWindow
        RenderWindow *render_window;

        //Keyboard
        vector <bool> is_key_pressed;

    public:
        
        //General
        double x;
        double y;

        virtual void create();
        virtual void update();
        virtual void draw();
        
        Instance(): is_key_pressed(999) {}

        //Object
        string getObjectName();
        void setObjectName(string object_name);

        //Sprite and Texture
        void setTexture(string filename);
        Texture getTexture();
        int getSpriteWidth();
        int getSpriteHeight();

        //Window
        RenderWindow* getRenderWindow();  
        void setRenderWindow(RenderWindow* render_window); 

        //Instances functions
        void drawSelf();
        void setOrigin(double x, double y);

        //Movement and Position functions
        void setPosition(double x, double y);

        //Keyboard
        bool keyboardCheck(Keyboard::Key key);
        bool keyboardCheckPressed(Keyboard::Key key);
};