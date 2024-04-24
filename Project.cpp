#include<SFML/Graphics.hpp>
#include<iostream>


int main() {
	sf::Window window(sf::VideoMode(800, 600), "The Maze Game");

	while (window.isOpen())
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
}