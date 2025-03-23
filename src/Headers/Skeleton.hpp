#ifndef SKELETON_H
#define SKELETON_H

#pragma once

#include "SFML\Graphics.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "iostream"
#include "math.h"
using namespace std;

class Skeleton : public Enemy
{
    private:
    string Name;
    int Hp;
    int Atk;
    float Speed;

    sf::Clock AtkClock;
    sf::Clock EscapeClock;
    sf::Clock comeDownClock;

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
    sf::IntRect Fireball;
    int CurrentFrame = 0;

    sf::Clock AnimationClock;

    bool isIdle = true;
    bool isAttacking = true;
    bool isHurt = false;
    bool isDead = false;
    bool isWalfing = false;
    bool isReacting = true;

    float groundLevel = 700;
    float xPos = 100;
    float yPos = groundLevel;

public:
    Skeleton(string Name = "Skeleton Warrior", int Hp = 10, int Atk = 1, float Speed = 2);
    ~Skeleton();

    sf::Sprite& get_Sprite();
    sf::RectangleShape& get_hitbox();

    void updateAnimation();
    void SkeletonLogic(Player &layer);
    void checkHp();
    void ifAttack();
    void move(float x, float y);
    bool checkCollisions(Player &player);
    float distance(Player &player);
    bool playerLeft(Player &player);
    bool playerRight(Player &player);
    void playerTakeDmg(Player &player);
    void spawn(Player &player);
};

#endif