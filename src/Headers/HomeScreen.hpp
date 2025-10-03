#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class HomeScreen
{
private:
    unsigned int width = 1440;
    unsigned int height = 800;

    bool isActive = true;

    sf::Texture *backgroundTexture;

    sf::RectangleShape StartButton;
    sf::RectangleShape HowToPlayButton;
    sf::RectangleShape CreditsButton;
    sf::RectangleShape AboutButton;
    sf::RectangleShape QuitButton;

    sf::Font font;
    
    sf::Text GameTitle;
    sf::Text Start;
    sf::Text HowToPlay;
    sf::Text Credits;
    sf::Text About;
    sf::Text Quit;

    void LoadFont(sf::Font &font, string std);

public:
    HomeScreen(unsigned int width = 1440, unsigned int height = 800);
    ~HomeScreen();

    void processEvents( sf::RenderWindow& window );
    void render( sf::RenderWindow& window );

    void setIsActive(bool isActive);
    bool getIsActive();

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