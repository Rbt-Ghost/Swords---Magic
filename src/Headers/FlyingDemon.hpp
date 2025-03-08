#ifndef FLYINGDEMON_H
#define FLYINGDEMON_H

#pragma once

#include "Enemy.hpp"

class FlyingDemon : public Enemy
{
private:
    string Name;
    int Hp;
    int Atk;
    float Speed;

    sf::Texture idleTexture;
    sf::Texture flyingTexture;
    sf::Texture attackTexture;
    sf::Texture hurtTexture;
    sf::Texture deathTexture;
    sf::Sprite sprite;

    sf::IntRect idleFrames[4];
    sf::IntRect flyingFrames[4];
    sf::IntRect attackFrames[8];
    sf::IntRect hurtFrames[4];
    sf::IntRect deathFrames[7];
    int CurrentFrame = 0;

    sf::Clock AnimationClock;

    bool isIdle = true;
    bool isFlying = false;
    bool isAttacking = false;
    bool isHurt = false;
    bool isDead = false; 

public:
    FlyingDemon(string Name = "Flying Demon", int Hp = 5, int Atk = 1, float Speed = 1.85);
    ~FlyingDemon();

    void set_isIdle(bool isIdle);
    void set_isFlying(bool isFlying);
    void set_isAttacking(bool isAttacking);
    void set_isHurt(bool isHurt);
    void set_isDead(bool isDead);

    sf::Sprite& getSprite();
    bool get_isIdle();
    bool get_isFlying();
    bool get_isAttacking();
    bool get_isHurt();
    bool get_isDead();

    void updateAnimation();

};

#endif