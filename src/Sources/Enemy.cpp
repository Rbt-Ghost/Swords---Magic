#include "..\src\Headers\Enemy.hpp"

    Enemy::Enemy(string Name, int Hp, int Atk, float Speed):
    Entity(Name, Hp, Atk, Speed) 
    {}

    Enemy::~Enemy()
    {}

    Enemy& Enemy::operator+=(int Heal)
    {
        Entity::operator+=(Heal);
        return *this;
    }
    Enemy& Enemy::operator-=(int Damage)
    {
        Entity::operator-=(Damage);
        return *this;
    }

    void Enemy::updateAnimation() {}

    void Enemy::updateLogic(Player &player) {}