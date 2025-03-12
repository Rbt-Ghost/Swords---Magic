#include "..\src\Headers\FlyingDemon.hpp"

    FlyingDemon::FlyingDemon(string Name, int Hp, int Atk, float Speed):
    Enemy(Name,Hp,Atk,Speed),
    sprite(idleTexture),
    fireballSprite(fireballTexture)
    {
        if (!idleTexture.loadFromFile("../assets/Flying Demon 2D Pixel Art/Sprites/with_outline/IDLE.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD IDLE SPRITE" << std::endl;
        }
        if (!flyingTexture.loadFromFile("../assets/Flying Demon 2D Pixel Art/Sprites/with_outline/FLYING.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD FLYING SPRITE" << std::endl;
        }
        if (!attackTexture.loadFromFile("../assets/Flying Demon 2D Pixel Art/Sprites/with_outline/ATTACK.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD ATTACK SPRITE" << std::endl;
        }
        if (!hurtTexture.loadFromFile("../assets/Flying Demon 2D Pixel Art/Sprites/with_outline/HURT.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD HURT SPRITE" << std::endl;
        }
        if (!deathTexture.loadFromFile("../assets/Flying Demon 2D Pixel Art/Sprites/with_outline/DEATH.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD DEATH SPRITE" << std::endl;
        }
        if (!fireballTexture.loadFromFile("../assets/Flying Demon 2D Pixel Art/Sprites/projectile.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD PROJECTILE SPRITE" << std::endl;
        }

        sprite.setTexture(idleTexture);

        for(int i=0; i<4; i++)
        {
            idleFrames[i] = sf::IntRect({81*i, 0}, {81, 71});
        }
        for(int i=0; i<4; i++)
        {
            flyingFrames[i] = sf::IntRect({81*i, 0}, {81, 71});
        }
        for(int i=0; i<8; i++)
        {
            attackFrames[i] = sf::IntRect({81*i, 0}, {81, 71});
        }
        for(int i=0; i<4; i++)
        {
            hurtFrames[i] = sf::IntRect({81*i, 0}, {81, 71});
        }
        for(int i=0; i<7; i++)
        {
            deathFrames[i] = sf::IntRect({81*i, 0}, {81, 71});
        }

        sprite.setTextureRect(idleFrames[0]);
        sprite.setScale(sf::Vector2f(1.8f,1.8f));
        sprite.setOrigin({40.5,35.5});
        sprite.setPosition({xPos=1000, yPos=700});

        hitbox.setSize({110.f,80.f});
        hitbox.setFillColor(sf::Color::Transparent);
        hitbox.setOutlineColor(sf::Color::Red);
        hitbox.setOutlineThickness(1.f);
        hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2});
        hitbox.setPosition({xPos,yPos});

        srand(time(NULL));
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
    void FlyingDemon::set_CurrentFrame(int CurrentFrame)
    {
        this->CurrentFrame = CurrentFrame;
    }


    sf::Sprite& FlyingDemon::get_Sprite()
    {
        return sprite;
    }
    sf::Sprite& FlyingDemon::get_FireballSprite()
    {
        return fireballSprite;
    }
    sf::RectangleShape& FlyingDemon::get_hitbox()
    {
        return hitbox;
    }
    sf::CircleShape& FlyingDemon::get_fireballHitbox()
    {
        return fireballHitbox;
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
    float FlyingDemon::get_xPos()
    {
        return xPos;
    }
    float FlyingDemon::get_yPos()
    {
        return yPos;
    }
    float FlyingDemon::get_CurrentFrame()
    {
        return CurrentFrame;
    }


    FlyingDemon& FlyingDemon::operator+=(int Heal)
    {
        Enemy::operator+=(Heal);
        return *this;
    }
    FlyingDemon& FlyingDemon::operator-=(int Damage)
    {
        Damage = max(0, Damage);
        Enemy::operator-=(Damage);
        return *this;
    }


    void FlyingDemon::updateAnimation()
    {
        if (AnimationClock.getElapsedTime().asSeconds() > 0.175f)
        {
            CurrentFrame++;

            if (isFlying)
            {
                if (CurrentFrame >= 4)
                    CurrentFrame = 0;
                sprite.setTexture(flyingTexture);
                sprite.setTextureRect(flyingFrames[CurrentFrame]);
            }
            else if (isAttacking)
            {
                if (CurrentFrame >= 8)
                    CurrentFrame = 0;
                sprite.setTexture(attackTexture);
                sprite.setTextureRect(attackFrames[CurrentFrame]);
            }
            else if (isHurt)
            {
                if (CurrentFrame >= 4)
                    CurrentFrame = 0;
                sprite.setTexture(hurtTexture);
                sprite.setTextureRect(hurtFrames[CurrentFrame]);
            }
            else if (isDead)
            {
                sprite.setTexture(deathTexture);
                sprite.setTextureRect(deathFrames[CurrentFrame]);
                if (CurrentFrame == 6)
                {
                    sprite.setPosition({2000,700});
                    hitbox.setPosition({2000,700});
                }
            }
            else
            {
                if (CurrentFrame >= 4)
                    CurrentFrame = 0;
                sprite.setTexture(idleTexture);
                sprite.setTextureRect(idleFrames[CurrentFrame]);
            }
            AnimationClock.restart();
        }
    }

    void FlyingDemon::checkHp()
    {
        if (getHp() == 0)
        {
            isHurt = false;
            isDead = true;
            CurrentFrame = 0;
        }
    }

    void FlyingDemon::escape()
    {
        int r = rand()%7 + 1;
        cout<<endl<<r;

        if ( r == 4)
        {
            isHurt = false;
            isFlying = true;
        }
    }

    void FlyingDemon::ifAttack()
    {
        int r = rand()%3 + 1;
        cout<<endl<<r;

        if ( r == 2)
        {
            isAttacking = true;
            isFlying = false;
        }
    }

    void FlyingDemon::move(float x, float y)
    {
        sprite.move({x,y});
        hitbox.move({x,y});
        xPos+=x;
        yPos+=y;
    }