#include "include/Entity.h"

//Initialize
void Entity::initVariables() {
    
    //RenderWindow
    this->render_window = nullptr;

    //Sprite and Texture
    this->sprite = nullptr;
    this->texture = nullptr;
}
void Entity::initSpriteAndTexture() {

    this->sprite = new sf::Sprite();
    this->texture = new sf::Texture();
}

//Constructor and Destructor
Entity::Entity() {

    this->initVariables();
    this->initSpriteAndTexture();
}
Entity::~Entity() {

}

//Accessors
void Entity::setRenderWindow(sf::RenderWindow* render_window) {

    this->render_window = render_window;
}
sf::RenderWindow* Entity::getRenderWindow() {

    return this->render_window;
}
void Entity::setSprite(std::string sprite_path) {

    this->texture->loadFromFile(sprite_path);
    this->sprite_width = this->texture->getSize().x;
    this->sprite_height = this->texture->getSize().y;

    this->sprite->setTexture(*this->texture);
    this->sprite->setOrigin(sf::Vector2f(this->sprite_width / 2, this->sprite_height / 2));
    this->sprite->setPosition(this->position);
}
sf::Sprite* Entity::getSprite() {

    return this->sprite;
}
void Entity::setPosition(sf::Vector2f position) {

    this->position = position;
}
sf::Vector2f Entity::getPosition() {
    
    return this->position;
}

//Functions
void Entity::create() {

}
void Entity::update() {

}
void Entity::render() {

    this->drawSelf();
}

void Entity::drawSelf() {

    this->render_window->draw(*this->sprite);
}

