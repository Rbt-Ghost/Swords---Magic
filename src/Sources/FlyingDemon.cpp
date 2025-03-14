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
        Projectile = sf::IntRect({0,0},{48,32});

        sprite.setTextureRect(idleFrames[0]);
        sprite.setScale(sf::Vector2f(1.8f,1.8f));
        sprite.setOrigin({40.5,35.5});
        sprite.setPosition({xPos, yPos});

        hitbox.setSize({110.f,80.f});
        hitbox.setFillColor(sf::Color::Transparent);
        hitbox.setOutlineColor(sf::Color::Red);
        hitbox.setOutlineThickness(1.f);
        hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2});
        hitbox.setPosition({xPos, yPos});


        fireballSprite.setTextureRect(Projectile);
        fireballSprite.setTexture(fireballTexture);
        fireballSprite.setScale({2.f,2.f});
        fireballSprite.setOrigin({48/2,32/2});

        fireballHitbox.setRadius(20.0f);
        fireballHitbox.setFillColor(sf::Color::Transparent);
        fireballHitbox.setOutlineColor(sf::Color::Red);
        fireballHitbox.setOutlineThickness(1.f);
        fireballHitbox.setOrigin(fireballHitbox.getGeometricCenter());

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
    void FlyingDemon::set_Projectile(bool ProjectileLaunched)
    {
        this->ProjectileLaunched = ProjectileLaunched;
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
    void FlyingDemon::set_fireball_xPos(float fireball_xPos)
    {
        this->fireball_xPos = fireball_xPos;
    }
    void FlyingDemon::set_fireball_yPos(float fireball_yPos)
    {
        this->fireball_yPos = fireball_yPos;
    }
    void FlyingDemon::set_ProjectileDir(bool ProjectileDir)
    {
        this->ProjectileDir = ProjectileDir;
    }
    void FlyingDemon::set_comeDown(bool comedown)
    {
        this->comedown = comedown;
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
    bool FlyingDemon::get_Projectile()
    {
        return ProjectileLaunched;
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
    float FlyingDemon::get_fireball_xPos()
    {
        return fireball_xPos;
    }
    float FlyingDemon::get_fireball_yPos()
    {
        return fireball_yPos;
    }
    float FlyingDemon::get_CurrentFrame()
    {
        return CurrentFrame;
    }
    int FlyingDemon::get_ProjectileSpeed()
    {
        return ProjectileSpeed;
    }
    bool FlyingDemon::get_ProjectileDir()
    {
        return ProjectileDir;
    }
    bool FlyingDemon::get_comeDown()
    {
        return comedown;
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
                    //move(1000,700);                   gresit
                    //sprite.setPosition({100,700});    gresit
                    //hitbox.setPosition({100,700});    gresit
                    sprite.setPosition({xPos=100,yPos=700}); // add random values
                    hitbox.setPosition({xPos=100,yPos=700});
                    setHp(10);
                    isDead = false;
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
        int r = rand()%6 + 1;

        if ( r == 3)
        {
            isHurt = false;
            isFlying = true;
        }
    }

    void FlyingDemon::comeDown()
    {
        int r = rand()%2 + 1;

        if ( r == 2)
        {
            comedown = true;
        }
    }

    void FlyingDemon::ifAttack()
    {
        int r = rand()%3 + 1;

        if ( r == 2)
        {
            isAttacking = true;
            isFlying = false;
        }
    }

    void FlyingDemon::move(float x, float y)
    {
        if (0 <= xPos + x && xPos + x <= 1440 && 0 <= yPos && yPos <= 800)
        {
            sprite.move({x,y});
            hitbox.move({x,y});
            xPos += x;
            yPos += y;
        }
    }

    void FlyingDemon::moveFireball(float x, float y)
    {
        fireballSprite.move({x,y});
        fireballHitbox.move({x,y});
        fireball_xPos += x;
        fireball_yPos += y;
    }

    void FlyingDemon::rotate_projectile()
    {
        if (ProjectileLaunched)
        {
            if (rotateUp)
            {
                fireballSprite.rotate(sf::degrees(10));
                rotateUp = false;
            }
            else
            {
                rotateUp = true;
            }
            if (rotateDown)
            {
                fireballSprite.rotate(sf::degrees(-10));
                rotateDown = false;
            }
            else
            {
                rotateDown = true;
            }
        }
    }