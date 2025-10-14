#ifndef GAME_HPP
#define GAME_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "HomeScreen.hpp"
#include "HowToPlayScreen.hpp"
#include "CreditsScreen.hpp"
#include "AboutScreen.hpp"
#include "GameOver.hpp"
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

    sf::Clock DefendClock;
    sf::Clock spawnClock;
    
    sf::RenderWindow *window;
    HomeScreen *homeScreen;
    HowToPlayScreen *howToPlayScreen;
    CreditsScreen *creditsScreen;
    AboutScreen *aboutScreen;
    GameOver *gameOverScreen;
    GameRoom *gameRoom;
    Player *player;
    FlyingDemon *FlyDemon[2];
    Skeleton *skeleton[3];
    Score *score;

    bool checkAtk1 = true;

    bool wasHoverStart = false;
    bool wasHoverHowToPlay = false;
    bool wasHoverCredits = false;
    bool wasHoverAbout = false;
    bool wasHoverQuit = false;

    bool wasHoverPlayAgain = false;
    bool wasHoverHome = false;

    bool isGamePaused = false;
    bool currentPauseKeyState = false;

    sf::Music backgroundMusic;
    sf::SoundBuffer buffer;
    sf::Sound sound;

    sf::RectangleShape pauseBackground;
    sf::Font font;
    sf::Text pauseText;

    void processEvents();
    void update();
    void render();

    void handlePlayerInput();

    void Home_handlePlayerInput();

    void GameOver_handlePlayerInput();

    void resetGame();

    void playerAttack();
    void playerDefend();
    void playerMoveR();
    void playerMoveL();
    void playerJump();

    void PlayMusic(const std::filesystem::path& filename);
    void PlaySound(const std::filesystem::path& filename);

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