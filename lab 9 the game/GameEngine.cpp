#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine(sf::Texture * shipTexture
, sf::Texture * cometTex, sf::Vector2i windowSize){

    this->shipTexture = shipTexture;
    this->cometTexture = cometTex;
    this->windowSize = windowSize;

    ship = new SpaceShip(shipTexture , sf::Vector2f(20, (float)(windowSize.y / 2)), sf::Vector2f(50, 50));
    shipController = new PhisController(ship);

    InitMenu();

}

void GameEngine::Draw(sf::RenderWindow * window){

    ship->Draw(window);

    for(int i = 0 ; i < mComets.size(); i++)
        mComets[i].comet->Draw(window);

    if(activeMode == menu)
        window->draw(enterToStart);

    if(activeMode == gaming)
        frame();
    

}

void GameEngine::InitMenu(){

    if(!activeFont.loadFromFile("fonts/ArialBlack.ttf"))
        std::cout << "нет указанного шрифта" << std::endl;

    enterToStart.setFont(activeFont);
    enterToStart.setCharacterSize(40);
    enterToStart.setFillColor(sf::Color::White);
    enterToStart.setString("Press SPACE to start");
    enterToStart.setPosition(sf::Vector2f(100 , windowSize.y / 2));

}

void GameEngine::release(){

    delete ship;
    delete shipController;

    for(int i = 0 ; i < mComets.size(); i++)
        releaseComet(i);

}

void GameEngine::OnSpaceButtonDown(){activeMode = gaming;}

void GameEngine::OnSButtonDown(){
    shipController->setSDirection(sf::Vector2f(0, 200));
    ship->setRotation(20);
}

void GameEngine::OnWButtonDown(){
    shipController->setSDirection(sf::Vector2f(0, -200));
    ship->setRotation(-20);
}

void GameEngine::OnWButtonUp(){
    shipController->setSDirection(sf::Vector2f(0, 0));
    ship->setRotation(0);
}

void GameEngine::OnSButtonUp(){
    shipController->setSDirection(sf::Vector2f(0, 0));
    ship->setRotation(0);
}


void GameEngine::frame(){

    shipController->computePosition();
    timerComets();

    for(int i = 0 ; i < mComets.size(); i++)
        mComets[i].cont->computePosition();

    checkColisions();

}

void GameEngine::timerComets(){

    sf::Time period = ComClock.getElapsedTime();
    if(period.asSeconds() > 1){
        ComClock.restart();
        createComet();
    }

}

void GameEngine::createComet(){
    vector<comet> comets;
    comet tempComet;
    sf::Vector2f dir(-200 , 0);

    tempComet.comet = new SpaceComet(cometTexture, 
    sf::Vector2f(windowSize.x + 100,getRandComY()), 
    sf::Vector2f(50 , 50), sf::Vector2f(3 , 0));
    tempComet.cont = new PhisController(tempComet.comet);
    tempComet.cont->setSDirection(dir);

    mComets.push_back(tempComet);

}

int GameEngine::getRandComY(){ 
    return (rand()%windowSize.y + 60) - 30;
}

void GameEngine::releaseComet(int index){

    delete mComets[index].comet;
    delete mComets[index].cont;

    mComets.erase(mComets.begin() + index);    

}

void GameEngine::releaseOldComets(){

    for(int i = 0 ; i < mComets.size(); i++)
        if( mComets[i].comet->getPosition().x < - 100)
            releaseComet(i);
}

void getBorders(SpaceObject * obj, sf::Vector2f * UpLeft, sf::Vector2f * DownRight){

    (*UpLeft) = obj->getPosition();
    (*DownRight) = (*UpLeft) + obj->getSize();


}

int GameEngine::checkColisions(){

    sf::Vector2f shipUpLeft;
    sf::Vector2f shipDownRight;

    getBorders(ship , &shipUpLeft , &shipDownRight);
    cout << shipUpLeft.x << shipDownRight.x << endl;

    for(int i = 0 ; i < mComets.size(); i++){
        

    }
}