#include<SFML/Graphics.hpp>
#include<iostream>
#include <fstream>
#include <SFML/Audio.hpp>
#include "game.h"

using namespace std;
using namespace sf;
int B =1;

string pathFont ="";
string pathImg = "img/";

//pathway for fonts for salman: /Users/salman/Desktop/ProjectS24/

struct HighScore {
    string name;
    int score;
};

bool compareScores(const HighScore& a, const HighScore& b) {
    return a.score < b.score;
}


int main() {
    RenderWindow MainMenu(VideoMode(800, 600), "Main Menu");
    sf::Music menuMusic;
    if (!menuMusic.openFromFile("MainMenu.ogg")) {
        // Error handling if the file fails to load
        std::cerr << "Failed to load background music!" << std::endl;
    }
    menuMusic.play();

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
    exitButton.setPosition(350.f, 400.f);
    exitButton.setCharacterSize(30);
    exitButton.setFillColor(sf::Color::Black);
    exitButton.setStyle(sf::Text::Bold);

    Text highButton;
    highButton.setFont(font); // font is a sf::Font
    highButton.setString("High Scores");
    highButton.setPosition(280.f, 300.f);
    highButton.setCharacterSize(30);
    highButton.setFillColor(sf::Color::Black);
    highButton.setStyle(sf::Text::Bold);

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
                    menuMusic.pause();
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
                    else if (highButton.getGlobalBounds().contains(mousePos)){
                        RenderWindow HighScores(VideoMode(800, 600), "High Scores");
                        Text Hightitle("High Scores", font, 50);
                        title.setPosition(250.f, 50.f);
                        const int MAX_SCORES = 10;
                        HighScore highScores[MAX_SCORES];
                        int numScores = 0;
                        ifstream file("highscores.txt");
                        if (file.is_open()) {
                            string name;
                            int score;
                            while (file >> name >> score && numScores < MAX_SCORES) {
                                highScores[numScores].name = name;
                                highScores[numScores].score = score;
                                ++numScores;
                            }
                            file.close();
                        }
                        else {
                            cout << "Error opening file!" << endl;
                            return 1;
                        }

                        // Sort high scores in increasing order
                        sort(highScores, highScores + numScores, compareScores);

                        Text scoresText("", font, 30);
                        scoresText.setPosition(100.f, 150.f);

                        for (int i = 0; i < numScores; ++i) {
                            scoresText.setString(scoresText.getString() + highScores[i].name + ": " + to_string(highScores[i].score) + "\n");
                        }

                        while (HighScores.isOpen())
                        {
                            Event event;
                            while (HighScores.pollEvent(event))
                            {
                                if (event.type == Event::Closed)
                                    HighScores.close();
                            }

                            HighScores.clear(Color::White);

                            HighScores.draw(title);
                            HighScores.draw(scoresText);

                            HighScores.display();
                        }
                    }
                    menuMusic.play();
                }
            }
        }

        MainMenu.clear(Color::White);
        MainMenu.draw(MainMenuS);

        MainMenu.draw(title);
        MainMenu.draw(playButton);
        MainMenu.draw(exitButton);
        MainMenu.draw(highButton);

        MainMenu.display();
    }


    return 0;
}
