#include "include/ParticleCircle.h"

//Functions
void ParticleCircle::update() {

    this->scale += -this->scale / 15;
}
void ParticleCircle::render() {

    this->r += (target_r - this->r) / 15;
    this->g += (target_g - this->g) / 15;
    this->b += (target_b - this->b) / 15;

    this->circle_shape.setRadius(this->radius * this->scale);
    this->circle_shape.setOrigin(sf::Vector2f(this->radius * this->scale, this->radius * this->scale));
    this->circle_shape.setPosition(this->x, this->y);
    this->circle_shape.setFillColor(sf::Color(this->r, this->g, this->b, this->alpha * 255));
    this->getRenderWindow()->draw(this->circle_shape);
}