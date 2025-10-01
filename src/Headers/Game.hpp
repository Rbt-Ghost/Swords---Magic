#ifndef GAME_HPP
#define GAME_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

    sf::Font font;
    sf::Text Start;

    bool isHomescreenActive = true;
    bool checkAtk1 = true;

    sf::Music backgroundMusic;

    void processEvents();
    void update();
    void render();

    void Home_ProcessEvents();
    void Home_Render();

    void handlePlayerInput();
    void Home_handlePlayerInput();
    
    void playerAttack();
    void playerDefend();
    void playerMoveR();
    void playerMoveL();
    void playerJump();

    void LoadFont(sf::Font &font, string std);

    void PlayMusic(const std::filesystem::path& filename);

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