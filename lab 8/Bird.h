#ifndef _BIRD_H_
#define _BIRD_H_

#include <SFML/Graphics.hpp>

class fallController;

class Bird
{
private:
    
    friend fallController;

    sf::Texture * texture;

    sf::Vector2f position; // положение на экране
    sf::Vector2f size;

public:
    Bird(sf::Texture * texture, sf::Vector2f sPos, sf::Vector2f size);
    void Draw(sf::RenderWindow * window);

    friend void setBirtSize(Bird * b, int size);
};


#endif