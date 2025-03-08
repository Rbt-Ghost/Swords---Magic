#include "..\src\Headers\FlyingDemon.hpp"

    FlyingDemon::FlyingDemon(string Name, int Hp, int Atk, float Speed):
    Enemy(Name,Hp,Atk,Speed),
    sprite(idleTexture)
    {
        if (!idleTexture.loadFromFile("../assets/Flying Demon 2D Pixel Art/Sprites/with_outline/IDLE.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD IDLE SPRITE" << std::endl;
        }

        sprite.setTexture(idleTexture);

        for(int i=0; i<4; i++)
        {
            idleFrames[i] = sf::IntRect({81*i, 0}, {81, 71});
        }

        sprite.setTextureRect(idleFrames[0]);
        sprite.setScale(sf::Vector2f(1.8f,1.8f));
        sprite.setOrigin({48,42});
        sprite.setPosition({1000, 800/4});
    }

    FlyingDemon::~FlyingDemon()
    {}


    void FlyingDemon::set_isIdle(bool isIdle)
    {
        this->isIdle = isIdle;
    }
    void FlyingDemon::set_isFlying(bool isFlying)
    {
        this->isFlying = isFlying; 
    }
    void FlyingDemon::set_isAttacking(bool isAttacking)
    {
        this->isAttacking = isAttacking;
    }
    void FlyingDemon::set_isHurt(bool isHurt)
    {
        this->isHurt = isHurt;
    }
    void FlyingDemon::set_isDead(bool isDead)
    {
        this->isDead = isDead;
    }


    sf::Sprite& FlyingDemon::getSprite()
    {
        return sprite;
    }
    bool FlyingDemon::get_isIdle()
    {
        return isIdle;
    }
    bool FlyingDemon::get_isFlying()
    {
        return isFlying;
    }
    bool FlyingDemon::get_isAttacking()
    {
        return isAttacking;
    }
    bool FlyingDemon::get_isHurt()
    {
        return isHurt;
    }
    bool FlyingDemon::get_isDead()
    {
        return isDead;
    }

    void FlyingDemon::updateAnimation()
    {
        if (AnimationClock.getElapsedTime().asSeconds() > 0.15f)
        {
            CurrentFrame++;

            if (isIdle)
            {
                if (CurrentFrame >=4)
                    CurrentFrame = 0;
                sprite.setTexture(idleTexture);
                sprite.setTextureRect(idleFrames[CurrentFrame]);
            }
            AnimationClock.restart();
        }
    }