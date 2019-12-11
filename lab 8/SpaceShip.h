#ifndef _BIRD_H_
#define _BIRD_H_

#include <SFML/Graphics.hpp>

class fallController;

class SpaceShip
{
private:
    
    friend fallController;

    sf::Texture * texture;

    sf::Vector2f position; // положение на экране
    sf::Vector2f size;

public:
    SpaceShip(sf::Texture * texture, sf::Vector2f sPos, sf::Vector2f size);
    void Draw(sf::RenderWindow * window);

};


#endif
