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

    sf::Font font;
    sf::Text Start;

    void LoadFont(sf::Font &font, string std);

public:
    HomeScreen(unsigned int width = 1440, unsigned int height = 800);
    ~HomeScreen();

    void processEvents( sf::RenderWindow& window );
    void render( sf::RenderWindow& window );

    void setIsActive(bool isActive);
    bool getIsActive();
};

#endif