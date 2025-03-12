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
    int currentFrame = 0;       // Track current animation frame

    sf::Clock animationClock;   // Control frame timing
    sf::Clock jumpClock;        // Control jump timing
    const float jumpCooldown = 0.9f;  // Define jump cooldown duration
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
    float groundLevel = 700;
    float xPos=1440/2;
    float yPos=groundLevel;

    sf::RectangleShape hitbox;

public:
    Player(string Name="Hero", int Hp=10, int Atk=3, float Speed=1);
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

    sf::Sprite& get_Sprite();
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

    Player &operator+=(int Heal);
    Player &operator-=(int Damage);

    void updateAnimation();
    void move(float x, float y);
    void jump();
    void updatePhysics();

    //void atk1();
    //void atk2();
    //void atk3();
    //void attack();
    //void hurt();
    //void die();
};

#endif