//
// Created by Salman Umar on 5/1/24.
//

#ifndef PROJECTS24_FUNC_H
#define PROJECTS24_FUNC_H
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

string pathway = "/Users/salman/Desktop/ProjectS24/img/";

//make a character and define its health
//make a health bar and show on the game UI

//items class and derive health and shield potions from it
class items {
public:
    //properties of the items (could be one or more)
    int health;
    int shield;
    int score;
    int lives;

    //creating a sprite to display the item
    Sprite item;
    Texture tex;

    // Getters for common properties
    int getHealth(){
        return health;
    }
    int getShield(){
        return shield;
    }
    int getScore(){
        return score;
    }
    int getExtraLives(){
        return lives;
    }
};

//derived class representing a health bandage
class Bandages : public items{
public:
    Bandages(int x, int y){
        tex.loadFromFile(pathway+"Bandages.png");
        item.setTexture(tex);
        item.setScale(0.06, 0.06);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        health = 15;
        shield = 0;
        score = 0;
        lives = 0;
    }
};

class Shields : public items{
public:
    Shields(int x, int y){
        tex.loadFromFile(pathway+"Shields.png");
        item.setTexture(tex);
        item.setScale(0.09, 0.09);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        health = 0;
        shield = 25;
        score = 0;
        lives = 0;
    }
};

class SlurpJ : public items{
public:
    SlurpJ(int x, int y){
        tex.loadFromFile(pathway+"Shields.png");
        item.setTexture(tex);
        item.setScale(0.09, 0.09);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        health = 0;
        shield = 25;
        score = 0;
        lives = 0;
    }
};

class Coins : public items{
public:
    Coins(int x, int y){
        tex.loadFromFile(pathway+"Coins.png");
        item.setTexture(tex);
        item.setScale(0.09, 0.09);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        health = 0;
        shield = 0;
        score = 100;
        lives = 0;
    }
};

class Treasure : public items{
public:
    Treasure(int x, int y){
        tex.loadFromFile(pathway+"Treasure.png");
        item.setTexture(tex);
        item.setScale(0.09, 0.09);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        health = 0;
        shield = 0;
        score = 100;
        lives = 0;
    }
};

class Hearts : public items{
public:
    Hearts(int x, int y){
        tex.loadFromFile(pathway+"Hearts.png");
        item.setTexture(tex);
        item.setScale(0.2, 0.2);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        health = 0;
        shield = 0;
        score = 0;
        lives = 1;
    }
};
//items class ends here

//weapons class and derive grenades etc. from it
class weapons {
public:
    //properties of the items (could be one or more)
    int uses;
    int damage;

    //creating a sprite to display the item
    Sprite item;
    Texture tex;

    // Getters for common properties
    int getDamage(){
        return damage;
    }
    int getUses(){
        return uses;
    }
};

//derived class representing a health bandage
class Fists : public weapons{
public:
    Fists(int x, int y){
        tex.loadFromFile(pathway+"fists.png");
        item.setTexture(tex);
        item.setScale(0.2, 0.2);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        uses = 20000;
        damage = 10;
    }
};

class Grenades : public weapons{
public:
    Grenades(int x, int y){
        tex.loadFromFile(pathway+"fists.png");
        item.setTexture(tex);
        item.setScale(0.09, 0.09);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        uses = 1;
        damage = 50;
    }
};

class Axe : public weapons{
public:
    Axe(int x, int y){
        tex.loadFromFile(pathway+"fists.png");
        item.setTexture(tex);
        item.setScale(0.09, 0.09);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        uses = 20;
        damage = 50;
    }
};

class Spear : public weapons{
public:
    Spear(int x, int y){
        tex.loadFromFile(pathway+"fists.png");
        item.setTexture(tex);
        item.setScale(0.09, 0.09);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        uses = 1;
        damage = 200;
    }
};

class knives : public weapons {
public:
    knives(int x, int y) {
        tex.loadFromFile(pathway+"fists.png");
        item.setTexture(tex);
        item.setScale(0.2, 0.2);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        uses = 5;
        damage = 15;
    }
};



#endif //PROJECTS24_FUNC_H
