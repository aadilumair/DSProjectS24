#pragma once
#include "maze.h"
#include "func.h"
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

        std::vector<items*> allItems; // Vector to hold all items (bandages, shields etc.)


        // Generate random number of items (bandages, shields etc.)
        int numBandages = rand() % 5 + 1; // Random number of bandages between 1 and 5
        int numShields = rand() % 10 + 1; // Random number of shields between 1 and 5
        int numCoins =  25;   // Random number of coins between 1 and 20
        int numHeart = rand() % 3 + 1; //Random number of hearts between 1 and 3
        int numTreasure = rand() % 3 + 1; //Random number of treasures between 1 and 3

        // Generate and add random bandages
        for (int i = 0; i < numBandages; ++i) {
            int x = rand() % (N - 1);
            int y = rand() % (N - 1);
            Bandages* bandage = new Bandages((x + 1) * cellSize, (y + 1) * cellSize);
            allItems.push_back(bandage);
        }

        // Generate and add random shields
        for (int i = 0; i < numShields; ++i) {
            int x = rand() % (N - 1);
            int y = rand() % (N - 1);
            Shields* shield = new Shields((x + 1) * cellSize, (y + 1) * cellSize);
            allItems.push_back(shield);
        }

        // Generate and add random coins
        for (int i = 0; i < numCoins; ++i) {
            int x = rand() % (N - 1);
            int y = rand() % (N - 1);
            Coins* coin = new Coins((x + 1) * cellSize, (y + 1) * cellSize);
            allItems.push_back(coin);
        }

        // Generate and add random hearts
        for (int i = 0; i < numHeart; ++i) {
            int x = rand() % (N - 1);
            int y = rand() % (N - 1);
            Hearts* hearts = new Hearts((x + 1) * cellSize, (y + 1) * cellSize);
            allItems.push_back(hearts);
        }

        // Generate and add random hearts
        for (int i = 0; i < numTreasure; ++i) {
            int x = rand() % (N - 1);
            int y = rand() % (N - 1);
            Treasure* treasure = new Treasure((x + 1) * cellSize, (y + 1) * cellSize);
            allItems.push_back(treasure);
        }

        Fists fistsInstance(850, 100);


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


            // Draw items
            for (auto& item : allItems) {
                window.draw(item->item);
            }

            //displaying the inventory
            //call the avl and display it smh
            //displayed fists for now
            window.draw(fistsInstance.item);

            window.display();
        }

        // Clean up dynamically allocated memory
        for (auto& item : allItems) {
            delete item;
        }
	}

};
