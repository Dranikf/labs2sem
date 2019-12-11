#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include "fallController.h"


int main(){
    sf::RenderWindow window(sf::VideoMode(500, 700), "My window");

    sf::Texture birdTexture;
    if (!birdTexture.loadFromFile("textures/kk.png"))
    {
        return 0;
    }

    SpaceShip m_bird(&birdTexture, sf::Vector2f(100, 200), sf::Vector2f(80, 80));
    fallController fallCont(&m_bird);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){

                window.close();

            }

            if (event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::Q)
                    fallCont.setSpeed(50.0);
                if (event.key.code == sf::Keyboard::W)
                    fallCont.setSpeed(-50.0);
                if (event.key.code == sf::Keyboard::E)
                    fallCont.setSpeed(0);
                if (event.key.code == sf::Keyboard::T)
                    fallCont.setAcceleration(10000);
                if (event.key.code == sf::Keyboard::Y)
                    fallCont.setAcceleration(-10000);
                if (event.key.code == sf::Keyboard::U)
                    fallCont.setAcceleration(0);
                
            }
        }

        window.clear(sf::Color::Black);

        fallCont.calculatePosition();
        m_bird.Draw(&window);

        window.display();

    }

    return 0;
}
