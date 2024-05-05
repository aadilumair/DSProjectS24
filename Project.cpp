#include<SFML/Graphics.hpp>
#include<iostream>
#include "game.h"

using namespace std;
using namespace sf;

string pathFont ="";
string pathImg = "img/";

//pathway for fonts for salman: /Users/salman/Desktop/ProjectS24/


int main() {
    RenderWindow MainMenu(VideoMode(800, 600), "Main Menu");
    Texture MainMenuT;
    //resize the background image !
    MainMenuT.loadFromFile(pathImg+"background.png");
    sf::Sprite MainMenuS(MainMenuT);

    Font font;
    font.loadFromFile(pathFont+"Retro Gaming.ttf");

    Text title;
    title.setFont(font); // font is a sf::Font
    title.setString("Main Menu");
    title.setPosition(250.f, 50.f);
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);

    Text playButton;
    playButton.setFont(font); // font is a sf::Font
    playButton.setString("Play");
    playButton.setPosition(350.f, 200.f);
    playButton.setCharacterSize(30);
    playButton.setFillColor(sf::Color::Black);
    playButton.setStyle(sf::Text::Bold);

    Text exitButton;
    exitButton.setFont(font); // font is a sf::Font
    exitButton.setString("Exit");
    exitButton.setPosition(350.f, 300.f);
    exitButton.setCharacterSize(30);
    exitButton.setFillColor(sf::Color::Black);
    exitButton.setStyle(sf::Text::Bold);

    while (MainMenu.isOpen())
    {
        Event event;
        while (MainMenu.pollEvent(event))
        {
            if (event.type == Event::Closed)
                MainMenu.close();

            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    Vector2f mousePos = MainMenu.mapPixelToCoords(Mouse::getPosition(MainMenu));

                    if (playButton.getGlobalBounds().contains(mousePos))
                    {
                        // game will start etc.
                           Game g;
                           g.startGame();
                    }
                    else if (exitButton.getGlobalBounds().contains(mousePos))
                    {
                        MainMenu.close();
                    }
                }
            }
        }

        MainMenu.clear(Color::White);
        MainMenu.draw(MainMenuS);

        MainMenu.draw(title);
        MainMenu.draw(playButton);
        MainMenu.draw(exitButton);

        MainMenu.display();
    }


    return 0;
}
