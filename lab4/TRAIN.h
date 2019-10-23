#include <SFML/Graphics.hpp>

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
};
