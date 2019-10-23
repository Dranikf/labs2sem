#include <SFML/Graphics.hpp>
#include "STATION.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::CircleShape station_graphicks(3.f);	
	station_graphicks.setFillColor(sf::Color::Black);

    STATION station("20 50 Minsk");

    station.showStationInfo();

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);

        station_graphicks.setPosition(5.f, 10.f);
        window.draw(station_graphicks);
        station_graphicks.setPosition(10.f, 20.f);
        window.draw(station_graphicks);
        station_graphicks.setPosition(5.f, 20.f);
        window.draw(station_graphicks);


        window.display();
    }

    return 0;
}
