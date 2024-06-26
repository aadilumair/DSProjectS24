#pragma once
#include "func.h"
#include "enemy.h"
#include "player.h"

#include<SFML/Graphics.hpp>
#include<iostream>
int C =3;

std::string combatPath = "img/";

int enemiesdef = 0;

class combat
{
public:
	bool startCombat(int N, int cellSize, Player &play, Enemy &ene /*, Inventory &inv*/) {
		sf::RenderWindow window(sf::VideoMode(N * cellSize + 400, N * cellSize + 100), "The Maze Runner");
		
		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event) ) {
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear(sf::Color::Black);
			drawsidebar(window);
			window.draw(play.p);
			window.draw(ene.ene);
			window.display();

            if (play.score >= ene.health){
                enemiesdef++;
                return true;
            }
		}
		return true;
	}

private:

};
