#include "EDGE.h"
#include <iostream>
#include "common_funcks.h"
#include <vector>

vector<STATION> * EDGE::stationsPtr = NULL;

EDGE::EDGE(string dataStr){

    vector<string> dataArray;

    parseDataStr(&dataArray, dataStr);
    position tempPosition;

    bool isFirst = false;

    for(int i =0; i < dataArray.size(); i++){

        if(atoi(dataArray[i].c_str()) == 1){

            if (isFirst == true){
                tempPosition = (*stationsPtr)[i].getPosition();
                endPoint.x = tempPosition.x;endPoint.y = tempPosition.y;
                break;
            }
            if(isFirst == false){
                tempPosition = (*stationsPtr)[i].getPosition();
                startPoint.x = tempPosition.x;startPoint.y = tempPosition.y;
                isFirst = true;        
                }
        }
    }

}

void EDGE::computePositions(vector<string> data){

     



}

void EDGE::setStations(vector<STATION> * stationsPtr){

    EDGE::stationsPtr = stationsPtr;

}
