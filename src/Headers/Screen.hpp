#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#pragma once

class Screen
{
protected:
    unsigned int width;
    unsigned int height;

    bool isActive = false;

    sf::Texture *backgroundTexture;
    sf::Font font;

public:
    Screen(unsigned int height, unsigned int width);
    virtual ~Screen();

    virtual void setIsActive(bool isActive);
    bool getIsActive();

    float getWidth();
    float getHeight();
    void setWidth(unsigned int width);
    void setHeight(unsigned int height);

    virtual void LoadFont(sf::Font &font, string std);
    virtual void LoadBackground();
    virtual void drawBackground(sf::RenderWindow& window);

    virtual void processEvents( sf::RenderWindow& window );
    virtual void render( sf::RenderWindow& window );
};

#endif