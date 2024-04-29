#include<SFML/Graphics.hpp>
#include<iostream>
#include "maze.h"

using namespace std;
using namespace sf;


int main() {
    int N = 30;
    int cellSize = 25;

    sf::RenderWindow window(sf::VideoMode(N * cellSize, N * cellSize), "The Maze Runner");

    Graph g(N * N);

    Maze::setupMaze(N, g);
    Maze::runDFS(g);
    

    while (window.isOpen()) {
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        Maze::drawMaze(window, cellSize, g);

        window.display();
    }

    return 0;
}



//test code for salman to test SFML
/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
sf::CircleShape shape(100.f);

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
 */

//maze coordinates will be stored in graphs
//graph can be converted into a tree
//store treasure items whose coordinates will be stored in an AVL tree
//find the shortest path, collect an item and then display a small part of the shortest path



