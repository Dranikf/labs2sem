#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameEngine.h"

const int windWidth = 700, windHeigth = 300;

int main(){
		
    sf::RenderWindow window(sf::VideoMode(windWidth, windHeigth), "My window");

    sf::Texture shipTexture;
    if (!shipTexture.loadFromFile("textures/kk.png"))
    {
        return 0;
    }

    sf::Texture commetTexture;
    if (!commetTexture.loadFromFile("textures/commetTexture.png"))
    {
        return 0;
    }

    GameEngine eng(&shipTexture , &commetTexture, sf::Vector2i(windWidth, windHeigth));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                
                
                window.close();
                eng.release();

            }
            
            if(event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space)eng.OnSpaceButtonDown();
                if (event.key.code == sf::Keyboard::S)eng.OnSButtonDown();
                if (event.key.code == sf::Keyboard::W)eng.OnWButtonDown();
            }

            if (event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::W)eng.OnWButtonUp();
                if (event.key.code == sf::Keyboard::S)eng.OnSButtonUp();

                
            }
        }

        window.clear(sf::Color::Black);

        //contr.computePosition();
  
        eng.Draw(&window);

        window.display();

    }

    return 0;
}
