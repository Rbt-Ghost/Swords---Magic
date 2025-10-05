#ifndef HOWTOPLAYSCREEN_H
#define HOWTOPLAYSCREEN_H

#pragma once

#include <SFML/Graphics.hpp>
#include "HomeScreen.hpp"
#include <iostream>
using namespace std;

class HowToPlayScreen : protected HomeScreen
{

private:
    bool isActive = false;

    sf::RectangleShape Background;
    sf::RectangleShape BackButton;
    
    sf::Font font;

    sf::Text Instructions;
    sf::Text Back;

public:
    HowToPlayScreen(unsigned int width, unsigned int height);
    ~HowToPlayScreen();

    void render(sf::RenderWindow& window);

    void DefaultBack();
    void HoverBack();

    sf::RectangleShape getBackButton();

    bool getIsActive();
    void setIsActive(bool isActive);
};

#endif