#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Instance.h"

using namespace std;
using namespace sf;

class BaseInstance : public Instance {

    private:

    public:

        //Base functions
        void create();
        void update();
        void draw();
};