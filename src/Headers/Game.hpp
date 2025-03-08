#ifndef GAME_HPP
#define GAME_HPP

#pragma once

#include <SFML/Graphics.hpp>
//#include <memory>
#include "Player.hpp"
#include "Enemy.hpp"

class Game 
{
private:
    unsigned int width;
    unsigned int height;


    sf::RenderWindow *window;
    sf::Texture *texture;

    Player *player;

    void processEvents();
    void update();
    void render();

    void handlePlayerInput();
    //void checkCollisions();

    void setW(unsigned int width);
    void setH(unsigned int height);

    unsigned int getW();
    unsigned int getH();

public:
    Game(const unsigned int width=1440, const unsigned int height=800);
    ~Game();

    void run();
};

#endif