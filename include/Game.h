#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "include/Player.h"
#include "include/Conductor.h"

class Game {

    private :
        
        //RenderWindow
        sf::RenderWindow* render_window;
        sf::VideoMode video_mode;
        sf::Event event;

        //Player
        Player* player;

        //Conductor
        Conductor* conductor;

        //Initialize
        void initVariables();
        void initRenderWindow();
        void initPlayer();
        void initConductor();

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