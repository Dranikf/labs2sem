#include <SFML/Graphics.hpp>
#include "STATION.h"
#include <math.h>

class TRAIN
{
private:

    int trainNumber;
    int stationInex;
    sf::Color trainColor;
    

public:
    TRAIN(int startStation, int trainNumber , sf::Color);
    ~TRAIN();

    int getStationIndex();
    sf::Color getTrainColor();

    void moveTrain(vector<STATION>*);
    void moveTrain(vector<STATION>* , sf::Vector2i);
};
