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
    if (Hp > 0) 
        this->Hp=Hp;
    else this->Hp = 0;
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
    setHp(Hp+=Heal);
    return *this;
}
Entity &Entity::operator-=(int Damage)
{
    setHp(Hp-=Damage);
    return *this;
}

Entity &Entity::operator*=(int Heal)
{
    setHp(Hp*=Heal);
    return *this;
}
Entity &Entity::operator/=(int Damage)
{
    setHp(Hp/=Damage);
    return *this;
}
bool operator==(const Entity a, const Entity b)
{
    return (a.Name == b.Name);
}

void Entity::updateAnimation() {}

void Entity::updateLogic() {}

void Entity::move(float x, float y) {}

void Entity::jump() {}

void Entity::updatePhysics() {}