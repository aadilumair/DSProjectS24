#include<SFML/Graphics.hpp>
#include<iostream>
#include "game.h"

using namespace std;
using namespace sf;

string pathFont ="/Users/salman/Desktop/ProjectS24/";


int main() {
    RenderWindow MainMenu(VideoMode(800, 600), "Main Menu");

    Font font;
    font.loadFromFile(pathFont+"Retro Gaming.ttf");

    /*Text title("Main Menu", font, 50);
    title.setPosition(250.f, 50.f);*/


    Text title;
    title.setFont(font); // font is a sf::Font
    title.setString("Main Menu");
    title.setPosition(250.f, 50.f);
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);

    /*Text playButton("Play", font, 30);
    playButton.setPosition(350.f, 200.f);*/

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

    /*Text exitButton("Exit", font, 30);
    exitButton.setPosition(350.f, 300.f);*/



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
                        cout << "Play button clicked!" << endl;
                        // game will start etc.
                        // add tehse two lines smwehre accordingly
                           Game g;
                           g.startGame();
                    }
                    else if (exitButton.getGlobalBounds().contains(mousePos))
                    {
                        cout << "Exit button clicked!" << endl;
                        MainMenu.close();
                    }
                }
            }
        }

        MainMenu.clear(Color::White);

        MainMenu.draw(title);
        MainMenu.draw(playButton);
        MainMenu.draw(exitButton);

        MainMenu.display();
    }


    return 0;
}
