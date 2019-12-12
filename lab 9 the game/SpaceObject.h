#ifndef _BIRD_H_
#define _BIRD_H_

#include <SFML/Graphics.hpp>

class PhisController;

class SpaceObject
{
protected:
    
    friend PhisController;

    sf::Texture * texture;

    sf::Vector2f position; // положение на экране
    sf::Vector2f size;

public:
    SpaceObject(sf::Texture * texture, sf::Vector2f sPos, sf::Vector2f size);
    void Draw(sf::RenderWindow * window);

    sf::Vector2f getPosition();
    sf::Vector2f getSize();

};


#endif
