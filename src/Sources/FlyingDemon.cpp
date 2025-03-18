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
        Fireball = sf::IntRect({0,0},{48,32});

        sprite.setTextureRect(idleFrames[0]);
        sprite.setScale(sf::Vector2f(1.8f,1.8f));
        sprite.setOrigin({40.5,35.5});

        hitbox.setSize({110.f,80.f});
        hitbox.setFillColor(sf::Color::Transparent);
        hitbox.setOutlineColor(sf::Color::Red);
        hitbox.setOutlineThickness(1.f);
        hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2});


        fireballSprite.setTextureRect(Fireball);
        fireballSprite.setTexture(fireballTexture);
        fireballSprite.setScale({2.f,2.f});
        fireballSprite.setOrigin({48/2,32/2});

        fireballHitbox.setRadius(20.0f);
        fireballHitbox.setFillColor(sf::Color::Transparent);
        fireballHitbox.setOutlineColor(sf::Color::Red);
        fireballHitbox.setOutlineThickness(1.f);
        
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
    void FlyingDemon::set_Fireball(bool FireballLaunched)
    {
        this->FireballLaunched = FireballLaunched;
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
    void FlyingDemon::set_FireballDir(bool FireballDir)
    {
        this->FireballDir = FireballDir;
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
    bool FlyingDemon::get_Fireball()
    {
        return FireballLaunched;
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
    int FlyingDemon::get_FireballSpeed()
    {
        return FireballSpeed;
    }
    bool FlyingDemon::get_FireballDir()
    {
        return FireballDir;
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
        Enemy::operator-=(Damage);
        return *this;
    }


    void FlyingDemon::updateAnimation()
    {
        if (AnimationClock.getElapsedTime().asSeconds() > 0.15f)
        {
            CurrentFrame++;

            if (isDead)
            {
                sprite.setTexture(deathTexture);
                sprite.setTextureRect(deathFrames[CurrentFrame]);
            }
            else if (isFlying)
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


    void FlyingDemon::FlyingDemonLogic(Player &player)
    {
        playerTakeDmg(player);

        if (playerLeft(player))
            {
                get_Sprite().setScale(sf::Vector2f(1.8f,1.8f));
            }
            else if (playerRight(player))
            {
                get_Sprite().setScale(sf::Vector2f(-1.8f,1.8f));
            }


            if (checkCollisions(player))
            {
                if (getHp() > 0 && player.get_isAttacking1())
                {
                    set_isHurt(true);

                    if (player.get_currentFrame() == 4 && EscapeClock.getElapsedTime().asSeconds() > 0.4f)
                    {    
                        set_CurrentFrame(0);

                        *this-=player.getAtk();
                        checkHp();

                        if (!get_isDead())
                            escape();

                        EscapeClock.restart();
                    }
                }
                
                if (getHp() > 0 && player.get_isAttacking2())
                {
                    set_isHurt(true);

                    if (player.get_currentFrame() == 1 && EscapeClock.getElapsedTime().asSeconds() > 0.1f)
                    {    
                        set_CurrentFrame(0);

                        *this-=player.getAtk();
                        checkHp();

                        if (!get_isDead())
                            escape();
                        
                        EscapeClock.restart();
                    }
                }

                if (getHp() > 0 && player.get_isAttacking3())
                {
                    set_isHurt(true);

                    if (player.get_currentFrame() == 3 && EscapeClock.getElapsedTime().asSeconds() > 0.3f)
                    {
                        set_CurrentFrame(0);

                        *this-=player.getAtk();

                        if (getHp() != 0)
                        {
                            if (playerLeft(player))
                            {
                                move( 60.f, 0.f);
                            }
                            if (playerRight(player))
                            {
                                move( -60.f, 0.f);
                            }
                        }

                        checkHp();

                        EscapeClock.restart();
                    }
                }
            }
            else if (get_isHurt() && get_CurrentFrame() > 3)
                set_isHurt(false);


            if ( get_isFlying() && distance(player) < 400 )
            {   
                if (playerLeft(player))
                {
                    move(getSpeed(),-getSpeed());
                }
                if (playerRight(player))
                {
                    move(-getSpeed(),-getSpeed());
                }
            }
            else
            {
                set_isFlying(false);
            }

            if (get_yPos() < groundLevel && comeDownClock.getElapsedTime().asSeconds() > 3.0f)
            {
                comeDown();
                comeDownClock.restart();
            }
            if ( !get_isFlying() && get_comeDown() && get_yPos() < groundLevel)
            {
                move(0, 2*getSpeed());
            }
            else
            {
                set_comeDown(false);
            }


            if ((get_isFlying() || get_isIdle()) && AtkClock.getElapsedTime().asSeconds() > 2.0f && !get_isHurt() && !player.get_isDead()) 
            {
                ifAttack();
                set_CurrentFrame(0);
                AtkClock.restart();
            }
            if (get_isAttacking() && get_CurrentFrame() == 3)
            {
                set_Fireball(true);
                recalculateFdir = true;
                playerPosition = player.get_Hitbox().getPosition();

                if (playerLeft(player))
                {
                    set_FireballDir(true);
                    
                    fireballHitbox.setOrigin({fireballHitbox.getRadius() * 2.f, fireballHitbox.getRadius()});
                    get_FireballSprite().setPosition({get_xPos() - 55, get_yPos() + 10});
                    get_fireballHitbox().setPosition({get_xPos() - 50, get_yPos() + 10});
                }
                else if (playerRight(player))
                {
                    set_FireballDir(false);
                    fireballHitbox.setOrigin({0.f, fireballHitbox.getRadius()});
                    get_FireballSprite().setPosition({get_xPos() + 55, get_yPos() + 10});
                    get_fireballHitbox().setPosition({get_xPos() + 50, get_yPos() + 10});
                }
            }
            if ((get_isAttacking() && get_CurrentFrame() >= 7 ) || get_isHurt() || get_isDead())
            {
                set_isAttacking(false);
            }

            if (get_Fireball())
            {
                if (recalculateFdir)
                {
                    demonPosition = get_FireballSprite().getPosition();
                    direction = playerPosition - demonPosition;
                    Fball_angle = atan2(direction.y, direction.x)*180.f / 3.13159f;

                    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                    if (length != 0) 
                    {
                        direction /= length;
                    }
                    recalculateFdir = false;
                }

                if (get_FireballDir())
                {
                    get_FireballSprite().setScale(sf::Vector2f(2.f,2.f));
                    moveFireball(direction.x * get_FireballSpeed(), direction.y * get_FireballSpeed());
                    get_FireballSprite().setRotation(sf::degrees(Fball_angle+180));
                    get_fireballHitbox().setRotation(sf::degrees(Fball_angle+180));
                }
                else if (!get_FireballDir())
                {
                    get_FireballSprite().setScale(sf::Vector2f(-2.f,2.f));
                    moveFireball(direction.x * get_FireballSpeed(), direction.y * get_FireballSpeed());
                    get_FireballSprite().setRotation(sf::degrees(Fball_angle));
                    get_fireballHitbox().setRotation(sf::degrees(Fball_angle));
                }
            }


            if ((checkFireballCollision(player) && (get_isDead() || player.get_isHurt() )) ||
                (checkFireballCollision(player) && player.get_isDefending() && 
                    ( (player.get_Sprite().getScale().x > 0 && get_FireballSprite().getScale().x > 0) ||
                    (player.get_Sprite().getScale().x < 0 && get_FireballSprite().getScale().x < 0) ) ) )
            {
                set_Fireball(false);
                set_fireball_xPos( get_xPos() );
                set_fireball_yPos( get_yPos() );
                get_FireballSprite().setPosition({get_xPos(), get_yPos()});
                get_fireballHitbox().setPosition({get_xPos(), get_yPos()});
            }

        if (player.get_isDead())
        {
            set_isHurt(false);
        }

        if (get_isDead() && get_CurrentFrame() == 6)
        {
            spawn(player);
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
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(1, 6);

        int r = dist(gen);

        if ( r == 3)
        {
            isHurt = false;
            isFlying = true;
        }
    }

    void FlyingDemon::comeDown()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(1, 3);

        int r = dist(gen);

        if ( r == 2)
        {
            comedown = true;
        }
    }

    void FlyingDemon::ifAttack()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(1, 4);

        int r = dist(gen);

        if ( r == 2 && !isAttacking)
        {
            isAttacking = true;
            isFlying = false;
        }
    }

    void FlyingDemon::move(float x, float y)
    {
        if (0 <= xPos + x && xPos + x <= 1440 && yPos <= 800)
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


    bool FlyingDemon::checkCollisions(Player &player)
    {
        if (player.get_Hitbox().getGlobalBounds().findIntersection(get_hitbox().getGlobalBounds()))
            return true;
        else return false;
    }


    bool FlyingDemon::checkFireballCollision(Player &player)
    {
        if (get_fireballHitbox().getGlobalBounds().findIntersection(player.get_Hitbox().getGlobalBounds()))
            return true; 
        else return false;
    }


    float FlyingDemon::distance(Player &player)
    {
        return sqrt (pow ( player.get_xPos() - get_xPos(), 2) + pow ( player.get_yPos() - get_yPos(), 2));
    }


    bool FlyingDemon::playerLeft(Player &player)
    {
        return (player.get_xPos() - get_xPos() < 0);
    }


    bool FlyingDemon::playerRight(Player &player)
    {
        return (player.get_xPos() - get_xPos() > 0);
    }


    void FlyingDemon::playerTakeDmg(Player &player)
    {
        if (checkFireballCollision(player) && get_Fireball() )
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


    void FlyingDemon::spawn(Player &player)
    {
        int x;
        int y;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist1(100, 1360);
        
        do
        {
            x = dist1(gen);
        }while( abs(x - player.get_xPos()) < 250 );    
        xPos = x;

        uniform_int_distribution<int> dist2(-400, 0);
        y = dist2(gen);
        yPos = y;

        sprite.setPosition({xPos,yPos});
        hitbox.setPosition({xPos,yPos});

        setHp(10);
        isDead = false;
        comedown = true;

        set_fireball_xPos( get_xPos() );
        set_fireball_yPos( get_yPos() );
        get_FireballSprite().setPosition({get_xPos(), get_yPos()});
        get_fireballHitbox().setPosition({get_xPos(), get_yPos()});
    }