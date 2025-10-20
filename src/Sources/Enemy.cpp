#include "..\src\Headers\Enemy.hpp"

Enemy::Enemy(string Name, int Hp, int Atk, float Speed) : 
Entity(Name, Hp, Atk, Speed)
{
}

Enemy::~Enemy()
{
}

Enemy &Enemy::operator+=(int Heal)
{
    Entity::operator+=(Heal);
    return *this;
}
Enemy &Enemy::operator-=(int Damage)
{
    Entity::operator-=(Damage);
    return *this;
}

void Enemy::updateLogic(Player &player) {}

bool Enemy::checkCollisions(Player &player)
{
    if (player.get_Hitbox().getGlobalBounds().findIntersection(get_Hitbox().getGlobalBounds()))
        return true;
    else
        return false;
}

float Enemy::distance(Player &player)
{
    return sqrt(pow(player.get_xPos() - get_xPos(), 2) + pow(player.get_yPos() - get_yPos(), 2));
}

bool Enemy::playerLeft(Player &player)
{
    return (player.get_xPos() - get_xPos() < 0);
}

bool Enemy::playerRight(Player &player)
{
    return (player.get_xPos() - get_xPos() > 0);
}

void Enemy::playerTakeDmg(Player &player)
{
    if (checkCollisions(player) && !player.get_isDead())
    {
        if (!player.get_isHurt())
        {
            player.set_isHurt(true);
            player.set_currentFrame(0);
            player -= getAtk();
            player.checkHp();
        }
    }
}

void Enemy::spawn() {}