#include "include/Game.h"

//Initialize
void Game::initVariables() {

    //RenderWindow
    this->render_window = nullptr;

    //Player
    this->player = nullptr;
}
void Game::initRenderWindow() {

    this->video_mode.width = 1920;
    this->video_mode.height = 1080; 

    this->render_window = new sf::RenderWindow(this->video_mode, "Rhythm Invader -- 1.0.0", sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen);
    this->render_window->setFramerateLimit(75);
    this->render_window->setMouseCursorVisible(false);
}
void Game::initPlayer() {

    this->player = new Player();
    this->player->setRenderWindow(this->render_window);
    this->player->create();
}
void Game::initConductor() { 

    this->conductor = new Conductor();
    this->conductor->setPlayer(this->player);
    
    //Choose music
    this->conductor->playMusic("Creatures Ov Deception");
    //this->conductor->playMusic("La Danse Macabre");
}

//Constructor and Destructor
Game::Game() {

    this->initVariables();
    this->initRenderWindow();
    this->initPlayer();
    this->initConductor();
}
Game::~Game() {

    //RenderWindow
    delete this->render_window;

    //Player
    delete this->player;

    //Conductor
    delete this->conductor;
}

//Accessors
const bool Game::isGameRunning() const {

    return this->render_window->isOpen();
}

//Functions
void Game::pollEvents() {

    while(this->render_window->pollEvent(this->event)) {
    
        switch(this->event.type) {

            case sf::Event::Closed :

                this->render_window->close();
                break;
            
            case sf::Event::KeyPressed :

                if(this->event.key.code == sf::Keyboard::Escape) {

                    this->render_window->close();
                }
                break;
        }
    }
}
void Game::update() {

    this->pollEvents();

    this->player->update();
    this->conductor->update();
}
void Game::render() {

    this->render_window->clear(sf::Color(0, 0, 0, 255));
    this->player->render();
    this->render_window->display(); 
}