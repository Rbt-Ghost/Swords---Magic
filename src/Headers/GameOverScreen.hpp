#ifndef GAMEOVER_H
#define GAMEOVER_H

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "HomeScreen.hpp"
using namespace std;

class GameOverScreen
{
private:
    bool isActive = false;

    unsigned int width;
    unsigned int height;

    sf::Texture *backgroundTexture;

    sf::RectangleShape PlayAgainButton;
    sf::RectangleShape HomeButton;

    sf::Font font;

    sf::Text GameOverText;
    sf::Text PlayAgainText;
    sf::Text HomeText;

    sf::SoundBuffer buffer;
    sf::Sound sound;

public:
    GameOverScreen(unsigned int width, unsigned int height);
    ~GameOverScreen();

    void processEvents(sf::RenderWindow& window);

    void render(sf::RenderWindow& window);

    void LoadFont(sf::Font &font, string std);
    void LoadBackground();
    void drawBackground(sf::RenderWindow& window);

    void DefaultPlayAgain();
    void HoverPlayAgain();
    void DefaultHome();
    void HoverHome();

    sf::RectangleShape getPlayAgainButton();
    sf::RectangleShape getHomeButton();

    bool getIsActive();
    void setIsActive(bool isActive);

    void setWidth(unsigned int width);
    void setHeight(unsigned int height);

    float getWidth();
    float getHeight();

};

#endif