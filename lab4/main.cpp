#include <SFML/Graphics.hpp>
#include "STATION.h"
#include "TRAIN.h"
#include <fstream>

vector<STATION> stations;
vector<TRAIN>   trains;

const float stationRadius = 3.f;
const float trainRadius = 5.f;

bool readStationData(string fileName){

    ifstream file(fileName);

    if(!file.is_open())
        return false;

    string stationStr;

    while (!file.eof())
    {
        getline(file, stationStr);
        stations.push_back(STATION(stationStr));
        
    }
    
        
    file.close();

    return true;

}

void drawStations(sf::RenderWindow * window){

    sf::CircleShape station_graphicks(stationRadius);	
	station_graphicks.setFillColor(sf::Color::Black);
    position tempPosition;

    for (int i = 0; i < stations.size(); i++){
        tempPosition = stations[i].getPosition();

        station_graphicks.setPosition(tempPosition.x, tempPosition.y); 
        window->draw(station_graphicks);
    }
}

void createTrains(){

    trains.push_back(TRAIN(0, 1, sf::Color::Red));
    trains.push_back(TRAIN(2, 2, sf::Color::Blue));

}

void drawTrains(sf::RenderWindow * window){

    sf::CircleShape station_graphicks(trainRadius);	
    position tempPosition;

        for (int i = 0; i < trains.size(); i++){
        tempPosition = stations[trains[i].getStationIndex()].getPosition();

        station_graphicks.setFillColor(trains[i].getTrainColor());
        station_graphicks.setPosition(tempPosition.x, tempPosition.y); 
        window->draw(station_graphicks);
    }

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 300), "My window");

    sf::CircleShape station_graphicks(3.f);	
	station_graphicks.setFillColor(sf::Color::Black);

    if(!readStationData("stations.inf"))
        return 0;

    createTrains();

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

        drawStations(&window);
        drawTrains(&window);

        window.display();
    }

    return 0;
}
