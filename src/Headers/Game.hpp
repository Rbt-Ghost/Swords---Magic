#ifndef GAME_HPP
#define GAME_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "FlyingDemon.hpp"
#include "Skeleton.hpp"
#include "GameRoom.hpp"
#include "Score.hpp"
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
    GameRoom *gameRoom;
    Player *player;
    FlyingDemon *FlyDemon[2];
    Skeleton *skeleton[3];
    Score *score;

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