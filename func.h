//
// Created by Salman Umar on 5/1/24.
//

#ifndef PROJECTS24_FUNC_H
#define PROJECTS24_FUNC_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>
using namespace std;
using namespace sf;

string pathway = "img/";
string fontpath ="";

//pathway for images for salman: /Users/salman/Desktop/ProjectS24/img/
//pathway for fonts for salman: /Users/salman/Desktop/ProjectS24/

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

    float getAbs() {
        return sqrt(pow(item.getPosition().x, 2) + pow(item.getPosition().y, 2));
    }

    bool operator<(items other) {
        return this->getAbs() < other.getAbs();
    }

    bool operator<=(items other) {
        return this->getAbs() <= other.getAbs();
    }

    bool operator>(items other) {
        return !(*this < other);
    }

    bool operator>=(items other) {
        return !(*this <= other);
    }
};

//derived class representing a health bandage
class Bandages : public items{
public:
    Bandages(int x, int y){
        tex.loadFromFile(pathway+"Bandages.png");
        item.setTexture(tex);
        item.setScale(0.05, 0.05);
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
        item.setScale(0.06, 0.06);
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
        item.setScale(0.15, 0.15);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        health = 0;
        shield = 0;
        score = 0;
        lives = 1;
    }
};
//items class ends here

//-----------------WEAPONS-----------------
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
        item.setScale(0.18, 0.18);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        uses = 20000;
        damage = 10;
    }
};

class Grenades : public weapons{
public:
    Grenades(int x, int y){
        tex.loadFromFile(pathway+"Grenades.png");
        item.setTexture(tex);
        item.setScale(0.06, 0.06);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        uses = 1;
        damage = 50;
    }
};

class Axe : public weapons{
public:
    Axe(int x, int y){
        tex.loadFromFile(pathway+"Axe.png");
        item.setTexture(tex);
        item.setScale(0.06, 0.06);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        uses = 20;
        damage = 50;
    }
};

class knives : public weapons {
public:
    knives(int x, int y) {
        tex.loadFromFile(pathway+"Knives.png");
        item.setTexture(tex);
        item.setScale(0.09, 0.09);
        item.setPosition(x, y);

        // Set properties specific to RedFood
        uses = 5;
        damage = 15;
    }
};

void drawinventory(sf::RenderWindow &window,sf::Font font){
    Sprite grenadespr,axespr,knivesspr,infinityspr;
    Texture grenadetex,axetex,knivestex,infinitytex;
    Text grenT,axeT,knivesT,ScoreT;

    Fists fistsInstance(850, 150);

    infinitytex.loadFromFile(pathway+"infinity.png");
    infinityspr.setTexture(infinitytex);
    infinityspr.setScale(0.12, 0.12);
    infinityspr.setPosition(937, 145);
    window.draw(infinityspr);



    //std::to_string(countercallfromAVL);
    grenT.setFont(font); // font is a sf::Font
    grenT.setString("0");
    grenT.setPosition(945,218);
    grenT.setCharacterSize(45);
    grenT.setFillColor(sf::Color::White);
    grenT.setStyle(sf::Text::Bold);

    axeT.setFont(font); // font is a sf::Font
    axeT.setString("0");
    axeT.setPosition(945,293);
    axeT.setCharacterSize(45);
    axeT.setFillColor(sf::Color::White);
    axeT.setStyle(sf::Text::Bold);

    knivesT.setFont(font); // font is a sf::Font
    knivesT.setString("0");
    knivesT.setPosition(945,368);
    knivesT.setCharacterSize(45);
    knivesT.setFillColor(sf::Color::White);
    knivesT.setStyle(sf::Text::Bold);

    ScoreT.setFont(font); // font is a sf::Font
    ScoreT.setString("SCORE: 0");
    ScoreT.setPosition(810, 473);
    ScoreT.setCharacterSize(45);
    ScoreT.setFillColor(sf::Color::White);
    ScoreT.setStyle(sf::Text::Bold);

    grenadetex.loadFromFile(pathway+"Grenades.png");
    grenadespr.setTexture(grenadetex);
    grenadespr.setScale(0.16, 0.16);
    grenadespr.setPosition(835, 207);
    window.draw(grenadespr);

    axetex.loadFromFile(pathway+"Axe.png");
    axespr.setTexture(axetex);
    axespr.setScale(0.16, 0.16);
    axespr.setPosition(835, 285);
    window.draw(axespr);

    knivestex.loadFromFile(pathway+"Knives.png");
    knivesspr.setTexture(knivestex);
    knivesspr.setScale(0.3, 0.3);
    knivesspr.setPosition(837, 363);
    window.draw(knivesspr);

    window.draw(fistsInstance.item);
    window.draw(axeT);
    window.draw(grenT);
    window.draw(knivesT);
    window.draw(ScoreT);

}

void drawhealthbar(sf::RenderWindow &window,sf::Font font){
    Sprite HealthSpr,ShieldSpr;
    Texture HealthTex,ShieldTex;

    HealthTex.loadFromFile(pathway+"Hearts.png");
    HealthSpr.setTexture(HealthTex);
    HealthSpr.setScale(0.3, 0.3);
    HealthSpr.setPosition(785, 25);
    window.draw(HealthSpr);

    ShieldTex.loadFromFile(pathway+"Shields.png");
    ShieldSpr.setTexture(ShieldTex);
    ShieldSpr.setScale(0.15, 0.15);
    ShieldSpr.setPosition(795, 85);
    window.draw(ShieldSpr);
}

void drawsidebar(sf::RenderWindow &window){
    sf::Font font;
    if (!font.loadFromFile(fontpath+"Retro Gaming.ttf"))
    {
        cout<<"Font not Loaded !\n";
    }

    drawinventory(window,font);
    drawhealthbar(window,font);

}





#endif //PROJECTS24_FUNC_H
