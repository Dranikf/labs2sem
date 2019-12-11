#include <SFML/Graphics.hpp>
#include "SpaceObject.h"


int main(){
		
    sf::RenderWindow window(sf::VideoMode(500, 700), "My window");

    sf::Texture shipTexture;
    if (!shipTexture.loadFromFile("textures/kk.png"))
    {
        return 0;
    }

	SpaceObject ship(&shipTexture, sf::Vector2f(20, 20), sf::Vector2f(30, 30));
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){

                window.close();

            }

            if (event.type == sf::Event::KeyReleased){
        //        if (event.key.code == sf::Keyboard::Q)
          //          fallCont.setSpeed(50.0);
            }
        }

        window.clear(sf::Color::Black);

        ship.Draw(&window);

        window.display();

    }

    return 0;
}
