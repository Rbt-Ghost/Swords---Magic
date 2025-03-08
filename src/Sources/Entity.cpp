#include "..\src\Headers\Entity.hpp"

Entity::Entity(string Name, int Hp, int Atk, float Speed)
{
    setName(Name);
    setHp(Hp);
    setAtk(Atk);
    setSpeed(Speed);
}
Entity::~Entity()
{}

void Entity::setName(string Name)
{
    this->Name=Name;
}
void Entity::setHp(int Hp)
{
    this->Hp=Hp;
}
void Entity::setAtk(int Atk)
{
    this->Atk=Atk;
}
void Entity::setSpeed(float Speed)
{
    this->Speed=Speed;
}

string Entity::getName()
{
    return Name;
}
int Entity::getHp()
{
    return Hp;
}
int Entity::getAtk()
{
    return Atk;
}
float Entity::getSpeed()
{
    return Speed;
}

Entity &Entity::operator+=(int Heal)
{
    Hp+=Heal;
    return *this;
}
Entity &Entity::operator-=(int Damage)
{
    Hp-=Damage;
    return *this;
}

void Entity::updateAnimation() {}

void Entity::move(float x, float y) {}

void Entity::jump() {}

void Entity::updatePhysics() {}

void Entity::attack() {}

void Entity::defend() {}

void Entity::hurt() {}

void Entity::die() {}