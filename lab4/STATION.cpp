#include "STATION.h"


STATION::STATION(string dataStr)
{

    vector<string> data;
    parseDataStr(&data, dataStr);

    st_pos.x = float(atof(data[0].c_str()));
    st_pos.y = float(atof(data[1].c_str()));

    statinonName = data[2].c_str();

}

STATION::~STATION()
{
}

void STATION::showStationInfo(){

    cout<< "position:" << st_pos.x << " " << st_pos.y  << endl;
    cout << "station name: " << statinonName << endl ; 

}