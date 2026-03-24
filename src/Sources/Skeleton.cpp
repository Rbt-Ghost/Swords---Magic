#include "..\src\Headers\Skeleton.hpp"

Skeleton::Skeleton(string Name, int Hp, int Atk, float Speed) : Enemy(Name, Hp, Atk, Speed)
{
    if (!idleTexture.loadFromFile("../assets/2D_Models/Skeleton Sprite Pack/Skeleton Idle.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD SKELETON IDLE SPRITE" << std::endl;
    }
    if (!attackTexture.loadFromFile("../assets/2D_Models/Skeleton Sprite Pack/Skeleton Attack.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD SKELETON ATTACK SPRITE" << std::endl;
    }
    if (!hurtTexture.loadFromFile("../assets/2D_Models/Skeleton Sprite Pack/Skeleton Hit.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD SKELETON HIT SPRITE" << std::endl;
    }
    if (!deathTexture.loadFromFile("../assets/2D_Models/Skeleton Sprite Pack/Skeleton Dead.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD SKELETON DEAD SPRITE" << std::endl;
    }
    if (!walkTexture.loadFromFile("../assets/2D_Models/Skeleton Sprite Pack/Skeleton Walk.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD SKELETON WALK SPRITE" << std::endl;
    }
    if (!reactingTexture.loadFromFile("../assets/2D_Models/Skeleton Sprite Pack/Skeleton React.png"))
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

    set_xPos(100);
    set_yPos(groundLevel);

    get_Sprite().setTextureRect(idleFrames[0]);
    get_Sprite().setScale(sf::Vector2f(3.f, 3.f));
    get_Sprite().setPosition({get_xPos(), get_yPos()});

    get_Hitbox().setSize({50, 95});
    get_Hitbox().setFillColor(sf::Color::Transparent);
    get_Hitbox().setOutlineColor(sf::Color::Red);
    get_Hitbox().setOutlineThickness(1.f);
    get_Hitbox().setPosition({get_xPos(), get_yPos()});

    get_Sound().setVolume(45.5f);
}

Skeleton::~Skeleton()
{
}

void Skeleton::updateAnimation()
{
    if (AnimationClock.getElapsedTime().asSeconds() > 0.1f)
    {
        set_currentFrame(get_currentFrame() + 1);

        if (get_isDead())
        {
            if (get_currentFrame() >= 15)
                set_currentFrame(0);
            get_Sprite().setTexture(deathTexture);
            get_Sprite().setTextureRect(deathFrames[get_currentFrame()]);

            get_Sprite().setOrigin({12, 16});
            get_Hitbox().setOrigin({get_Hitbox().getSize().x / 2, get_Hitbox().getSize().y / 2 - 10});
        }
        else if (isAttacking)
        {
            if (get_currentFrame() >= 18)
                set_currentFrame(0);
            get_Sprite().setTexture(attackTexture);
            get_Sprite().setTextureRect(attackFrames[get_currentFrame()]);

            get_Sprite().setOrigin({12, 20});
            get_Hitbox().setOrigin({get_Hitbox().getSize().x / 2, get_Hitbox().getSize().y / 2 - 10});
        }
        else if (isHurt)
        {
            if (get_currentFrame() > 8)
                set_currentFrame(0);
            get_Sprite().setTexture(hurtTexture);
            get_Sprite().setTextureRect(hurtFrames[get_currentFrame()]);

            get_Sprite().setOrigin({18, 16});
            get_Hitbox().setOrigin({get_Hitbox().getSize().x / 2, get_Hitbox().getSize().y / 2 - 10});
        }
        else if (isWalking)
        {
            if (get_currentFrame() >= 13)
                set_currentFrame(0);
            get_Sprite().setTexture(walkTexture);
            get_Sprite().setTextureRect(walkFrames[get_currentFrame()]);

            get_Sprite().setOrigin({12, 16.5});
            get_Hitbox().setOrigin({get_Hitbox().getSize().x / 2, get_Hitbox().getSize().y / 2 - 10});
        }
        else if (isReacting)
        {
            if (get_currentFrame() >= 4)
                set_currentFrame(0);
            get_Sprite().setTexture(reactingTexture);
            get_Sprite().setTextureRect(reactingFrames[get_currentFrame()]);

            get_Sprite().setOrigin({11, 16});
            get_Hitbox().setOrigin({get_Hitbox().getSize().x / 2, get_Hitbox().getSize().y / 2 - 10});
        }
        else
        {
            if (get_currentFrame() >= 11)
                set_currentFrame(0);
            get_Sprite().setTexture(idleTexture);
            get_Sprite().setTextureRect(idleFrames[get_currentFrame()]);

            get_Sprite().setOrigin({12, 16});
            get_Hitbox().setOrigin({get_Hitbox().getSize().x / 2, get_Hitbox().getSize().y / 2 - 10});
        }
        AnimationClock.restart();
    }
}

void Skeleton::updateLogic(Player &player)
{

    if (!get_isDead() && checkCollisions(player))
    {
        isWalking = false;

        if (AtkClock.getElapsedTime().asSeconds() > 4.25f)
        {
            if (playerRight(player))
            {
                get_Sprite().setScale(sf::Vector2f(3.f, 3.f));
            }
            else if (playerLeft(player))
            {
                get_Sprite().setScale(sf::Vector2f(-3.f, 3.f));
            }
            set_currentFrame(0);
            isAttacking = true;

            AtkClock.restart();
        }

        if (isAttacking)
        {
            if (get_currentFrame() == 7)
            {
                bool isBlock = player.get_isDefending() &&
                               ((playerLeft(player) && player.get_Sprite().getScale().x > 0) ||
                                (playerRight(player) && player.get_Sprite().getScale().x < 0));

                if (isBlock)
                {
                    player.onShieldBlock();
                }
                else if (!player.get_isDefending())
                {
                    playerTakeDmg(player);
                }
            }
        }
        if (getHp() > 0 && player.get_isAttacking1() && (playerLeft(player) && player.get_Sprite().getScale().x > 0 || playerRight(player) && player.get_Sprite().getScale().x < 0))
        {
            if (!isAttacking)
            {
                isHurt = true;
            }

            if (player.get_currentFrame() == 4 && EscapeClock.getElapsedTime().asSeconds() > 0.4f)
            {
                if (!isAttacking)
                {
                    set_currentFrame(0);
                }

                *this -= player.getAtk();
                checkHp();

                EscapeClock.restart();
            }
        }

        if (getHp() > 0 && player.get_isAttacking2() && (playerLeft(player) && player.get_Sprite().getScale().x > 0 || playerRight(player) && player.get_Sprite().getScale().x < 0))
        {
            if (!isAttacking)
            {
                isHurt = true;
            }

            if (player.get_currentFrame() == 1 && EscapeClock.getElapsedTime().asSeconds() > 0.1f)
            {
                if (!isAttacking)
                {
                    set_currentFrame(0);
                }

                *this -= player.getAtk();
                checkHp();

                EscapeClock.restart();
            }
        }

        if (getHp() > 0 && player.get_isAttacking3() && (playerLeft(player) && player.get_Sprite().getScale().x > 0 || playerRight(player) && player.get_Sprite().getScale().x < 0))
        {
            if (!isAttacking)
            {
                isHurt = true;
            }

            if (player.get_currentFrame() == 3 && EscapeClock.getElapsedTime().asSeconds() > 0.3f)
            {
                if (!isAttacking)
                {
                    set_currentFrame(0);
                }

                *this -= player.getAtk();
                checkHp();

                EscapeClock.restart();
            }
        }
    }
    if (isHurt && get_currentFrame() >= 7)
    {
        isHurt = false;
    }

    if (isAttacking && get_currentFrame() >= 17)
    {
        isAttacking = false;
    }

    if (!isHurt && !isAttacking && !get_isDead())
    {
        int x;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist1(3, 10);
        x = dist1(gen);

        if (Reacting() && !isReacting && !isAttacking && ReactClock.getElapsedTime().asSeconds() > x)
        {
            isReacting = true;
            set_currentFrame(0);
            ReactClock.restart();
        }

        if (isAttacking)
            isReacting = false;
        else if (isReacting && get_currentFrame() == 3)
        {
            k++;
            set_currentFrame(0);
            if (k == 4)
            {
                isReacting = false;
                k = 0;
            }
        }
    }

    if (abs(get_xPos() - player.get_xPos()) > 40 && !isAttacking && !get_isDead() && !isReacting)
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

    if (get_isDead() && get_currentFrame() == 14)
    {
        spawn();
    }
}

void Skeleton::move(float x, float y)
{
    get_Sprite().move({x, y});
    get_Hitbox().move({x, y});
    set_xPos(get_xPos() + x);
    set_yPos(get_yPos() + y);
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
    set_xPos(x);

    get_Sprite().setPosition({get_xPos(), get_yPos()});
    get_Hitbox().setPosition({get_xPos(), get_yPos()});

    setHp(get_MaxHP());
    set_isDead(false);
}

void Skeleton::SkeletonSounds()
{
    if (get_isDead() && !deathSoundPlayed)
    {
        PlaySound("..//assets/Sounds/Skeleton//Death.mp3");
        deathSoundPlayed = true;
    }
    else if (!get_isDead())
    {
        deathSoundPlayed = false;
    }

    if (isAttacking && !attackSoundPlayed)
    {
        PlaySound("..//assets/Sounds/Skeleton//Axe hit stone.mp3");
        attackSoundPlayed = true;
    }
    else if (!isAttacking)
    {
        attackSoundPlayed = false;
    }

    if (isWalking && !walkSoundPlayed)
    {
        PlaySound("..//assets/Sounds/Skeleton//Walking.mp3");
        walkSoundPlayed = true;
    }
    else if (!isWalking)
    {
        walkSoundPlayed = false;
    }
}