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

public:
    Entity(string Name="- // -", int Hp=10, int Atk=2, float Speed=1);
    virtual ~Entity();

    void setName(string Name);
    void setHp(int Hp);
    void setAtk(int Atk);
    void setSpeed(float Speed);

    string getName();
    int getHp();
    int getAtk(); 
    float getSpeed();

    Entity &operator+=(int Heal);
    Entity &operator-=(int Damage);
    Entity &operator*=(int Heal);
    Entity &operator/=(int Damage);
    friend bool operator==(const Entity a, const Entity b);

    virtual void updateAnimation();
    virtual void move(float x, float y);
    virtual void jump();
    virtual void updatePhysics();
    virtual void attack();
    virtual void defend();
    virtual void hurt();
    virtual void die();
};

#endif