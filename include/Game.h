#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "include/Player.h"

class Game {

    private :
        
        //RenderWindow
        sf::RenderWindow* render_window;
        sf::VideoMode video_mode;
        sf::Event event;

        //Player
        Player* player;

        //Initialize
        void initVariables();
        void initRenderWindow();
        void initPlayer();

    public :

        //Constructor and Destructor
        Game();
        virtual ~Game();

        //Accessors
        const bool isGameRunning() const;

        //Functions
        void pollEvents();
        void update();
        void render();
};