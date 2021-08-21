#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Object.h"

using namespace std;
using namespace sf;

class Room {

    private:

        //Room
        string room_name;

        //RenderWindow
        RenderWindow* window;

        //Objects
        vector <Object> objects;

    public: Room(string room_name, RenderWindow* window);

        //Object functions
        void addObject(Object object);
        Object getObject(int index);
        
        //Room functions
        void update();
        void draw();
};