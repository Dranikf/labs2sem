#ifndef FALLCONTROLLER_H_
#define FALLCONTROLLER_H_

#include "SpaceShip.h"

class fallController
{
private:
    
    SpaceShip * bird;
    float V = 0; // скорость птицы
    float a = 0; // ускорение птицы 
    int weigth = 5; // вес птицы
    sf::Clock clock;

public:
    fallController(SpaceShip * bird);

    void setSpaceShipPosition(sf::Vector2f position);
    void calculatePosition();
    void setSpeed(float speed);
    void setAcceleration(float acceleration);

};


#endif
