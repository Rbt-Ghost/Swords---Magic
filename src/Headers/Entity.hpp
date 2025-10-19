#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Entity
{
private:
    string Name;
    int Hp;
    int Atk;
    float Speed;

    int currentFrame = 0;
    bool isDead;
    float xPos;
    float yPos;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::RectangleShape hitbox;

protected: 
    virtual void PlaySound(const std::filesystem::path& filename);

public:
    Entity(string Name="- // -", int Hp=10, int Atk=2, float Speed=1);
    virtual ~Entity();

    void setName(string Name);
    void setHp(int Hp);
    void setAtk(int Atk);
    void setSpeed(float Speed);
    void set_currentFrame(int currentFrame);
    void set_isDead(bool isDead);
    void set_xPos(float xPos);
    void set_yPos(float yPos);

    string getName();
    int getHp();
    int getAtk(); 
    float getSpeed();
    int get_currentFrame();
    bool get_isDead();
    float get_xPos();
    float get_yPos();
    sf::Sprite& get_Sprite();
    sf::Texture& get_Texture();
    sf::RectangleShape& get_Hitbox();

    Entity &operator+=(int Heal);
    Entity &operator-=(int Damage);
    Entity &operator*=(int Heal);
    Entity &operator/=(int Damage);
    friend bool operator==(const Entity a, const Entity b);

    virtual void updateAnimation();
    virtual void jump();
    virtual void updatePhysics();
    virtual void move(float x, float y);
    virtual void checkHp();
};

#endif