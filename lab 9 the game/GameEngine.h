#ifndef GAME_ENGINE_H_
#define GAME_ENGINE_H_

#include "SpaceComet.h"
#include "SpaceShip.h"
#include "PhisController.h"
#include <vector>

using namespace std;

struct comet
{
    SpaceComet * comet;
    PhisController * cont;
};

class GameEngine
{
private:
    enum mode {menu, gaming};

    mode activeMode = menu;
    sf::Vector2i windowSize;


    vector<comet> mComets;
    sf::Clock ComClock;

    SpaceShip * ship;
    PhisController * shipController;

    sf::Font activeFont;
    sf::Text enterToStart;

    sf::Texture * shipTexture, * cometTexture;

    void frame();
    void timerComets();
    void createComet();
    int getRandComY();
    void releaseComet(int index);

public:
    GameEngine(sf::Texture * shipTexture, sf::Texture * cometTex
    , sf::Vector2i windowSize);

    void Draw(sf::RenderWindow * window);

    void InitMenu();

    void release();

    void OnSpaceButtonDown();
    void OnWButtonDown();
    void OnSButtonDown();
    void OnWButtonUp();
    void OnSButtonUp();

};

#endif