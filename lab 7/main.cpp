#include <SFML/Graphics.hpp>
//#include "STATION.h"
#include "TRAIN.h"
#include <fstream>
#include "EDGE.h"

vector<STATION> stations;
vector<TRAIN>   trains;
vector<EDGE>    edges;

const float stationRadius = 3.f;
const float trainRadius = 5.f;

template<typename T>
bool readFileData(vector<T> * array, string fileName){

    ifstream file(fileName);

    if(!file.is_open())
        return false;

    string dataStr;

    while (!file.eof())
    {
        getline(file, dataStr);
        array->push_back(T(dataStr));
        
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

void drawLine(sf::RenderWindow * window, sf::Vector2f point1, sf::Vector2f point2,sf::Color color){

    sf::Vertex line[] = {sf::Vertex(point1, color), sf::Vertex(point2, color)};

    window->draw(line, 2, sf::Lines);

}

void drawGraph(sf::RenderWindow * window){

    for (int i =0; i < edges.size(); i++)
        drawLine(window, edges[i].startPoint , edges[i].endPoint , sf::Color::Black);

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 300), "My window");

    sf::RectangleShape rectangle(sf::Vector2f(400.f, 300.f));

    EDGE::setStations(&stations);
        
    sf::Texture konturTexture;
    if (!konturTexture.loadFromFile("kontur.jpg"))
    {
        return 0;
    }

    rectangle.setTexture(&konturTexture);


    sf::Vector2i localPosition;

    sf::CircleShape station_graphicks(3.f);	
	station_graphicks.setFillColor(sf::Color::Black);

    if(!readFileData(&stations , "stations.inf"))
        return 0;

    createTrains();

    if(!readFileData(&edges, "graphInfo"))
        return 0;

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::Q)
                    trains[0].moveTrain(&stations);
                if (event.key.code == sf::Keyboard::W)
                    trains[1].moveTrain(&stations);
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                //trains[0].moveTrain(&stations, sf::Mouse::getPosition(window));
                //перемещиние первого поезда на точку на которую нажали, заремил в лабе 7
                  position test;
                  test.x = 40; test.y = 40;
                  stations[0].setPosition(test);                
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){

                //trains[1].moveTrain(&stations, sf::Mouse::getPosition(window));
                //перемещение второго поаезда
                
            }
                
        }
        window.clear(sf::Color::White);

        window.draw(rectangle);

        drawStations(&window);
        //drawTrains(&window); рисование поездов, отключил в лабараторке 7, чтобы не мешали
        drawGraph(&window);

        window.display();
    }

    return 0;
}
