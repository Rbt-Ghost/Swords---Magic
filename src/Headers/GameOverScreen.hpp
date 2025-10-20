#ifndef GAMEOVER_H
#define GAMEOVER_H

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Screen.hpp"

using namespace std;
class GameOverScreen : public Screen
{
private:
    sf::RectangleShape PlayAgainButton;
    sf::RectangleShape HomeButton;

    sf::Text GameOverText;
    sf::Text PlayAgainText;
    sf::Text HomeText;

    sf::SoundBuffer buffer;
    sf::Sound sound;

public:
    GameOverScreen(unsigned int width, unsigned int height);
    ~GameOverScreen();

    void render(sf::RenderWindow& window) override;

    void LoadBackground() override;
    void drawBackground(sf::RenderWindow& window) override;

    void DefaultPlayAgain();
    void HoverPlayAgain();
    void DefaultHome();
    void HoverHome();

    sf::RectangleShape getPlayAgainButton();
    sf::RectangleShape getHomeButton();

    void setIsActive(bool isActive) override;

};

#endif