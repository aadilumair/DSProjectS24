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
        sf::RenderWindow window(sf::VideoMode(N * cellSize + 300, N * cellSize + 100), "The Maze Runner");

        Graph g(N * N);

        Maze::setupMaze(N, g);
        Maze::runDFS(g);


        while (window.isOpen()) {

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::Black);

            sf::RectangleShape wallN;
            wallN.setFillColor(sf::Color::White);
            wallN.setSize(sf::Vector2f(cellSize * N, 2));
            wallN.setPosition(sf::Vector2f(cellSize, cellSize));
            window.draw(wallN);

            sf::RectangleShape wallS;
            wallS.setFillColor(sf::Color::White);
            wallS.setSize(sf::Vector2f(cellSize * N, 2));
            wallS.setPosition(sf::Vector2f(cellSize, cellSize * N + cellSize));
            window.draw(wallS);

            sf::RectangleShape wallW;
            wallN.setFillColor(sf::Color::White);
            wallN.setSize(sf::Vector2f(2, cellSize * N));
            wallN.setPosition(sf::Vector2f(cellSize, cellSize));
            window.draw(wallN);

            Maze::drawMaze(window, cellSize, g);

            window.display();
        }
	}

};
