#ifndef SCORE_H
#define SCORE_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "FlyingDemon.hpp"
#include "Skeleton.hpp"
#include "fstream"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Score
{
private:
    sf::Clock clockF;
    sf::Clock clockS;

    sf::Font font;
    sf::Text currentScoreText;
    sf::Text bestScoreText;

    int currentScore;
    int bestScore;

    bool check = false;

public:
    static int globalBestScore;

    Score();
    ~Score();

    void loadBestScore();
    void saveBestScore();

    void update(Player &player);
    void updateFlyingDemon(FlyingDemon &flyingDemon);
    void updateSkeleton(Skeleton &skeleton);
    void addScore(int amount);
    void reset();
    void draw(sf::RenderWindow& window);
    void LoadFont(sf::Font &font, string std);

    static int getGlobalBestScore();
};

#endif