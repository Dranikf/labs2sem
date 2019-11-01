#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

const int windWidth = 500, windHeigth = 400;

vector<int> wArray;

void visualiseVector(vector<int> * arr, sf::RenderWindow * window){

    int arraySize =  arr->size();
    int reictangleWidth = windWidth/ arraySize;

    sf::RectangleShape Rectangle;
    Rectangle.setFillColor(sf::Color::Black);
    
    for(int i = 0; i < arraySize; i++){

        Rectangle.setSize(sf::Vector2f(400.f, 300.f));

        window->draw(Rectangle);

    }
}

int main(){

    sf::RenderWindow window(sf::VideoMode(windWidth, windHeigth), "My window");


    for(int i =0; i< 100 ; i++)
        wArray.push_back(i);


    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
                
        }
        window.clear(sf::Color::White);

        visualiseVector(&wArray, &window);

        window.display();
    }

    return 0;

}