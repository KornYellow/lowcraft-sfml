#include "include/Particle.h"

//Initialize
void Particle::initVariables() {
    
    //RenderWindow
    this->render_window = nullptr;
}

//Constructor and Destructor
Particle::Particle() {
    
    this->initVariables();

    this->scale = 1;
    this->alpha = 1;
    this->rotation = 0;
}
Particle::~Particle() {

}

//Accessors
int Particle::getSpriteWidth() {

    return this->sprite_width;
}
int Particle::getSpriteHeight() {
    
    return this->sprite_height;
}
void Particle::setRenderWindow(sf::RenderWindow* render_window) {

    this->render_window = render_window;
}
sf::RenderWindow* Particle::getRenderWindow() {

    return this->render_window;
}
void Particle::setSprite(std::string sprite_path) {

    this->texture.loadFromFile(sprite_path);
    this->sprite_width = this->texture.getSize().x;
    this->sprite_height = this->texture.getSize().y;

    this->sprite.setTexture(this->texture);
    this->sprite.setOrigin(sf::Vector2f(this->sprite_width / 2, this->sprite_height / 2));
    this->sprite.setPosition(this->x, this->y);
}
sf::Sprite Particle::getSprite() {

    return this->sprite;
}
void Particle::setPosition(double x, double y) {

    this->x = x;
    this->y = y;
}
sf::Vector2f Particle::getPosition() {
    
    return sf::Vector2f(this->x, this->y);
}

//Functions
void Particle::update() {

    this->scale += -this->scale / 10;
}
void Particle::render() {

    this->drawSelf();
}
void Particle::drawSelf() {

    this->sprite.setPosition(this->x, this->y);
    this->sprite.setScale(sf::Vector2f(this->scale, this->scale));
    this->sprite.setRotation(this->rotation);
    this->sprite.setColor(sf::Color::White);
    this->render_window->draw(this->sprite);
}