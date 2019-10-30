#include <SFML/Graphics.hpp>
#include <string>
#include "STATION.h"
#include <vector>
#include "common_funcks.h"

#ifndef EDGE_H
#define EDGE_H

using namespace std;

class EDGE
{
private:

    static vector<STATION> * stationsPtr;

public:
    sf::Vector2f startPoint;
    sf::Vector2f endPoint;
    
    EDGE(string dataStr);

    static void setStations(vector<STATION> * stationsPtr);

};

#endif