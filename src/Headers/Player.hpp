#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
using namespace std;

class Player : public Entity    
{
private:
    sf::Texture idleTexture;
    sf::Texture walkTexture;
    sf::Texture jumpTexture;
    sf::Texture defendTexture;
    sf::Texture attackTexture1;
    sf::Texture attackTexture2;
    sf::Texture attackTexture3;
    sf::Texture runningTexture;
    sf::Texture hurtTexture;
    sf::Texture deathTexture;
    sf::Sprite sprite;

    sf::Texture HpBarTexture100;
    sf::Texture HpBarTexture90;
    sf::Texture HpBarTexture80;
    sf::Texture HpBarTexture70;
    sf::Texture HpBarTexture60;
    sf::Texture HpBarTexture50;
    sf::Texture HpBarTexture40;
    sf::Texture HpBarTexture30;
    sf::Texture HpBarTexture20;
    sf::Texture HpBarTexture10;
    sf::Sprite HpBar;

    sf::IntRect idleFrames[7];  // Idle animation frames
    sf::IntRect walkFrames[8];  // Walk animation frames
    sf::IntRect jumpFrames[5];  // Jump animation frames
    sf::IntRect defendFrames[6];  // Defend animation frames
    sf::IntRect attackFrames1[6];  // Attack animation frames
    sf::IntRect attackFrames2[5];  // Attack animation frames
    sf::IntRect attackFrames3[6];  // Attack animation frames
    sf::IntRect runningFrames[8];  // Running animation frames
    sf::IntRect hurtFrames[4];  // Hurt animation frames
    sf::IntRect deathFrames[12];  // Die animation frames
    sf::IntRect Hp_Bar;
    int currentFrame = 0;       // Track current animation frame

    sf::Clock animationClock;  
    sf::Clock jumpClock; 
    const float jumpCooldown = 0.715f;  
    sf::Clock defendClock;
    const float defendCooldown = 2.f;
    

    bool isMovingR = false;
    bool isMovingL = false;
    bool isRunning = false;
    bool isJumping = false;
    bool isFalling = false;
    bool isDefending = false;
    bool isAttacking1 = false;
    bool isAttacking2 = false;
    bool isAttacking3 = false;
    bool isHurt = false;
    bool isDead = false;

    float yVelocity = 0;
    float groundLevel = 710;
    float xPos=1440/2;
    float yPos=500;

    sf::RectangleShape hitbox;

public:
    Player(string Name="Hero", int Hp=10, int Atk=3, float Speed=1.5);
    virtual ~Player();

    void set_isMovingR(bool isMovingR);
    void set_isMovingL(bool isMovingL);
    void set_isJumping(bool isJumping);
    void set_isDefending(bool isDefending);
    void set_isAttacking1(bool isAttacking1);
    void set_isAttacking2(bool isAttacking2);
    void set_isAttacking3(bool isAttacking3);
    void set_isRunning(bool isRunning);
    void set_isHurt(bool isHurt);
    void set_isDead(bool isDead);
    void set_currentFrame(int currentFrame);
    void set_GroundLevel(float groundLevel);
    void set_xPos(float xPos);
    void set_yPos(float yPos);

    sf::Sprite& get_Sprite();
    sf::Sprite& get_Hp_Bar();
    sf::RectangleShape& get_Hitbox();
    int get_currentFrame();
    bool get_isMovingR();
    bool get_isMovingL();
    bool get_isJumping();
    bool get_isDefending();
    bool get_isAttacking1();
    bool get_isAttacking2();
    bool get_isAttacking3();
    bool get_isRunning();
    bool get_isHurt();
    bool get_isDead();
    float get_xPos();
    float get_yPos();
    bool get_isFalling();
    float get_groundLevel();

    Player &operator+=(int Heal);
    Player &operator-=(int Damage);

    void updateAnimation();
    void move(float x, float y);
    void jump();
    void updatePhysics();
    void checkHp();
    void respawn();
};

#endif