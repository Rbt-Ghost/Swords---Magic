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

    sf::Clock AtkClock;
    sf::Clock minAtkClock;
    sf::Clock EscapeClock;
    sf::Clock comeDownClock;

    sf::Texture idleTexture;
    sf::Texture flyingTexture;
    sf::Texture attackTexture;
    sf::Texture hurtTexture;
    sf::Texture deathTexture;

    sf::Texture fireballTexture;
    sf::Sprite fireballSprite;

    sf::IntRect idleFrames[4];
    sf::IntRect flyingFrames[4];
    sf::IntRect attackFrames[8];
    sf::IntRect hurtFrames[4];
    sf::IntRect deathFrames[7];
    sf::IntRect Fireball;

    sf::Clock AnimationClock;

    bool isIdle = true;
    bool isFlying = false;
    bool isAttacking = false;
    bool FireballLaunched = false;
    bool isHurt = false;
    bool comedown = false;

    bool rotateUp = true;
    bool rotateDown = false;
    bool FireballDir;
    bool recalculateFdir = true;
    float Fball_angle;

    bool hurtSoundPlayed = false;
    bool deathSoundPlayed = false;
    bool fireballSoundPlayed = false;
    bool flyingSoundPlayed = false;
    
    float groundLevel = 700;
    float fireball_xPos;
    float fireball_yPos;
    int FireballSpeed = 13;
    sf::Vector2f playerPosition;
    sf::Vector2f demonPosition;
    sf::Vector2f direction;

    sf::CircleShape fireballHitbox;

public:
    FlyingDemon(string Name = "Flying Demon", int Hp = 5, int Atk = 1, float Speed = 2);
    ~FlyingDemon();

    void set_isIdle(bool isIdle);
    void set_isFlying(bool isFlying);
    void set_isAttacking(bool isAttacking);
    void set_Fireball(bool FireballLaunched);
    void set_isHurt(bool isHurt);
    void set_fireball_xPos(float fireball_xPos);
    void set_fireball_yPos(float fireball_yPos);
    void set_FireballDir(bool FireballDir);
    void set_comeDown(bool comedown);
    void set_GroundLevel(float groundLevel);

    sf::Sprite& get_FireballSprite();
    sf::CircleShape& get_fireballHitbox();
    bool get_isIdle();
    bool get_isFlying();
    bool get_isAttacking();
    bool get_Fireball();
    bool get_isHurt();
    float get_fireball_xPos();
    float get_fireball_yPos();
    int get_FireballSpeed();
    bool get_FireballDir();
    bool get_comeDown();

    FlyingDemon& operator+=(int Heal);
    FlyingDemon& operator-=(int Damage);

    void updateAnimation() override;
    void updateLogic(Player &player) override;
    void escape();
    void comeDown();
    void ifAttack();
    void moveFireball(float x, float y);
    bool checkFireballCollision(Player &player);
    void playerTakeDmg(Player &player) override;
    void spawn(Player &player);
    void FlyingDemonSounds();
};

#endif