#include <SFML/Graphics.hpp>
#include "SpaceObject.h"
#include "PhisController.h"


int main(){
		
    sf::RenderWindow window(sf::VideoMode(700, 300), "My window");

    sf::Texture shipTexture;
    if (!shipTexture.loadFromFile("textures/kk.png"))
    {
        return 0;
    }

	SpaceObject ship(&shipTexture, sf::Vector2f(20, 20), sf::Vector2f(50, 50));

    PhisController contr(&ship);
	    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){

                window.close();

            }

            if (event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::W)
                    contr.setSDirection(sf::Vector2f(0, -200));
                if (event.key.code == sf::Keyboard::S)
                    contr.setSDirection(sf::Vector2f(0, 200));
            }
        }

        window.clear(sf::Color::Black);

        contr.computePosition();
        ship.Draw(&window);

        window.display();

    }

    return 0;
}
