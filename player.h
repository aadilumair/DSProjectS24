#pragma once
#include<SFML/Graphics.hpp>
#include"AVLTrees.h"
#include<iostream>
#include "func.h"

std::string path = "/Users/salman/Desktop/ProjectS24/img/";
std::string pathforFont = "/Users/salman/Desktop/ProjectS24";

//pathway for images for salman: /Users/salman/Desktop/ProjectS24/img/
class Player;
//class CollisionWithItem;


class Player
{
private:

    float calculateDistance(float x1, float y1, float x2, float y2) {
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }

public:
    //AVLTree<items> itemsTree; // AVL tree to store items
    //AVLTree<weapons> weaponsTree;
	sf::Texture pTexture;
	float speed;
	int lives;
	int shield;
	int health;
    int score;
	sf::Sprite p;
	Player();
	~Player();

	//bool closeToAPoint(int x, int y);
	std::string getStrHealth();
    void drawScore(sf::RenderWindow &window);
	void move(std::string dir, sf::Image img);
    int getscore();

    void handleCollision(items& item) {
        //changing the position of the item
        item.item.setPosition(1000,1000);

        //updating player attributes here
        if (item.priority == 1 || item.priority == 2){
            //itemsTree.insert(item);
        }
        else if (item.priority == 3 || item.priority ==4){
            //update player score here
            score += item.score;
            //itemsTree.insert(item);
        }
        else if (item.priority == 5){
            //update player lives here by 1
            lives += item.lives;
            //itemsTree.insert(item);
        }

    }

    void handleCollision(weapons& weapon) {
        //changing the position of the item
        weapon.item.setPosition(1000,1000);

        //updating player inventory here
        //you will be inserting the weapons into AVLTree<weapons> weaponsTree; commented as a public member

    }

    void checkCollisionwItems(items& item) {
        // Assuming each item has position (x, y) and dimensions (width, height)
        //items
        float itemLeft = item.item.getPosition().x;
        float itemRight = itemLeft + item.item.getGlobalBounds().width;
        float itemTop = item.item.getPosition().y;
        float itemBottom = itemTop + item.item.getGlobalBounds().height;

        float playerLeft = p.getPosition().x;
        float playerRight = playerLeft + p.getGlobalBounds().width;
        float playerTop = p.getPosition().y;
        float playerBottom = playerTop + p.getGlobalBounds().height;

        // Check for collision using bounding boxes
        if (playerRight >= itemLeft && playerLeft <= itemRight &&
            playerBottom >= itemTop && playerTop <= itemBottom) {
            // Collision occurred, handle collision
            handleCollision(item);
        }
    }

    void checkCollisionwWeapons(weapons& weapon){
        float weaponLeft = weapon.item.getPosition().x;
        float weaponRight = weaponLeft + weapon.item.getGlobalBounds().width;
        float weaponTop = weapon.item.getPosition().y;
        float weaponBottom = weaponTop + weapon.item.getGlobalBounds().height;

        float playerLeft = p.getPosition().x;
        float playerRight = playerLeft + p.getGlobalBounds().width;
        float playerTop = p.getPosition().y;
        float playerBottom = playerTop + p.getGlobalBounds().height;
        if (playerRight >= weaponLeft && playerLeft <= weaponRight &&
            playerBottom >= weaponTop && playerTop <= weaponBottom) {
            handleCollision(weapon);
        }
    }

};

std::string Player::getStrHealth() {
	// Get health as a string
	return "Lives " + std::to_string(health);
}

int Player::getscore() {
    return score;
}

void Player::drawScore(sf::RenderWindow &window) {
    sf::Font font;
    if (!font.loadFromFile(fontpath+"Retro Gaming.ttf"))
    {
        cout<<"Font not Loaded !\n";
    }
    Text ScoreT;
    ScoreT.setFont(font); // font is a sf::Font
    ScoreT.setString("SCORE: " + std::to_string(getscore()) );
    ScoreT.setPosition(810, 473);
    ScoreT.setCharacterSize(45);
    ScoreT.setFillColor(sf::Color::White);
    ScoreT.setStyle(sf::Text::Bold);
    window.draw(ScoreT);
}


Player::Player()
{
	lives = 1;
	shield = 0;
	speed = 2;
	health = 100;
    score = 0;
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

/*class CollisionWithItem {
private:
public:
    AVLTree<items> itemsTree; // AVL tree to store items
    // Constructor
    CollisionWithItem() {}

    // Method to handle collision with an item
    void handleCollision(Player& player, items& item) {
        //changing the position of the item
        item.item.setPosition(1000,1000);

        //updating player attributes here
        if (item.priority == 1 || item.priority == 2){
            //itemsTree.insert(item);
        }
        else if (item.priority == 3 || item.priority ==4){
            //update player score here
            player.score += item.score;
            //itemsTree.insert(item);
        }
        else if (item.priority == 5){
            //update player lives here by 1
            player.lives += item.lives;
            //itemsTree.insert(item);
        }

    }
};*/