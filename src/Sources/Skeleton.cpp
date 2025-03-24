#include "..\src\Headers\Skeleton.hpp"

Skeleton::Skeleton(string Name, int Hp, int Atk, float Speed) : 
Enemy(Name, Hp, Atk, Speed),
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

    for (int i = 0; i < 11; i++)
    {
        idleFrames[i] = sf::IntRect({24 * i, 0}, {24, 32});
    }
    for (int i = 0; i < 18; i++)
    {
        attackFrames[i] = sf::IntRect({43 * i, 0}, {43, 37});
    }
    for (int i = 0; i < 8; i++)
    {
        hurtFrames[i] = sf::IntRect({30 * i, 0}, {30, 32});
    }
    for (int i = 0; i < 15; i++)
    {
        deathFrames[i] = sf::IntRect({33 * i, 0}, {33, 32});
    }
    for (int i = 0; i < 13; i++)
    {
        walkFrames[i] = sf::IntRect({22 * i, 0}, {22, 33});
    }
    for (int i = 0; i < 4; i++)
    {
        reactingFrames[i] = sf::IntRect({22 * i, 0}, {22, 32});
    }

    sprite.setTextureRect(idleFrames[0]);
    sprite.setScale(sf::Vector2f(3.f, 3.f));
    sprite.setPosition({xPos, yPos});

    hitbox.setSize({50, 95});
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1.f);
    hitbox.setPosition({xPos, yPos});
}

Skeleton::~Skeleton()
{
}

sf::Sprite &Skeleton::get_Sprite()
{
    return sprite;
}
sf::RectangleShape &Skeleton::get_hitbox()
{
    return hitbox;
}

bool Skeleton::get_isDead()
{
    return isDead;
}
int Skeleton::get_CurrentFrame()
{
    return CurrentFrame;
}

void Skeleton::updateAnimation()
{
    if (AnimationClock.getElapsedTime().asSeconds() > 0.1f)
    {
        CurrentFrame++;

        if (isDead)
        {
            if (CurrentFrame >= 15)
                CurrentFrame = 0;
            sprite.setTexture(deathTexture);
            sprite.setTextureRect(deathFrames[CurrentFrame]);

            sprite.setOrigin({12, 16});
            hitbox.setOrigin({hitbox.getSize().x / 2, hitbox.getSize().y / 2 - 10});
        }
        else if (isAttacking)
        {
            if (CurrentFrame >= 18)
                CurrentFrame = 0;
            sprite.setTexture(attackTexture);
            sprite.setTextureRect(attackFrames[CurrentFrame]);

            sprite.setOrigin({12, 20});
            hitbox.setOrigin({hitbox.getSize().x / 2, hitbox.getSize().y / 2 - 10});
        }
        else if (isHurt)
        {
            if (CurrentFrame > 8)
                CurrentFrame = 0;
            sprite.setTexture(hurtTexture);
            sprite.setTextureRect(hurtFrames[CurrentFrame]);

            sprite.setOrigin({18, 16});
            hitbox.setOrigin({hitbox.getSize().x / 2, hitbox.getSize().y / 2 - 10});
        }
        else if (isWalking)
        {
            if (CurrentFrame >= 13)
                CurrentFrame = 0;
            sprite.setTexture(walkTexture);
            sprite.setTextureRect(walkFrames[CurrentFrame]);

            sprite.setOrigin({12, 16.5});
            hitbox.setOrigin({hitbox.getSize().x / 2, hitbox.getSize().y / 2 - 10});
        }
        else if (isReacting)
        {
            if (CurrentFrame >= 4)
                CurrentFrame = 0;
            sprite.setTexture(reactingTexture);
            sprite.setTextureRect(reactingFrames[CurrentFrame]);

            sprite.setOrigin({11, 16});
            hitbox.setOrigin({hitbox.getSize().x / 2, hitbox.getSize().y / 2 - 10});
        }
        else
        {
            if (CurrentFrame >= 11)
                CurrentFrame = 0;
            sprite.setTexture(idleTexture);
            sprite.setTextureRect(idleFrames[CurrentFrame]);

            sprite.setOrigin({12, 16});
            hitbox.setOrigin({hitbox.getSize().x / 2, hitbox.getSize().y / 2 - 10});
        }
        AnimationClock.restart();
    }
}

void Skeleton::SkeletonLogic(Player &player)
{

    if (!isDead && checkCollisions(player))
    {
        isWalking = false;

        if (AtkClock.getElapsedTime().asSeconds() > 3.5)
        {
            CurrentFrame = 0;
            isAttacking = true;

            AtkClock.restart();
        }

        if (isAttacking)
        {
            if (CurrentFrame == 7 && !player.get_isDefending())
            {
                playerTakeDmg(player);
            }
        }
        else
        {
            if (getHp() > 0 && player.get_isAttacking1())
            {
                isHurt = true;

                if (player.get_currentFrame() == 4 && EscapeClock.getElapsedTime().asSeconds() > 0.4f)
                {
                    CurrentFrame = 0;

                    *this -= player.getAtk();
                    checkHp();

                    // if (!get_isDead())
                    //   escape();

                    EscapeClock.restart();
                }
            }

            if (getHp() > 0 && player.get_isAttacking2())
            {
                isHurt = true;

                if (player.get_currentFrame() == 1 && EscapeClock.getElapsedTime().asSeconds() > 0.1f)
                {
                    CurrentFrame = 0;

                    *this -= player.getAtk();
                    checkHp();

                    /// if (!get_isDead())
                    // escape();

                    EscapeClock.restart();
                }
            }

            if (getHp() > 0 && player.get_isAttacking3())
            {
                isHurt = true;

                if (player.get_currentFrame() == 3 && EscapeClock.getElapsedTime().asSeconds() > 0.3f)
                {
                    CurrentFrame = 0;

                    *this -= player.getAtk();

                    checkHp();

                    EscapeClock.restart();
                }
            }
        }
    }
    else if (isHurt && CurrentFrame >= 7)
    {
        isHurt = false;
    }
    

    if (isAttacking && CurrentFrame >= 17)
    {
        isAttacking = false;
    }

    
    if (!isHurt && !isAttacking && !isDead)
    {
        int x;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist1(3, 10);
        x = dist1(gen);

        if (Reacting() && !isReacting && !isAttacking && ReactClock.getElapsedTime().asSeconds() > x)
        {
            isReacting = true;
            CurrentFrame = 0;
            ReactClock.restart();
        }

        if (isAttacking)
            isReacting = false;
        else if (isReacting && CurrentFrame == 3)
        {
            k++;
            CurrentFrame = 0;
            if (k == 4)
            {
                isReacting = false;
                k = 0;
            }
        }
    }

    if (abs(xPos - player.get_xPos()) > 40 && !isAttacking && !isDead && !isReacting)
    {
        isWalking = true;
        if (playerLeft(player))
        {
            get_Sprite().setScale(sf::Vector2f(-3.f, 3.f));
            move(-getSpeed(), 0);
        }
        else if (playerRight(player))
        {
            get_Sprite().setScale(sf::Vector2f(3.f, 3.f));
            move(getSpeed(), 0);
        }
    }
    else
    {
        isWalking = false;
    }

    if (isDead && CurrentFrame == 14)
    {
        spawn();
    }
}

void Skeleton::checkHp()
{
    if (getHp() == 0)
    {
        isHurt = false;
        isDead = true;
        CurrentFrame = 0;
    }
}
// void Skeleton::ifAttack() {}

void Skeleton::move(float x, float y)
{
    {
        sprite.move({x, y});
        hitbox.move({x, y});
        xPos += x;
        yPos += y;
    }
}

bool Skeleton::checkCollisions(Player &player)
{
    if (player.get_Hitbox().getGlobalBounds().findIntersection(get_hitbox().getGlobalBounds()))
        return true;
    else
        return false;
}

float Skeleton::distance(Player &player)
{
    return sqrt(pow(player.get_xPos() - xPos, 2) + pow(player.get_yPos() - yPos, 2));
}

bool Skeleton::playerLeft(Player &player)
{
    return (player.get_xPos() - xPos < 0);
}

bool Skeleton::playerRight(Player &player)
{
    return (player.get_xPos() - xPos > 0);
}

bool Skeleton::Reacting()
{
    int x;

    random_device rd;

    mt19937 gen(rd());
    uniform_int_distribution<int> dist1(1, 5);
    x = dist1(gen);

    if (x == 3)
        return true;
    else
        return false;
}

void Skeleton::playerTakeDmg(Player &player)
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

void Skeleton::spawn()
{
    int x;
    int check;

    random_device rd;

    mt19937 gen(rd());
    uniform_int_distribution<int> dist1(1, 2);
    check = dist1(gen);

    if (check == 1)
    {
        mt19937 gen(rd());
        uniform_int_distribution<int> dist1(-600, -50);
        x = dist1(gen);
    }
    else if (check == 2)
    {
        mt19937 gen(rd());
        uniform_int_distribution<int> dist1(1490, 1800);
        x = dist1(gen);
    }
    xPos = x;

    sprite.setPosition({xPos, yPos});
    hitbox.setPosition({xPos, yPos});

    setHp(10);
    isDead = false;
}