#ifndef ABOUTSCREEN_H
#define ABOUTSCREEN_H

#pragma once

#include <SFML/Graphics.hpp>
#include "HomeScreen.hpp"
#include <iostream>
using namespace std;
using namespace sf;

class AboutScreen : protected HomeScreen
{
private:
    bool isActive = false;

    RectangleShape Background;
    RectangleShape BackButton;

    Font font;

    Text About;
    Text Back;

public:
    AboutScreen(unsigned int width, unsigned int height);
    ~AboutScreen();

    void render(sf::RenderWindow& window);

    void DefaultBack();
    void HoverBack();

    RectangleShape getBackButton();

    bool getIsActive();
    void setIsActive(bool isActive);

};

#endif