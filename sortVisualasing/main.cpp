#include <SFML/Graphics.hpp>
#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int windWidth = 800, windHeigth = 400;

vector<int> wArray;

void visualiseVector(vector<int> * arr, sf::RenderWindow * window){

    int arraySize =  arr->size();
    float reictangleWidth = (float)windWidth/ (float)arraySize;

    sf::RectangleShape Rectangle;
    Rectangle.setFillColor(sf::Color::Black);
    
    for(int i = 0; i < arraySize; i++){

        Rectangle.setSize(sf::Vector2f(reictangleWidth - 1, (*arr)[i]));
        Rectangle.setPosition(sf::Vector2f((float)i*reictangleWidth ,windHeigth - (*arr)[i]));

        window->draw(Rectangle);

    }
}

void changeValues(int firstIndex, int secondIndex, vector<int> * arr){

    int temp;

    temp = (*arr)[firstIndex];
    (*arr)[firstIndex] = (*arr)[secondIndex];
    (*arr)[secondIndex] = temp;

}

int bubbleSort(vector<int> * arr){

    for(int i =0 ; i < arr->size() -1; i++){

        if((*arr)[i]> (*arr)[i + 1]){
            changeValues(i, i+1, arr);
            return 0;
        } 

    }
    return 1;
}

int revbubbleSort(vector<int> * arr){


     for(int i =0 ; i < arr->size() -1; i++){

         if((*arr)[i]< (*arr)[i + 1]){
             changeValues(i, i+1, arr);
             return 0;
         }

     }
     return 1;


}

int randMix(vector<int> * arr){

    int firstIndex, secondIndex, temp;

    firstIndex = rand() % arr->size();
    secondIndex = rand() % arr->size();

    changeValues(firstIndex, secondIndex, arr);

    return 0;
}

int emptyFunc(vector<int> * arr){}

class algoritmControler{

public:

    int (*algoFunck)(vector<int> * arr) = emptyFunc;
    int callAlgor(vector<int> * arr){return algoFunck(arr);};


};

int main(){

    sf::RenderWindow window(sf::VideoMode(windWidth, windHeigth), "My window");

    algoritmControler * algCont;

    algCont = new algoritmControler;

    for(int i =0; i< 100 ; i++)
        wArray.push_back(i * 3);


    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Q)
                    algCont->algoFunck = randMix;
                if  (event.key.code == sf::Keyboard::W)
                    algCont->algoFunck = bubbleSort;
                if (event.key.code == sf::Keyboard::E)
                    algCont->algoFunck= revbubbleSort;
            }
                
        }

        window.clear(sf::Color::White);

        if(algCont->callAlgor(&wArray)== 1)
		algCont->algoFunck = emptyFunc;
        visualiseVector(&wArray, &window);

        window.display();
    }

    delete algCont;

    return 0;

}
