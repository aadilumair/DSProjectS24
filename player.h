#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

std::string path = "img/";

//pathway for images for salman: /Users/salman/Desktop/ProjectS24/img/

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
	void move(std::string dir, sf::Image img);

};

std::string Player::getStrHealth() {
	// Get health as a string
	return "Lives " + std::to_string(health);
}


Player::Player()
{
	lives = 3;
	shield = 0;
	speed = 2;
	health = 3;
	pTexture.loadFromFile(path + "Spy.png");
	p.setTexture(pTexture);
	p.setPosition(30 , 26);
	p.setScale(0.07, 0.07);
	
	
}

void Player::move(std::string dir, sf::Image img) {
	//std::cout << "(" << this->p.getPosition().x << ", " << this->p.getPosition().y << ")\n";
	int dx = 0, dy = 0;
	if (dir == "u") {
		dy = -1 * speed;
	}
	if (dir == "d") {
		dy = 1 * speed;
	}
	if (dir == "l") {
		dx = -1 * speed;
	}
	if (dir == "r") {
		dx = 1 * speed;
	}
	int ax = dx + p.getPosition().x;
	int ay = dy + p.getPosition().y;

	const float scale = 0.07;
	if (!(img.getPixel(ax, ay) == sf::Color::White) && !(img.getPixel(ax, ay + (300 * scale)) == sf::Color::White)
		&& !(img.getPixel(ax + (200 * scale), ay) == sf::Color::White) && !(img.getPixel(ax + (200 * scale), ay + (300 * scale)) == sf::Color::White))
		p.move(dx, dy);

	
}

Player::~Player()
{
}