#include "SpaceComet.h"
#include <iostream>

SpaceComet::SpaceComet(sf::Texture * texture, sf::Vector2f sPos
    , sf::Vector2f size, sf::Vector2f direction) 
    : SpaceObject(texture, sPos, size){

        this->direction = direction;

}

void SpaceComet::Draw(sf::RenderWindow * window){

    // пририсую кометам хвосты

    sf::CircleShape hv;
    hv.setFillColor(sf::Color(200, 50, 50));

    float sRad = size.y /2;

    for(float i = sRad ; i > 0; i -= 4.0){

        hv.setRadius(i);
        hv.setPosition((position + (direction * ((sRad-i) * 2))));

        
        window->draw(hv);

    }

    sf::RectangleShape rectangle(size);

    rectangle.setTexture(texture);
    rectangle.setPosition(position);
    
    window->draw(rectangle);

}