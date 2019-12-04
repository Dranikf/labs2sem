#include "fallController.h"
#include "math.h"

fallController::fallController(Bird* bird){

    this->bird = bird;

}

void fallController::setBirdPosition(sf::Vector2f position)
{

    bird->position = position;
    
}

void fallController::calculatePosition()
{
    sf::Time t = clock.getElapsedTime();
    
    V += weigth * a;
    bird->position.y += t.asMicroseconds() * V;

    clock.restart();

}

void fallController::setSpeed(float speed){

    V = speed;

}

void fallController::setAcceleration(float acceleration){

    a = acceleration;

}