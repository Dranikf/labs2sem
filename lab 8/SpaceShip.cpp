#include "SpaceShip.h"

SpaceShip::SpaceShip(sf::Texture * texture, sf::Vector2f sPos, sf::Vector2f size){

    position = sPos;
    this->texture = texture;
    this->size = size;

}

void SpaceShip::Draw(sf::RenderWindow * window){

    sf::RectangleShape rectangle(size);

    rectangle.setTexture(texture);
    rectangle.setPosition(position);

    window->draw(rectangle);

}
