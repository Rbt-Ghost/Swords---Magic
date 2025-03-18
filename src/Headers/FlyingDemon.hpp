#ifndef FLYINGDEMON_H
#define FLYINGDEMON_H

#pragma once

#include "Enemy.hpp"
#include "Player.hpp"
#include <iostream>
#include <math.h>
#include <random>
using namespace std;

class FlyingDemon : public Enemy
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
    sf::Texture flyingTexture;
    sf::Texture attackTexture;
    sf::Texture hurtTexture;
    sf::Texture deathTexture;
    sf::Sprite sprite;

    sf::Texture fireballTexture;
    sf::Sprite fireballSprite;

    sf::IntRect idleFrames[4];
    sf::IntRect flyingFrames[4];
    sf::IntRect attackFrames[8];
    sf::IntRect hurtFrames[4];
    sf::IntRect deathFrames[7];
    sf::IntRect Fireball;
    int CurrentFrame = 0;

    sf::Clock AnimationClock;

    bool isIdle = true;
    bool isFlying = false;
    bool isAttacking = false;
    bool FireballLaunched = false;
    bool isHurt = false;
    bool isDead = false;
    bool comedown = false;

    bool rotateUp = true;
    bool rotateDown = false;
    bool FireballDir;
    bool recalculateFdir = true;
    float Fball_angle;
    
    float xPos = 1300;
    float yPos = 700;
    unsigned int groundLevel = 700;
    float fireball_xPos = xPos;
    float fireball_yPos = yPos;
    int FireballSpeed = 13;
    sf::Vector2f playerPosition;
    sf::Vector2f demonPosition;
    sf::Vector2f direction;

    sf::RectangleShape hitbox;
    sf::CircleShape fireballHitbox;

public:
    FlyingDemon(string Name = "Flying Demon", int Hp = 5, int Atk = 1, float Speed = 2);
    ~FlyingDemon();

    void set_isIdle(bool isIdle);
    void set_isFlying(bool isFlying);
    void set_isAttacking(bool isAttacking);
    void set_Fireball(bool FireballLaunched);
    void set_isHurt(bool isHurt);
    void set_isDead(bool isDead);
    void set_CurrentFrame(int CurrentFrame);
    void set_fireball_xPos(float fireball_xPos);
    void set_fireball_yPos(float fireball_yPos);
    void set_FireballDir(bool FireballDir);
    void set_comeDown(bool comedown);

    sf::Sprite& get_Sprite();
    sf::Sprite& get_FireballSprite();
    sf::RectangleShape& get_hitbox();
    sf::CircleShape& get_fireballHitbox();
    bool get_isIdle();
    bool get_isFlying();
    bool get_isAttacking();
    bool get_Fireball();
    bool get_isHurt();
    bool get_isDead();
    float get_xPos();
    float get_yPos();
    float get_fireball_xPos();
    float get_fireball_yPos();
    float get_CurrentFrame();
    int get_FireballSpeed();
    bool get_FireballDir();
    bool get_comeDown();

    FlyingDemon& operator+=(int Heal);
    FlyingDemon& operator-=(int Damage);

    void updateAnimation();
    void FlyingDemonLogic(Player &player);
    void checkHp();
    void escape();
    void comeDown();
    void ifAttack();
    void move(float x, float y);
    void moveFireball(float x, float y);
    bool checkCollisions(Player &player);
    bool checkFireballCollision(Player &player);
    float distance(Player &player);
    bool playerLeft(Player &player);
    bool playerRight(Player &player);
    void playerTakeDmg(Player &player);
    void spawn(Player &player);

};

#endif