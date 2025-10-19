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

    sf::IntRect idleFrames[11];
    sf::IntRect attackFrames[18];
    sf::IntRect hurtFrames[8];
    sf::IntRect deathFrames[15];
    sf::IntRect walkFrames[13];
    sf::IntRect reactingFrames[4];

    sf::Clock AnimationClock;

    sf::SoundBuffer buffer;
    sf::Sound sound;

    bool isIdle = true;
    bool isAttacking = false;
    bool isHurt = false;
    bool isWalking = false;
    bool isReacting = false;

    float groundLevel = 700;
    int k=0;

    bool hurtSoundPlayed = false;
    bool deathSoundPlayed = false;
    bool attackSoundPlayed = false;
    bool walkSoundPlayed = false;

    void PlaySound(const std::filesystem::path& filename) override;

public:
    Skeleton(string Name = "Skeleton Warrior", int Hp = 10, int Atk = 1, float Speed = 2);
    ~Skeleton();

    sf::Sound& get_Sound();

    void updateAnimation() override;
    void updateLogic(Player &layer) override;
    bool Reacting();
    void spawn() override;
    void SkeletonSounds();
};

#endif