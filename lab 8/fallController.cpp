#include "fallController.h"
#include "math.h"
#include <iostream>

using namespace std;

fallController::fallController(SpaceShip* bird){

    this->bird = bird;

}

void fallController::setSpaceShipPosition(sf::Vector2f position)
{

    bird->position = position;
    
}

void fallController::calculatePosition()
{
    sf::Time t = clock.getElapsedTime();
    
    V += a * pow(t.asSeconds(),2);
    bird->position.y += t.asSeconds() * V;

    clock.restart();

}

void fallController::setSpeed(float speed){

    V = speed;

}

void fallController::setAcceleration(float acceleration){

    a = acceleration;

}
