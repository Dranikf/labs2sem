#ifndef _SPACE_SHIP_H_
#define _SPACE_SHIP_H_

#include "SpaceObject.h"

class SpaceShip: public SpaceObject
{
private:

    float rotationAng = 0;

public:
    SpaceShip(sf::Texture * texture, sf::Vector2f sPos, sf::Vector2f size);

    void Draw(sf::RenderWindow * window);
    void setRotation(float ange);
    
};

#endif