#ifndef _SPACE_COMET_H
#define _SPACE_COMET_H

#include "SpaceObject.h"

class SpaceComet: public SpaceObject
{
private:
    sf::Vector2f direction;
public:
    SpaceComet(sf::Texture * texture, sf::Vector2f sPos
    , sf::Vector2f size, sf::Vector2f direction);

    void Draw(sf::RenderWindow * window);
};


#endif