#ifndef CREDITSSCREEN_H
#define CREDITSSCREEN_H

#pragma once

#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include <iostream>
using namespace std;
using namespace sf;

class CreditsScreen : public Screen
{
private:
    RectangleShape Background;
    RectangleShape BackButton;

    Text Credits;
    Text Back;

public:
    CreditsScreen(unsigned int width, unsigned int height);
    ~CreditsScreen();

    void render(sf::RenderWindow& window);

    void DefaultBack();
    void HoverBack();

    RectangleShape getBackButton();
};

#endif