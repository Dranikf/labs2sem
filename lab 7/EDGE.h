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

public:
    
    static vector<STATION*> * stationsArr;

    EDGE(string dataStr);
    EDGE(int startPointIndex, int endPointIndex);

    sf::Vector2i getStartPosition();
    sf::Vector2i getEndPosition();

    STATION * startPoint;
    STATION * endPoint;

};

#endif
