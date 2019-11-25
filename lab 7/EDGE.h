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

    int endPointIndex, startPointIndex;
    
    EDGE(string dataStr);
    EDGE(int startPointIndex, int endPointIndex);

};

#endif
