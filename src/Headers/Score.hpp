#ifndef SCORE_H
#define SCORE_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Skeleton.hpp"
#include "FlyingDemon.hpp"
#include "fstream"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Score
{
private:
    sf::Clock clock;
    sf::Clock clock1;
    sf::Clock clock2;

    sf::Font font;
    sf::Text currentScoreText;
    sf::Text bestScoreText;

    int currentScore;
    int bestScore;

    bool checkE1 = false;
    bool checkE2 = false;

public:
    static int globalBestScore;

    Score();
    ~Score();

    void loadBestScore();
    void saveBestScore();

    void update(Player &player);
    void updateFlyingDemon(FlyingDemon &FlyDemon);
    void updateSkeleton(Skeleton &Skeleton);
    void addScore(int amount);
    void reset();
    void draw(sf::RenderWindow& window);
    void LoadFont(sf::Font &font, string std);

    static int getGlobalBestScore();
};

#endif