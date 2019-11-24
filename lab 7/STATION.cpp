#include "STATION.h"


STATION::STATION(string dataStr)
{

    vector<string> data;
    parseDataStr(&data, dataStr);

    st_pos.x = float(atof(data[0].c_str()));
    st_pos.y = float(atof(data[1].c_str()));

    stationName = data[2].c_str();

}

STATION::STATION(int x , int y, string stationName){

    st_pos.x = x;
    st_pos.y = y;
    this->stationName = stationName;

}

STATION::~STATION()
{
}

void STATION::showStationInfo(){

    cout<< "position:" << st_pos.x << " " << st_pos.y  << endl;
    cout << "station name: " << stationName << endl ; 

}

sf::Vector2i STATION::getPosition(){

    return st_pos;

    
}

void STATION::setPosition(sf::Vector2i pos){

   st_pos = pos;

}

void STATION::setColor(sf::Color color){

    this->color = color;

}

sf::Color STATION::getColor(){
    return color;
}

string STATION::getName(){

    return stationName;

}

string STATION::getDataString(){
    string result;

    result = to_string(st_pos.x) + " " + to_string(st_pos.y) + " " + stationName;

    return result;

}