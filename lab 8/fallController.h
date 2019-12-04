#ifndef FALLCONTROLLER_H_
#define FALLCONTROLLER_H_

#include "Bird.h"

class fallController
{
private:
    
    Bird * bird;
    float V = 0; // скорость птицы
    float a = 0; // ускорение птицы 
    int weigth = 5; // вес птицы
    sf::Clock clock;

public:
    fallController(Bird * bird);

    void setBirdPosition(sf::Vector2f position);
    void calculatePosition();
    void setSpeed(float speed);
    void setAcceleration(float acceleration);

    friend void setBirtSize();

};


#endif