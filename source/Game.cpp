#include "include/Game.h"

//Initialize
void Game::initVariables() {

    //RenderWindow
    this->render_window = nullptr;

    //Player
    this->player = nullptr;
}
void Game::initRenderWindow() {

    this->video_mode.width = 1280;
    this->video_mode.height = 720; 

    this->render_window = new sf::RenderWindow(this->video_mode, "Rhythm Invader -- 1.0.0", sf::Style::Titlebar | sf::Style::Close);
}
void Game::initPlayer() {

    this->player = new Player();
    this->player->setRenderWindow(this->render_window);
    this->player->create();
}

//Constructor and Destructor
Game::Game() {

    this->initVariables();
    this->initRenderWindow();
    this->initPlayer();
}
Game::~Game() {

    //RenderWindow
    delete this->render_window;
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
}
void Game::render() {

    this->render_window->clear(sf::Color(120, 120, 120, 255));
    this->player->render();
    this->render_window->display();
}