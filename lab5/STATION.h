#include <vector>
#include <string>
#include <iostream>
#include "common_funcks.h"

#ifndef STATION_H
#define STATION_H

using namespace std;


class STATION
{
private:

    position    st_pos;
    string      statinonName;
    
public:

    STATION(string);
    ~STATION();

    void showStationInfo();
    position getPosition();
};

#endif