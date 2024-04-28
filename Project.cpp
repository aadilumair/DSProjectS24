#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;


int main() {
	sf::Window window(sf::VideoMode(800, 600), "The Maze Game");

	while (window.isOpen())
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
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



