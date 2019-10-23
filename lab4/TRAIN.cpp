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