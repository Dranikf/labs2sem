#include "SpaceObject.h"

SpaceObject::SpaceObject(sf::Texture * texture, sf::Vector2f sPos, sf::Vector2f size){

    position = sPos;
    this->texture = texture;
    this->size = size;

}

void SpaceObject::Draw(sf::RenderWindow * window){

    sf::RectangleShape rectangle(size);

    rectangle.setTexture(texture);
    rectangle.setPosition(position);

    window->draw(rectangle);

}
