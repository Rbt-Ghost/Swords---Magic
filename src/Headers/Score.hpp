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
#include <unordered_set> // added
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

    // track which enemy instances already awarded score on death
    std::unordered_set<const void*> awardedEnemies;

    // salt used when hashing saved score to prevent trivial tampering
    const std::string scoreSalt = "SwordsMagicSalt_v1";

    // compute SHA-256 hex string for input
    static std::string sha256(const std::string &input);

    // XOR-encrypt then hex-encode; and the reverse (hex-decode then XOR-decrypt)
    static std::string xorEncryptToHex(const std::string &plain, const std::string &key);
    static std::string xorDecryptFromHex(const std::string &hexStr, const std::string &key);
    static bool isDecimalString(const std::string &s);

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