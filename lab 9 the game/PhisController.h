#ifndef _PHIS_CONTROLLER_
#define _PHIS_CONTROLLER_

#include <SFML/Graphics.hpp>
#include "SpaceObject.h"


class PhisController{

	public:
		PhisController(SpaceObject * object);

		void setSDirection(sf::Vector2f dir);

		void computePosition();
	private:
		SpaceObject * object;
		sf::Vector2f direction;// направление движения обьекта, притом длинна вектора отразит также скорость
		sf::Clock clock;

		
};

#endif
