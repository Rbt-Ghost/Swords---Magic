#ifndef CREDITSSCREEN_H
#define CREDITSSCREEN_H

#pragma once

#include <SFML/Graphics.hpp>
#include "HomeScreen.hpp"
#include <iostream>
using namespace std;
using namespace sf;

class CreditsScreen : protected HomeScreen
{
private:
    bool isActive = false;

    RectangleShape Background;
    RectangleShape BackButton;

    Font font;

    Text Credits;
    Text Back;

public:
    CreditsScreen(unsigned int width, unsigned int height);
    ~CreditsScreen();

    void render(sf::RenderWindow& window);

    void DefaultBack();
    void HoverBack();

    RectangleShape getBackButton();

    bool getIsActive();
    void setIsActive(bool isActive);
};

#endif