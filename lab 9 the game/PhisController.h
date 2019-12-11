#ifndef _PHIS_CONTROLLER_
#define _PHIS_CONTROLLER_

#include <SFML/Graphics.hpp>
#include "SpaceObject.h"


class PhisController{

	public:
		PhisController(SpaceObject * object);
		SpaceObject * object;
	private:
		sf::Vector2f direction;// направление движения обьекта
		float speed;// выраженная в условных единицах скорость

		
};

#endif
