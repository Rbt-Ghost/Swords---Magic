#include "..\src\Headers\Skeleton.hpp"

    Skeleton::Skeleton(string Nane, int Hp, int Atk, float Speed):
    Enemy(Name,Hp,Atk,Speed),
    sprite(idleTexture)
    {
        if (!idleTexture.loadFromFile("../assets/Skeleton Sprite Pack/Skeleton/Sprite Sheets/Skeleton Idle.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD SKELETON IDLE SPRITE" << std::endl;
        }
        if (!attackTexture.loadFromFile("../assets/Skeleton Sprite Pack/Skeleton/Sprite Sheets/Skeleton Attack.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD SKELETON ATTACK SPRITE" << std::endl;
        }
        if (!hurtTexture.loadFromFile("../assets/Skeleton Sprite Pack/Skeleton/Sprite Sheets/Skeleton Hit.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD SKELETON HIT SPRITE" << std::endl;
        }
        if (!deathTexture.loadFromFile("../assets/Skeleton Sprite Pack/Skeleton/Sprite Sheets/Skeleton Dead.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD SKELETON DEAD SPRITE" << std::endl;
        }
        if (!walkTexture.loadFromFile("../assets/Skeleton Sprite Pack/Skeleton/Sprite Sheets/Skeleton Walk.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD SKELETON WALK SPRITE" << std::endl;
        }
        if (!reactingTexture.loadFromFile("../assets/Skeleton Sprite Pack/Skeleton/Sprite Sheets/Skeleton React.png"))
        {
            std::cerr << "ERROR :: COULD NOT LOAD SKELETON REACT SPRITE" << std::endl;
        }

        for(int i=0; i<11; i++)
        {
            idleFrames[i] = sf::IntRect({24*i, 0}, {24, 32});
        }
        for(int i=0; i<18; i++)
        {
            attackFrames[i] = sf::IntRect({43 * i, 0}, {43, 37});
        }
        for(int i=0; i<8; i++)
        {
            hurtFrames[i] = sf::IntRect({30*i, 0}, {30, 32});
        }
        for(int i=0; i<15; i++)
        {
            deathFrames[i] = sf::IntRect({33*i, 0}, {33, 32});
        }
        for(int i=0; i<13; i++)
        {
            walkFrames[i] = sf::IntRect({22*i, 0}, {22, 33});
        }
        for(int i=0; i<4; i++)
        {
            reactingFrames[i] = sf::IntRect({22*i, 0}, {22, 32});
        }

        sprite.setTextureRect(idleFrames[0]);
        sprite.setScale(sf::Vector2f(3.f,3.f));
        sprite.setPosition({xPos,yPos});

        hitbox.setSize({50,85});
        hitbox.setFillColor(sf::Color::Transparent);
        hitbox.setOutlineColor(sf::Color::Red);
        hitbox.setOutlineThickness(1.f);
        hitbox.setPosition({xPos,yPos});
    }

    Skeleton::~Skeleton()
    {}


    sf::Sprite& Skeleton::get_Sprite()
    {
        return sprite;
    }
    sf::RectangleShape& Skeleton::get_hitbox()
    {
        return hitbox;
    }


    void Skeleton::updateAnimation()
    {
        if (AnimationClock.getElapsedTime().asSeconds() > 0.15f)
        {
            CurrentFrame++;

            if (isDead)
            {
                if (CurrentFrame >= 15)
                    CurrentFrame = 0;
                sprite.setTexture(deathTexture);
                sprite.setTextureRect(deathFrames[CurrentFrame]);

                sprite.setOrigin({12,16});
                hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2-10});
            }
            else if (isAttacking)
            {
                if (CurrentFrame >= 18)
                    CurrentFrame = 0;
                sprite.setTexture(attackTexture);
                sprite.setTextureRect(attackFrames[CurrentFrame]);

                sprite.setOrigin({12,20});
                hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2-10});
            }
            else if (isHurt)
            {
                if (CurrentFrame >= 8)
                    CurrentFrame = 0;
                sprite.setTexture(hurtTexture);
                sprite.setTextureRect(hurtFrames[CurrentFrame]);

                sprite.setOrigin({12,16});
                hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2-10});
            }
            else if (isWalfing)
            {
                if (CurrentFrame >= 13)
                    CurrentFrame = 0;
                sprite.setTexture(walkTexture);
                sprite.setTextureRect(walkFrames[CurrentFrame]);

                sprite.setOrigin({12,16.5});
                hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2-10});
            }
            else if (isReacting)
            {
                if (CurrentFrame >= 4)
                    CurrentFrame = 0;
                sprite.setTexture(reactingTexture);
                sprite.setTextureRect(reactingFrames[CurrentFrame]);

                sprite.setOrigin({12,16});
                hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2-10});
            }
            else
            {
                if (CurrentFrame >= 11)
                    CurrentFrame = 0;
                sprite.setTexture(idleTexture);
                sprite.setTextureRect(idleFrames[CurrentFrame]);

                sprite.setOrigin({12,16});
                hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2-10});
            }
            AnimationClock.restart();
        }
    }

    void Skeleton::SkeletonLogic(Player &layer)
    {

    }

    void Skeleton::checkHp()
    {

    }
    void Skeleton::ifAttack()
    {

    }

    void Skeleton::move(float x, float y)
    {

    }

    bool Skeleton::checkCollisions(Player &player)
    {

    }

    float Skeleton::distance(Player &player)
    {

    }

    bool Skeleton::playerLeft(Player &player)
    {

    }

    bool Skeleton::playerRight(Player &player)
    {

    }
    void Skeleton::playerTakeDmg(Player &player)
    {

    }

    void Skeleton::spawn(Player &player)
    {

    }