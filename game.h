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
        sf::RenderWindow window(sf::VideoMode(N * cellSize + 400, N * cellSize + 100), "The Maze Runner");

        Graph g(N * N);

        Maze::setupMaze(N, g);
        Maze::runDFS(g);

        //-------------setting up items,weapons and inventory-------------------
        std::vector<items*> allItems; // Vector to hold all items (bandages, shields etc.)
        std::vector<weapons*> allWeapons; // Vector to hold all items (bandages, shields etc.)

        // Generate random number of items (bandages, shields etc.)
        int numBandages = rand() % 5 + 1; // Random number of bandages between 1 and 5
        int numShields = rand() % 10 + 1; // Random number of shields between 1 and 5
        int numCoins =  25;   // Random number of coins between 1 and 20
        int numHeart = rand() % 3 + 1; //Random number of hearts between 1 and 3
        int numTreasure = rand() % 3 + 1; //Random number of treasures between 1 and 3
        // Generate random number of weapons (knives,axes etc.)
        int numFists = 1; // Random number of bandages between 1 and 5
        int numGrenades = rand() % 5 + 1; //Random number of treasures between 1 and 3
        int numAxes = rand() % 2 + 1; // Random number of shields between 1 and 5
        int numKnives = rand() % 5 + 1; //Random number of hearts between 1 and 3

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

        // Generate and add random Grenades
        for (int i = 0; i < numGrenades; ++i) {
            int x = rand() % (N - 1);
            int y = rand() % (N - 1);
            Grenades* grenades = new Grenades((x + 1) * cellSize, (y + 1) * cellSize);
            allWeapons.push_back(grenades);
        }

        // Generate and add random Axes
        for (int i = 0; i < numAxes; ++i) {
            int x = rand() % (N - 1);
            int y = rand() % (N - 1);
            Axe* axes = new Axe((x + 1) * cellSize, (y + 1) * cellSize);
            allWeapons.push_back(axes);
        }

        // Generate and add random Knives
        for (int i = 0; i < numKnives; ++i) {
            int x = rand() % (N - 1);
            int y = rand() % (N - 1);
            knives* knive = new knives((x + 1) * cellSize, (y + 1) * cellSize);
            allWeapons.push_back(knive);
        }
        //-------------setting up items,weapons and inventory-------------------

        //------------------------setting up font------------------------



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
            // Draw weapons
            for (auto& weapon : allWeapons) {
                window.draw(weapon->item);
            }
            //displaying the inventory
            //call the avl and display it smh (still needs to be done, display numbers !)
            //check for collisions, add item/weapon to AVL, count no. of items in AVL and display next
            //to the images
            //display health bar and shields
            drawsidebar(window);

            //displaying text


            window.display();
        }

        // Clean up dynamically allocated memory for consumables
        for (auto& item : allItems) {
            delete item;
        }
        // Clean up dynamically allocated memory for weapons
        for (auto& weapon : allWeapons) {
            delete weapon;
        }

    }

};
