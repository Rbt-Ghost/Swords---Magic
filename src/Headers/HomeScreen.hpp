#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screen.hpp"

using namespace std;

class HomeScreen : public Screen
{
private:
    sf::RectangleShape StartButton;
    sf::RectangleShape HowToPlayButton;
    sf::RectangleShape CreditsButton;
    sf::RectangleShape AboutButton;
    sf::RectangleShape QuitButton;
    
    sf::Text GameTitle;
    sf::Text Start;
    sf::Text HowToPlay;
    sf::Text Credits;
    sf::Text About;
    sf::Text Quit;

public:
    HomeScreen(unsigned int width, unsigned int height);
    ~HomeScreen();

    void render( sf::RenderWindow& window ) override;

    sf::RectangleShape getStartButton();
    sf::RectangleShape getHowToPlayButton();
    sf::RectangleShape getCreditsButton();
    sf::RectangleShape getAboutButton();
    sf::RectangleShape getQuitButton();
    
    void DefaultStart();
    void HoverStart();
    void DefaultHowToPlay();
    void HoverHowToPlay();
    void DefaultCredits();
    void HoverCredits();
    void DefaultAbout();
    void HoverAbout();
    void DefaultQuit();
    void HoverQuit();
};

#endif