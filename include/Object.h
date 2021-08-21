#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Instance.h"

using namespace std;
using namespace sf;

class Object {

    private:

        //Room
        string room_name;

        //Object
        string object_name;

        //RenderWindow
        RenderWindow* window;

        //Instances
        vector <Instance> instances;

    public: Object(string object_name, RenderWindow* window);

        //Room
        string getRoomName();
        void setRoomName(string room_name);

        //Window
        RenderWindow* getRenderWindow();  
        void setRenderWindow(RenderWindow* window);

        //Instance functions
        void addInstance(Instance instance);
        Instance getInstance(int index);
        
        //Object functions
        void update();
        void draw();
};