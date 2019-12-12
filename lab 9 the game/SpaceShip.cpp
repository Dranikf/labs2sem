#include "SpaceShip.h"

SpaceShip::SpaceShip(sf::Texture * texture, sf::Vector2f sPos, sf::Vector2f size) : SpaceObject(texture, sPos, size){


}

void SpaceShip::Draw(sf::RenderWindow * window){

    sf::RectangleShape rectangle(size);

    rectangle.setTexture(texture);
    rectangle.setPosition(position);
    rectangle.setRotation(rotationAng);

    window->draw(rectangle);


}

void SpaceShip::setRotation(float ange){

    rotationAng = ange;

}