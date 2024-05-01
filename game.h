#pragma once
#include "maze.h"
#include <SFML/Graphics.hpp>

class Game
{
private:
	int N;
    int cellSize;
	Graph g;

public:
    Game() :N(30), g(N* N), cellSize(25) {

    }

	void startGame() {
		

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
	}

};
