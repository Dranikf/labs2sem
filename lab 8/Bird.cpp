#include "Bird.h"

Bird::Bird(sf::Texture * texture, sf::Vector2f sPos, sf::Vector2f size){

    position = sPos;
    this->texture = texture;
    this->size = size;

}

void Bird::Draw(sf::RenderWindow * window){

    sf::RectangleShape rectangle(size);

    rectangle.setTexture(texture);
    rectangle.setPosition(position);

    window->draw(rectangle);

}