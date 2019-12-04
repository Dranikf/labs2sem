#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "fallController.h"

void setBirtSize(Bird * b, int size){

    b->size = sf::Vector2f(size , size);

}

int main(){
    sf::RenderWindow window(sf::VideoMode(500, 700), "My window");

    sf::Texture birdTexture;
    if (!birdTexture.loadFromFile("textures/kk.png"))
    {
        return 0;
    }

    Bird m_bird(&birdTexture, sf::Vector2f(100, 200), sf::Vector2f(80, 80));
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
                    fallCont.setAcceleration(1000000);
                if (event.key.code == sf::Keyboard::Y)
                    fallCont.setAcceleration(-1000000);
                if (event.key.code == sf::Keyboard::U)
                    fallCont.setAcceleration(0);
                if (event.key.code == sf::Keyboard::A)
                    setBirtSize(&m_bird , 80);
                if (event.key.code == sf::Keyboard::S)
                    setBirtSize(&m_bird , 40);
                
            }
        }

        window.clear(sf::Color::Black);

        fallCont.calculatePosition();
        m_bird.Draw(&window);

        window.display();

    }

    return 0;
}