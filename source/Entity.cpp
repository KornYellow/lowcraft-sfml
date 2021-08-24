#include "include/Entity.h"

//Constructor and Destructor
Entity::Entity() {

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

}
