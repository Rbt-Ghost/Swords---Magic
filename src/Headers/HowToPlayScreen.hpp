#ifndef HOWTOPLAYSCREEN_H
#define HOWTOPLAYSCREEN_H

#pragma once

#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include <iostream>
using namespace std;

class HowToPlayScreen : public Screen
{

private:
    sf::RectangleShape Background;
    sf::RectangleShape BackButton;

    sf::Text Instructions;
    sf::Text Back;

public:
    HowToPlayScreen(unsigned int width, unsigned int height);
    ~HowToPlayScreen();

    void render(sf::RenderWindow& window);

    void DefaultBack();
    void HoverBack();

    sf::RectangleShape getBackButton();
};

#endif