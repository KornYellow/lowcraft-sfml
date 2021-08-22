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

        //Object
        string object_name;

        //RenderWindow
        RenderWindow* render_window;

        //Instances
        vector <Instance> instances;

    public:

        //Object
        void setObjectName(string object_name);
        string getObjectName();

        void update();
        void draw();

        //RenderWindow
        void setRenderWindow(RenderWindow* render_window);
        RenderWindow* getRenderWindow();  

        //Instance
        void addInstance(Instance* instance);
        Instance* getInstance(int index);
};