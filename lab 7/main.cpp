#include <SFML/Graphics.hpp>
#include <fstream>
#include "EDGE.h"
#include <math.h>
#include <stdlib.h>

// команды к программе 
// a - сознать вершину (создаст под указателем мыши) нужно указать имя в консоли
// n - получить имя выделенной вершины
// d - удалить выделенную вершину


vector<STATION*> stations;
vector<EDGE*> edges;

sf::Font activeFont;

const float stationRadius = 3.f;
const float trainRadius = 5.f;

void writeEdgesToFile(string fileName){

    ofstream outFile(fileName);

    int point1Index, point2Index;
    string writeString;

    for(int i = 0; i < edges.size(); i++ ){
        if(i != 0) outFile << endl;

        writeString = "";

        for(int k = 0; k < stations.size(); k++){
            writeString += " ";
            if(edges[i]->startPoint == stations[k] || edges[i]->endPoint == stations[k]) 
            {writeString += "1"; continue;}
            
            writeString += "0";
        }

        writeString.erase(0, 1);

        outFile << writeString;

    }

    outFile.close();

}

template<typename T>
void saveVec2iToFile(vector<T> * array, string fileName){

    ofstream outFile(fileName);
    int size = array->size();
    
    for(int i = 0; i < size; i++){

        outFile << (*array)[i]->getDataString();

        if(i != size -1) outFile << endl;

    }

    outFile.close();

}

void drawStationsText(sf::RenderWindow * window, sf::Font font, int size){

    sf::Text number;

    number.setFont(font);
    number.setCharacterSize(size);
    number.setFillColor(sf::Color::Black);

    for(int i =0; i < stations.size(); i++){

        number.setString(to_string(i));
        number.setPosition((sf::Vector2f)stations[i]->getPosition());

        window->draw(number);
    }

}

void drawStations(sf::RenderWindow * window){

    sf::CircleShape station_graphicks(stationRadius);	
	station_graphicks.setFillColor(sf::Color::Black);
    sf::Vector2i tempPosition;

    for (int i = 0; i < stations.size(); i++){
        tempPosition = stations[i]->getPosition();

        station_graphicks.setFillColor(stations[i]->getColor());
        station_graphicks.setPosition(tempPosition.x, tempPosition.y); 
        window->draw(station_graphicks);
    }
}

void drawLine(sf::RenderWindow * window, sf::Vector2f point1, sf::Vector2f point2,sf::Color color){

    sf::Vertex line[] = {sf::Vertex(point1, color), sf::Vertex(point2, color)};

    window->draw(line, 2, sf::Lines);

}

template<typename PointClass>
int findNearestPoint(sf::Vector2i mousePosition , vector<PointClass> * points){

    sf::Vector2i tempPosition;
    float minDistance = -1.f , temDistance;
    int minIndex = -1;
    int i = 0;

    do{

        tempPosition = (*points)[i]->getPosition();
        temDistance = (float)pow((mousePosition.x - tempPosition.x),2) + (float)pow((mousePosition.y - tempPosition.y),2);
        if(temDistance < minDistance || minDistance == -1.0f){

            minDistance = temDistance;
            minIndex = i;

        }
        
        i++;
    }while(i < points->size());

    return minIndex;
}

void drawEdges(sf::RenderWindow * window){

    sf::Vector2f startPoint, endPoint;

    for (int i = 0; i < edges.size(); i++){
        startPoint = (sf::Vector2f)edges[i]->getStartPosition();
        endPoint = (sf::Vector2f)edges[i]->getEndPosition();

        drawLine(window, startPoint, endPoint, sf::Color::Black);

    }

}

int checkCommection(int point1 , int point2){

    for(int i = 0; i < edges.size(); i++){

        if((edges[i]->startPoint == stations[point1] && edges[i]->endPoint == stations[point2]) || 
            (edges[i]->startPoint == stations[point2] && edges[i]->endPoint == stations[point1])){
            return i;}
    }

    return -1;

}

void delEdge(int Index){

    delete edges[Index];
    edges.erase(edges.begin() + Index);    

}

void deleteEdge(int point1 , int point2){

    int deletedIndex = checkCommection(point1, point2);
    if(deletedIndex == -1){
        cout<< "указанного соединения не сущесвует" << endl;
        return;
    }
    
    delEdge(deletedIndex);    

}

void cerateEdge(int sPointIndex){

    string index_str ; int index;

    cout << "Enter pointIndex for connection: ";
    getline(cin ,index_str); index = atoi(index_str.c_str());
    if (index >= stations.size() || index >= stations.size()  < 0){
        cout<< "такой точки не существует!!" << endl;
        return;
    }

    if(sPointIndex == index){
        cout << "поддержка петлевых связей отсудствует" << endl;
        return;
    }

    if (checkCommection(sPointIndex , index) != -1){
        cout << "соединнение уже существует" << endl;
        return;
    }

    edges.push_back(new EDGE(sPointIndex, index));

}

void buttonIOnPressed(int selectedPoint){

    cout<< "укажите соединение с какой точкой вы хотить разорвать:";
    int index = cinGetInt();
    if (index >= stations.size() || index >= stations.size()  < 0){
        cout<< "такой точки не существует!!" << endl;
        return;
    }

    deleteEdge(selectedPoint, index);

}


void deletePoint(int pointIndex){


    for(int i = 0; i < edges.size(); i++){

        if(edges[i]->startPoint == stations[pointIndex] || edges[i]->endPoint == stations[pointIndex]){
            
            delEdge(i);
            i--;

        }
    }       

    delete stations[pointIndex];
    stations.erase(stations.begin() + pointIndex);

}

void releaseMemory(){

    for(int i = 0; i < stations.size(); i++)
        delete stations[i];


    for (int i = 0; i < edges.size(); i++)
        delete edges[i];


}

int main()
{

    int activePoint = -1; // это активная станция которая бегает за мышкой
    int selectedPoint = 0; // это активная станция которая меняет цвет

    sf::RenderWindow window(sf::VideoMode(400, 300), "My window");
    if(!activeFont.loadFromFile("ArialBlack.ttf")) return 0;


    if(!readFileData(&stations , "stations.inf"))
       return 0;

    EDGE::stationsArr = &stations;

    if(!readFileData(&edges, "graphInfo"))
        return 0;

    
    stations[selectedPoint]->setColor(sf::Color::Red);

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                saveVec2iToFile(&stations, "stations.inf");
                writeEdgesToFile("graphInfo");
                window.close();
            }

            if (event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::A){

                    string name;

                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    cout<< "Enter station name:" << endl;
                    getline(cin, name);
                    stations.push_back(new STATION(mousePosition.x, mousePosition.y, name));

                }

                if (event.key.code == sf::Keyboard::N) cout << stations[selectedPoint]->getName() << endl;
                
                if (event.key.code == sf::Keyboard::D)  deletePoint(selectedPoint);

                if  (event.key.code == sf::Keyboard::Q)  cerateEdge(selectedPoint);

                if (event.key.code == sf::Keyboard::I)  buttonIOnPressed(selectedPoint);
                    


            }
            
            if(event.type == sf::Event::MouseButtonPressed){
                activePoint = findNearestPoint(sf::Mouse::getPosition(window), &stations);
                stations[selectedPoint]->setColor(sf::Color::Black);
                selectedPoint = activePoint;
                stations[selectedPoint]->setColor(sf::Color::Red);
            }

            if(event.type == sf::Event::MouseButtonReleased){
                activePoint = -1;
            }

                
        }

        if(activePoint != -1) stations[activePoint]->setPosition(sf::Mouse::getPosition(window));

        window.clear(sf::Color::White);

        drawStations(&window);
        drawStationsText(&window, activeFont, 15);

        drawEdges(&window);

        window.display();
    }

    return 0;
}