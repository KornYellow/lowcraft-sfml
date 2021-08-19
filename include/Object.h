#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Instance.h"

using namespace std;
using namespace sf;

class Object {

    private:

        //Object
        string object_name;

        //RenderWindow
        RenderWindow* window;

        //Instances
        vector <Instance> instances;

    public: Object(string name, RenderWindow* window);

        //Instance functions
        void addInstance(Instance instance);
        Instance getInstance(int index);
        
        //Object functions
        void update();
        void draw();
};