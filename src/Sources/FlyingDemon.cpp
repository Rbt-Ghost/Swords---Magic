#include "..\src\Headers\FlyingDemon.hpp"

FlyingDemon::FlyingDemon(string Name, int Hp, int Atk, float Speed) : Enemy(Name, Hp, Atk, Speed),
                                                                      fireballSprite(fireballTexture)
{
    if (!idleTexture.loadFromFile("../assets/2D_Models/Flying Demon 2D Pixel Art/IDLE.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD IDLE SPRITE" << std::endl;
    }
    if (!flyingTexture.loadFromFile("../assets/2D_Models/Flying Demon 2D Pixel Art/FLYING.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD FLYING SPRITE" << std::endl;
    }
    if (!attackTexture.loadFromFile("../assets/2D_Models/Flying Demon 2D Pixel Art/ATTACK.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD ATTACK SPRITE" << std::endl;
    }
    if (!hurtTexture.loadFromFile("../assets/2D_Models/Flying Demon 2D Pixel Art/HURT.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD HURT SPRITE" << std::endl;
    }
    if (!deathTexture.loadFromFile("../assets/2D_Models/Flying Demon 2D Pixel Art/DEATH.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD DEATH SPRITE" << std::endl;
    }
    if (!fireballTexture.loadFromFile("../assets/2D_Models/Flying Demon 2D Pixel Art/projectile.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD PROJECTILE SPRITE" << std::endl;
    }

    get_Sprite().setTexture(idleTexture);

    for (int i = 0; i < 4; i++)
    {
        idleFrames[i] = sf::IntRect({81 * i, 0}, {81, 71});
    }
    for (int i = 0; i < 4; i++)
    {
        flyingFrames[i] = sf::IntRect({81 * i, 0}, {81, 71});
    }
    for (int i = 0; i < 8; i++)
    {
        attackFrames[i] = sf::IntRect({81 * i, 0}, {81, 71});
    }
    for (int i = 0; i < 4; i++)
    {
        hurtFrames[i] = sf::IntRect({81 * i, 0}, {81, 71});
    }
    for (int i = 0; i < 7; i++)
    {
        deathFrames[i] = sf::IntRect({81 * i, 0}, {81, 71});
    }
    Fireball = sf::IntRect({0, 0}, {48, 32});

    get_Sprite().setTextureRect(idleFrames[0]);
    get_Sprite().setScale(sf::Vector2f(1.8f, 1.8f));
    get_Sprite().setOrigin({40.5, 35.5});

    get_Hitbox().setSize({95.f, 80.f});
    get_Hitbox().setFillColor(sf::Color::Transparent);
    get_Hitbox().setOutlineColor(sf::Color::Red);
    get_Hitbox().setOutlineThickness(1.f);
    get_Hitbox().setOrigin({get_Hitbox().getSize().x / 2, get_Hitbox().getSize().y / 2});

    fireballSprite.setTextureRect(Fireball);
    fireballSprite.setTexture(fireballTexture);
    fireballSprite.setScale({2.f, 2.f});
    fireballSprite.setOrigin({48 / 2, 32 / 2});

    fireballHitbox.setRadius(20.0f);
    fireballHitbox.setFillColor(sf::Color::Transparent);
    fireballHitbox.setOutlineColor(sf::Color::Red);
    fireballHitbox.setOutlineThickness(1.f);

    get_Sound().setVolume(90.f);
}

FlyingDemon::~FlyingDemon()
{
}

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
void FlyingDemon::set_GroundLevel(float groundLevel)
{
    this->groundLevel = groundLevel;
}

sf::Sprite &FlyingDemon::get_FireballSprite()
{
    return fireballSprite;
}
sf::CircleShape &FlyingDemon::get_fireballHitbox()
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
float FlyingDemon::get_fireball_xPos()
{
    return fireball_xPos;
}
float FlyingDemon::get_fireball_yPos()
{
    return fireball_yPos;
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

FlyingDemon &FlyingDemon::operator+=(int Heal)
{
    Enemy::operator+=(Heal);
    return *this;
}
FlyingDemon &FlyingDemon::operator-=(int Damage)
{
    Enemy::operator-=(Damage);
    return *this;
}

void FlyingDemon::updateAnimation()
{
    if (AnimationClock.getElapsedTime().asSeconds() > 0.15f)
    {
        set_currentFrame(get_currentFrame() + 1);

        if (get_isDead())
        {
            get_Sprite().setTexture(deathTexture);
            get_Sprite().setTextureRect(deathFrames[get_currentFrame()]);
        }
        else if (isFlying)
        {
            if (get_currentFrame() >= 4)
                set_currentFrame(0);
            get_Sprite().setTexture(flyingTexture);
            get_Sprite().setTextureRect(flyingFrames[get_currentFrame()]);
        }
        else if (isAttacking)
        {
            if (get_currentFrame() >= 8)
                set_currentFrame(0);
            get_Sprite().setTexture(attackTexture);
            get_Sprite().setTextureRect(attackFrames[get_currentFrame()]);
        }
        else if (isHurt)
        {
            if (get_currentFrame() >= 4)
                set_currentFrame(0);
            get_Sprite().setTexture(hurtTexture);
            get_Sprite().setTextureRect(hurtFrames[get_currentFrame()]);
        }
        else
        {
            if (get_currentFrame() >= 4)
                set_currentFrame(0);
            get_Sprite().setTexture(idleTexture);
            get_Sprite().setTextureRect(idleFrames[get_currentFrame()]);
        }
        AnimationClock.restart();
    }
}

void FlyingDemon::updateLogic(Player &player)
{
    playerTakeDmg(player);

    if (playerLeft(player))
    {
        get_Sprite().setScale(sf::Vector2f(1.8f, 1.8f));
    }
    else if (playerRight(player))
    {
        get_Sprite().setScale(sf::Vector2f(-1.8f, 1.8f));
    }

    if (!get_isDead())
    {
        if (checkCollisions(player))
        {
            if (getHp() > 0 && player.get_isAttacking1() && (playerLeft(player) && player.get_Sprite().getScale().x > 0 || playerRight(player) && player.get_Sprite().getScale().x < 0))
            {
                set_isHurt(true);

                if (player.get_currentFrame() == 4 && EscapeClock.getElapsedTime().asSeconds() > 0.4f)
                {
                    set_currentFrame(0);

                    *this -= player.getAtk();
                    checkHp();

                    if (!get_isDead())
                        escape();

                    EscapeClock.restart();
                }
            }

            if (getHp() > 0 && player.get_isAttacking2() && (playerLeft(player) && player.get_Sprite().getScale().x > 0 || playerRight(player) && player.get_Sprite().getScale().x < 0))
            {
                set_isHurt(true);

                if (player.get_currentFrame() == 1 && EscapeClock.getElapsedTime().asSeconds() > 0.1f)
                {
                    set_currentFrame(0);

                    *this -= player.getAtk();
                    checkHp();

                    if (!get_isDead())
                        escape();

                    EscapeClock.restart();
                }
            }

            if (getHp() > 0 && player.get_isAttacking3() && (playerLeft(player) && player.get_Sprite().getScale().x > 0 || playerRight(player) && player.get_Sprite().getScale().x < 0))
            {
                set_isHurt(true);

                if (player.get_currentFrame() == 3 && EscapeClock.getElapsedTime().asSeconds() > 0.3f)
                {
                    set_currentFrame(0);

                    *this -= player.getAtk();

                    if (getHp() != 0)
                    {
                        if (playerLeft(player))
                        {
                            move(60.f, 0.f);
                        }
                        if (playerRight(player))
                        {
                            move(-60.f, 0.f);
                        }
                    }

                    checkHp();

                    EscapeClock.restart();
                }
            }
        }
        else if (get_isHurt() && get_currentFrame() >= 3)
            set_isHurt(false);

        if (get_isFlying() && distance(player) < 400)
        {
            if (playerLeft(player))
            {
                move(getSpeed(), -getSpeed());
            }
            if (playerRight(player))
            {
                move(-getSpeed(), -getSpeed());
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
        if (!get_isFlying() && get_comeDown() && get_yPos() < groundLevel)
        {
            move(0, 2 * getSpeed());
        }
        else
        {
            set_comeDown(false);
        }

        if ((get_isFlying() || get_isIdle()) && AtkClock.getElapsedTime().asSeconds() > 2.0f && !get_isHurt() && !player.get_isDead())
        {
            ifAttack();
            set_currentFrame(0);
            AtkClock.restart();
        }
        if (get_isAttacking() && get_currentFrame() == 3)
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
        if ((get_isAttacking() && get_currentFrame() >= 7) || get_isHurt() || get_isDead())
        {
            set_isAttacking(false);
        }

        if (get_Fireball())
        {
            if (recalculateFdir)
            {
                demonPosition = get_FireballSprite().getPosition();
                direction = playerPosition - demonPosition;
                Fball_angle = atan2(direction.y, direction.x) * 180.f / 3.13159f;

                float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                if (length != 0)
                {
                    direction /= length;
                }
                recalculateFdir = false;
            }

            if (get_FireballDir())
            {
                get_FireballSprite().setScale(sf::Vector2f(2.f, 2.f));
                moveFireball(direction.x * get_FireballSpeed(), direction.y * get_FireballSpeed());
                get_FireballSprite().setRotation(sf::degrees(Fball_angle + 180));
                get_fireballHitbox().setRotation(sf::degrees(Fball_angle + 180));
            }
            else if (!get_FireballDir())
            {
                get_FireballSprite().setScale(sf::Vector2f(-2.f, 2.f));
                moveFireball(direction.x * get_FireballSpeed(), direction.y * get_FireballSpeed());
                get_FireballSprite().setRotation(sf::degrees(Fball_angle));
                get_fireballHitbox().setRotation(sf::degrees(Fball_angle));
            }
        }

        if ((checkFireballCollision(player) && (get_isDead() || player.get_isHurt())) ||
            (checkFireballCollision(player) && player.get_isDefending() &&
             ((player.get_Sprite().getScale().x > 0 && get_FireballSprite().getScale().x > 0) ||
              (player.get_Sprite().getScale().x < 0 && get_FireballSprite().getScale().x < 0))))
        {
            bool isBlock = player.get_isDefending() &&
                           ((player.get_Sprite().getScale().x > 0 && get_FireballSprite().getScale().x > 0) ||
                            (player.get_Sprite().getScale().x < 0 && get_FireballSprite().getScale().x < 0));

            if (isBlock)
            {
                player.onShieldBlock();
            }

            set_Fireball(false);
            set_fireball_xPos(get_xPos());
            set_fireball_yPos(get_yPos());
            get_FireballSprite().setPosition({get_xPos(), get_yPos()});
            get_fireballHitbox().setPosition({get_xPos(), get_yPos()});
        }
    }

    if (player.get_isDead())
    {
        set_isHurt(false);
    }

    if (get_isDead() && get_currentFrame() == 6)
    {
        spawn(player);
    }
}

void FlyingDemon::escape()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 6);

    int r = dist(gen);

    if (r == 3)
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

    if (r == 2)
    {
        comedown = true;
    }
}

void FlyingDemon::ifAttack()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 3);

    int r = dist(gen);

    if (r == 2 && !isAttacking)
    {
        isAttacking = true;
        isFlying = false;
    }
}

void FlyingDemon::moveFireball(float x, float y)
{
    fireballSprite.move({x, y});
    fireballHitbox.move({x, y});
    fireball_xPos += x;
    fireball_yPos += y;
}

bool FlyingDemon::checkFireballCollision(Player &player)
{
    if (get_fireballHitbox().getGlobalBounds().findIntersection(player.get_Hitbox().getGlobalBounds()))
        return true;
    else
        return false;
}

void FlyingDemon::playerTakeDmg(Player &player)
{
    if (checkFireballCollision(player) && get_Fireball() && !player.get_isDead())
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
    uniform_int_distribution<int> dist1(150, 1310);

    do
    {
        x = dist1(gen);
    } while (abs(x - player.get_xPos()) < 250);
    set_xPos(x);

    uniform_int_distribution<int> dist2(-400, 0);
    y = dist2(gen);
    set_yPos(y);

    get_Sprite().setPosition({get_xPos(), get_yPos()});
    get_Hitbox().setPosition({get_xPos(), get_yPos()});

    setHp(20);
    set_isDead(false);
    comedown = true;

    set_fireball_xPos(get_xPos());
    set_fireball_yPos(get_yPos());
    get_FireballSprite().setPosition({get_xPos(), get_yPos()});
    get_fireballHitbox().setPosition({get_xPos(), get_yPos()});
}

void FlyingDemon::FlyingDemonSounds()
{
    if (isHurt && !hurtSoundPlayed)
    {
        PlaySound("..//assets//Sounds//FlyingDemon//Hurt.mp3");
        hurtSoundPlayed = true;
    }
    else if (!isHurt)
    {
        hurtSoundPlayed = false;
    }

    if (get_isDead() && !deathSoundPlayed)
    {
        PlaySound("../assets//Sounds//FlyingDemon//Death.mp3");
        deathSoundPlayed = true;
    }
    else if (!get_isDead())
    {
        deathSoundPlayed = false;
    }

    if (isAttacking && !fireballSoundPlayed)
    {
        PlaySound("../assets//Sounds//FlyingDemon//Fireball.mp3");
        fireballSoundPlayed = true;
    }
    else if (!isAttacking)
    {
        fireballSoundPlayed = false;
    }

    if ((isFlying || isIdle))
    {
        if (!flyingSoundPlayed || get_Sound().getStatus() != sf::Sound::Status::Playing)
        {
            PlaySound("../assets//Sounds//FlyingDemon//Flying.mp3");
            flyingSoundPlayed = true;
        }
    }
    else
    {
        if (flyingSoundPlayed && get_Sound().getStatus() == sf::Sound::Status::Playing)
            get_Sound().stop();
        flyingSoundPlayed = false;
    }
}