#ifndef GAME_HPP
#define GAME_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "FlyingDemon.hpp"
#include <math.h>

class Game
{
private:
    unsigned int width;
    unsigned int height;

    sf::Clock clock;
    sf::Clock DefendClock;
    sf::Clock spawnClock;
    sf::RenderWindow *window;
    sf::Texture *texture;

    Player *player;
    FlyingDemon *FlyDemon[4];

    bool checkAtk1 = true;

    void processEvents();
    void update();
    void render();

    void handlePlayerInput();
    
    void playerAttack();
    void playerDefend();
    void playerMoveR();
    void playerMoveL();
    void playerJump();

    void setW(unsigned int width);
    void setH(unsigned int height);

    unsigned int getW();
    unsigned int getH();

public:
    Game(const unsigned int width = 1440, const unsigned int height = 800);
    ~Game();

    void run();
};

#endif