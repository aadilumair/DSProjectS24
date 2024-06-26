#pragma once
#include "maze.h"
#include "enemy.h"
#include "func.h"
#include "player.h"
#include "combatScreen.h"
#include <SFML/Graphics.hpp>

string imagepathway = "img/";
int A = 0;

class Game
{
private:
	int N;
    int cellSize;
	Graph g;
    sf::Music backgroundMusic;

public:
    Game() :N(30), g(N* N), cellSize(25) {
        srand(time(0));

    }

    bool checkCollisionEnemy(Player &play, int i, vector<Enemy *> &eneList) {
        Enemy ene = *eneList[i];
        if (play.p.getGlobalBounds().intersects(ene.ene.getGlobalBounds())) {
            combat cmb;
            if (cmb.startCombat(N, cellSize, play, ene)) {
                //won combat
                eneList.erase(eneList.begin() + i);
                return false;
            }
            else {
                return true;
            }
        }
    }

	void startGame() {
        sf::RenderWindow window(sf::VideoMode(N * cellSize + 400, N * cellSize + 100), "The Maze Runner");

        // Load the background music from file
        if (!backgroundMusic.openFromFile("GameMusic.ogg")) {
            // Error handling if the file fails to load
            std::cerr << "Failed to load background music!" << std::endl;
        }
        backgroundMusic.play();

        Graph g(N * N);

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile(imagepathway+"Background.png")) {
            // Handle error loading texture
        }

        sf::Sprite backgroundSprite(backgroundTexture);

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

        std::vector<Enemy *> eneList;
        int noOfEne = /*(rand() % 20) +*/ 10;
        for (int i = 0; i < noOfEne; ++i) {
            int x = rand() % (N - 1);
            int y = rand() % (N - 1);
            Enemy*ene = new Enemy((x + 1) * cellSize, (y + 1) * cellSize);
            eneList.push_back(ene);
        }


        //------------------------setting up Player------------------------

        Player player;

        window.display();
        while (window.isOpen()) {

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed || player.lives==0)
                    window.close();
            }

            window.clear(sf::Color::Black);
            window.draw(backgroundSprite);

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

            for (int i = 0; i < eneList.size(); i++) {
                window.draw(eneList[i]->ene);
            }

            //displaying the inventory
            drawsidebar(window);

            //checking collision with enemy
            for (int i = 0; i < eneList.size(); i++) {
                checkCollisionEnemy(player, i,eneList);
            }

            //displaying defeated enemies (done here cus file alr included)
            sf::Font font;
            if (!font.loadFromFile(fontpath+"Retro Gaming.ttf"))
            {
                cout<<"Font not Loaded !\n";
            }
            Text EnemiesT;
            EnemiesT.setFont(font); // font is a sf::Font
            EnemiesT.setString("ENEMIES: " + std::to_string(enemiesdef) );
            EnemiesT.setPosition(810, 540);
            EnemiesT.setCharacterSize(45);
            EnemiesT.setFillColor(sf::Color::White);
            EnemiesT.setStyle(sf::Text::Bold);
            window.draw(EnemiesT);

            //checking collision with items & weapons
            for (auto& item : allItems) {
                player.checkCollisionwItems(*item);
            }
            for (auto& weapons : allWeapons) {
                player.checkCollisionwWeapons(*weapons);
            }

            player.drawScore(window);


            //Moving and disp. of player
            Texture test;
            test.create(N* cellSize + 400, N* cellSize + 100);
            test.update(window);
            Image image = test.copyToImage();
            

            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                player.move("u", image);
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                player.move("d", image);
            }
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                player.move("l", image);
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                player.move("r", image);
            }
            window.draw(player.p);

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
