#include "EDGE.h"
#include <iostream>
#include "common_funcks.h"
#include <vector>

vector<STATION*> * EDGE::stationsArr;

EDGE::EDGE(string dataStr){

    vector<string> dataArray;

    parseDataStr(&dataArray, dataStr);
    sf::Vector2i tempPosition;

    bool isFirst = false;

    for(int i =0; i < dataArray.size(); i++){

        if(atoi(dataArray[i].c_str()) == 1){

            if (isFirst == true){
                endPoint = (*stationsArr)[i];
                break;
            }
            if(isFirst == false){
                startPoint = (*stationsArr)[i];
                isFirst = true;        
                }
        }
    }

}

EDGE::EDGE(int startPointIndex, int endPointIndex){

    this->startPoint = (*stationsArr)[startPointIndex];
    this->endPoint = (*stationsArr)[endPointIndex];

}

sf::Vector2i EDGE::getEndPosition(){

    return startPoint->getPosition();

}

sf::Vector2i EDGE::getStartPosition(){

    return endPoint->getPosition();

}