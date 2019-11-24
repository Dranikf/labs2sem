#include <vector>
#include <string>
#include <iostream>
#include "common_funcks.h"
#include <SFML/Graphics.hpp>

#ifndef STATION_H
#define STATION_H

using namespace std;


class STATION
{
private:

    sf::Vector2i    st_pos;
    string          stationName;
    sf::Color       color = sf::Color::Black;
    
public:

    STATION(string);
    STATION(int x, int y, string stationName);
    ~STATION();

    void showStationInfo();
    sf::Vector2i getPosition();
    void setPosition(sf::Vector2i pos);
    void setColor(sf::Color color);
    sf::Color getColor();
    string getName();
    string getDataString();
};

#endif
