#include "PhisController.h"
//#include <iostream>

PhisController::PhisController(SpaceObject * object)
{

	this->object = object;

}

void PhisController::setSDirection(sf::Vector2f dir){

	direction = dir;

}

void PhisController::computePosition(){

	sf::Time t = clock.getElapsedTime();
    
	object->position += (direction* t.asSeconds());

	//std::cout <<  object->position.x << object->position.x<< std::endl;

    clock.restart();


}