#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

std::string path = "/Users/salman/Desktop/ProjectS24/img/";


class Player
{
private:
	

public:
	sf::Texture pTexture;
	float speed;
	int lives;
	int shield;
	int health;
	sf::Sprite p;
	
	Player();
	~Player();

	//bool closeToAPoint(int x, int y);
	std::string getStrHealth();
	void move(std::string dir);

};

std::string Player::getStrHealth() {
	// Get health as a string
	return "Lives " + std::to_string(health);
}


Player::Player()
{
	lives = 1;
	shield = 0;
	speed = 0.2;
	health = 3;
	std::cout<<pTexture.loadFromFile(path + "Spy.png");
	p.setTexture(pTexture);
	p.setPosition(25 / 2, 25 / 2);
	p.setScale(0.09, 0.09);
	
	
}

void Player::move(std::string dir) {
	std::cout << "(" << this->p.getPosition().x << ", " << this->p.getPosition().y << ")\n";
	if (dir == "u") {
		p.move(0, -1 * speed);
	}
	if (dir == "d") {
		p.move(0, 1 * speed);
	}
	if (dir == "l") {
		p.move(-1 * speed, 0);
	}
	if (dir == "r") {
		p.move(1 * speed, 0);
	}

}

Player::~Player()
{
}