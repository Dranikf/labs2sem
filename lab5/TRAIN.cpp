#include "TRAIN.h"


TRAIN::TRAIN(int startStation, int trainNumber, sf::Color trainColor)
{

    this->trainNumber = trainNumber;
    this->stationInex = startStation;
    this->trainColor = trainColor;

}

TRAIN::~TRAIN()
{
}

int TRAIN::getStationIndex(){

    return stationInex;

}

sf::Color TRAIN::getTrainColor(){

    return trainColor;

}

// эта прегрузка ищет ближайшую станцию к текущей и переносит поезд туда
void TRAIN::moveTrain(vector<STATION>* stations){

    position activePosition = (*stations)[stationInex].getPosition();
    position tempPosition;
    float minDistance = -1.f , temDistance;
    int minIndex = -1;
    int i = 0;

    do{
        if (i == stationInex){
            i++; // пропускаем итерацию если рассматриваемая станция активна сейчас
            continue;
        }

        tempPosition = (*stations)[i].getPosition();
        temDistance = (float)pow((activePosition.x - tempPosition.x),2) + (float)pow((activePosition.y - tempPosition.y),2);
        if(temDistance < minDistance || minDistance == -1.0f){
            minDistance = temDistance;
            minIndex = i;
        }
        
        i++;
    }while(i < stations->size());

    stationInex = minIndex;

}

void TRAIN::moveTrain(vector<STATION>* stations , sf::Vector2i mousePos){

    position tempPosition;
    float minDistance = -1.f , temDistance;
    int minIndex = -1;
    int i = 0;

    do{

        tempPosition = (*stations)[i].getPosition();
        temDistance = (float)pow((mousePos.x - tempPosition.x),2) + (float)pow((mousePos.y - tempPosition.y),2);
        if(temDistance < minDistance || minDistance == -1.0f){
            minDistance = temDistance;
            minIndex = i;
        }
        
        i++;
    }while(i < stations->size());

    stationInex = minIndex;

}