#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Room.h"
#include "include/Game.h"
#include "include/Object.h"

using namespace std;
using namespace sf;

class Room {

    private:

        //Game
        Game* game;

        //Room
        string room_name;

        //RenderWindow
        RenderWindow* render_window;

        //Objects
        vector <Object> objects;

    public:

        //Game
        void setGame(Game* game);
        Game* getGame();

        //Room
        void setRoomName(string room_name);
        string getRoomName();

        void update();
        void draw();

        //RenderWindow
        void setRenderWindow(RenderWindow* render_window);
        RenderWindow* getRenderWidnow();

        //Object
        void addObject(Object* object);
        Object* getObject(int index);
};