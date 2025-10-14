#ifndef GAMEOVER_H
#define GAMEOVER_H

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "HomeScreen.hpp"
using namespace std;

class GameOver : public HomeScreen
{
private:
    bool isActive = false;

    sf::Texture *backgroundTexture;

    sf::RectangleShape Background;
    sf::RectangleShape PlayAgainButton;
    sf::RectangleShape HomeButton;

    sf::Font font;

    sf::Text GameOverText;
    sf::Text PlayAgainText;
    sf::Text HomeText;

    sf::SoundBuffer buffer;
    sf::Sound sound;

public:
    GameOver(unsigned int width, unsigned int height);
    ~GameOver();

    void render(sf::RenderWindow& window);

    void LoadBackground() override; 

    void DefaultPlayAgain();
    void HoverPlayAgain();
    void DefaultHome();
    void HoverHome();

    sf::RectangleShape getPlayAgainButton();
    sf::RectangleShape getHomeButton();

    //bool getIsActive();
    //void setIsActive(bool isActive);

};

#endif