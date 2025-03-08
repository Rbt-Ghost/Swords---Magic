#ifndef ENEMY_H
#define ENEMY_H

#pragma once

#include "Entity.hpp"

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
};

#endif