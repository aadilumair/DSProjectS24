#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<random>
#include<time.h>

std::string enePath = "img/";

int F = 6;

class Enemy
{
public:
    //creating a sprite to display the item
    sf::Sprite ene;
    sf::Texture tex;

    bool hitShield;
    int health;

    Enemy(int x, int y) {
        tex.loadFromFile(enePath + "warlord-helmet.png");
        ene.setTexture(tex);
        ene.setScale(0.03, 0.03);
        ene.setPosition(x, y);

        srand(time(0));
        health = (rand() % 100) + 1;
        hitShield = rand() > (RAND_MAX / 2);


    }

    float getAbs() {
        return sqrt(pow(ene.getPosition().x, 2) + pow(ene.getPosition().y, 2));
    }

    bool operator<(Enemy other) {
        return this->getAbs() < other.getAbs();
    }

    bool operator<=(Enemy other) {
        return this->getAbs() <= other.getAbs();
    }

    bool operator>(Enemy other) {
        return !(*this < other);
    }

    bool operator>=(Enemy other) {
        return !(*this <= other);
    }
};

