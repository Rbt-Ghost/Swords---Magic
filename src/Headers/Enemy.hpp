#ifndef ENEMY_H
#define ENEMY_H

#pragma once

#include "Entity.hpp"
#include "Player.hpp"

class Enemy : public Entity
{
private:
    string Name;
    int Hp;
    int Atk;
    float Speed;

    int MaxHP;

public:
    Enemy(string Name, int Hp, int Atk, float Speed);
    virtual ~Enemy();

    int get_MaxHP();

    Enemy& operator+=(int Heal);
    Enemy& operator-=(int Damage);

    virtual void updateLogic(Player &player);
    virtual bool checkCollisions(Player &player);
    virtual float distance(Player &player);
    virtual bool playerLeft(Player &player);
    virtual bool playerRight(Player &player);
    virtual void playerTakeDmg(Player &player);
    virtual void spawn();
};

#endif