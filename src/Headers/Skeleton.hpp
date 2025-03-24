#ifndef SKELETON_H
#define SKELETON_H

#pragma once

#include "SFML\Graphics.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "iostream"
#include <random>
#include "math.h"
using namespace std;

class Skeleton : public Enemy
{
private:

    sf::Clock AtkClock;
    sf::Clock EscapeClock;
    sf::Clock ReactClock;

    sf::Texture idleTexture;
    sf::Texture attackTexture;
    sf::Texture hurtTexture;
    sf::Texture deathTexture;
    sf::Texture walkTexture;
    sf::Texture reactingTexture;

    sf::Sprite sprite;
    sf::RectangleShape hitbox;

    sf::IntRect idleFrames[11];
    sf::IntRect attackFrames[18];
    sf::IntRect hurtFrames[8];
    sf::IntRect deathFrames[15];
    sf::IntRect walkFrames[13];
    sf::IntRect reactingFrames[4];
    int CurrentFrame = 0;

    sf::Clock AnimationClock;

    bool isIdle = true;
    bool isAttacking = false;
    bool isHurt = false;
    bool isDead = false;
    bool isWalking = false;
    bool isReacting = false;

    float groundLevel = 700;
    float xPos = 100;
    float yPos = groundLevel;
    int k=0;

public:
    Skeleton(string Name = "Skeleton Warrior", int Hp = 10, int Atk = 1, float Speed = 2);
    ~Skeleton();

    sf::Sprite& get_Sprite();
    sf::RectangleShape& get_hitbox();

    bool get_isDead();
    int get_CurrentFrame();

    void updateAnimation();
    void SkeletonLogic(Player &layer);
    void checkHp();
    void ifAttack();
    void move(float x, float y);
    bool checkCollisions(Player &player);
    float distance(Player &player);
    bool playerLeft(Player &player);
    bool playerRight(Player &player);
    bool Reacting();
    void playerTakeDmg(Player &player);
    void spawn();
};

#endif