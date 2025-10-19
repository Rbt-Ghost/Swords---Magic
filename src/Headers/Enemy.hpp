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

public:
    Enemy(string Name, int Hp, int Atk, float Speed);
    virtual ~Enemy();

    Enemy& operator+=(int Heal);
    Enemy& operator-=(int Damage);

    virtual void updateLogic(Player &player);
    virtual void move(float x, float y) override;
    virtual bool checkCollisions(Player &player);
    virtual float distance(Player &player);
    virtual bool playerLeft(Player &player);
    virtual bool playerRight(Player &player);
    virtual void playerTakeDmg(Player &player);
    virtual void spawn();
};

#endif