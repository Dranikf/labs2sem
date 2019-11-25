#include "EDGE.h"
#include <iostream>
#include "common_funcks.h"
#include <vector>

EDGE::EDGE(string dataStr){

    vector<string> dataArray;

    parseDataStr(&dataArray, dataStr);
    sf::Vector2i tempPosition;

    bool isFirst = false;

    for(int i =0; i < dataArray.size(); i++){

        if(atoi(dataArray[i].c_str()) == 1){

            if (isFirst == true){
                endPointIndex = i;
                break;
            }
            if(isFirst == false){
                startPointIndex = i;
                isFirst = true;        
                }
        }
    }

}

EDGE::EDGE(int startPointIndex, int endPointIndex){

    this->startPointIndex = startPointIndex;
    this->endPointIndex = endPointIndex;

}