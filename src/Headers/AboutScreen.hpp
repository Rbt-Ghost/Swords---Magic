#ifndef ABOUTSCREEN_H
#define ABOUTSCREEN_H

#pragma once

#include <SFML/Graphics.hpp>
#include "Screen.hpp"
#include <iostream>
using namespace std;
using namespace sf;

class AboutScreen : public Screen
{
private:
    RectangleShape Background;
    RectangleShape BackButton;

    Text About;
    Text Back;

public:
    AboutScreen(unsigned int width, unsigned int height);
    ~AboutScreen();

    void render(sf::RenderWindow& window);

    void DefaultBack();
    void HoverBack();

    RectangleShape getBackButton();
};

#endif