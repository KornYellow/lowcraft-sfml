#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Game {

    private :
        
        //RenderWindow
        sf::RenderWindow* render_window;
        sf::VideoMode video_mode;
        sf::Event event;

        //Initialize
        void initVariables();
        void initRenderWindow();

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