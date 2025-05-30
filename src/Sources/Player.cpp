#include "..\src\Headers\Player.hpp"

Player::Player(string Name, int Hp, int Atk, float Speed): 
Entity(Name,Hp,Atk,Speed),
sprite(idleTexture),
HpBar(HpBarTexture100)
{

    if (!idleTexture.loadFromFile("../assets/Knight 2D Pixel Art/Sprites/with_outline/IDLE.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD IDLE SPRITE" << std::endl;
    }
    if (!walkTexture.loadFromFile("../assets/Knight 2D Pixel Art/Sprites/with_outline/WALK.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD WALK SPRITE" << endl;
    }
    if (!jumpTexture.loadFromFile("../assets/Knight 2D Pixel Art/Sprites/with_outline/JUMP.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD JUMP SPRITE" << endl;
    }
    if (!defendTexture.loadFromFile("../assets/Knight 2D Pixel Art/Sprites/with_outline/DEFEND.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD DEFEND SPRITE" << endl;
    }
    if (!attackTexture1.loadFromFile("../assets/Knight 2D Pixel Art/Sprites/with_outline/ATTACK 1.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD ATTACK SPRITE" << endl;
    }
    if (!attackTexture2.loadFromFile("../assets/Knight 2D Pixel Art/Sprites/with_outline/ATTACK 2.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD ATTACK SPRITE" << endl;
    }
    if (!attackTexture3.loadFromFile("../assets/Knight 2D Pixel Art/Sprites/with_outline/ATTACK 3.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD ATTACK SPRITE" << endl;
    }
    if (!runningTexture.loadFromFile("../assets/Knight 2D Pixel Art/Sprites/with_outline/RUN.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD RUNNING SPRITE" << endl;
    }
    if (!deathTexture.loadFromFile("../assets/Knight 2D Pixel Art/Sprites/with_outline/DEATH.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD IDLE SPRITE" << endl;
    }
    if (!hurtTexture.loadFromFile("../assets/Knight 2D Pixel Art/Sprites/with_outline/HURT.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD IDLE SPRITE" << endl;
    }
    if (!HpBarTexture100.loadFromFile("../assets/Hp_Bar/hp100.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture90.loadFromFile("../assets/Hp_Bar/hp90.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture80.loadFromFile("../assets/Hp_Bar/hp80.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture70.loadFromFile("../assets/Hp_Bar/hp70.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture60.loadFromFile("../assets/Hp_Bar/hp60.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture50.loadFromFile("../assets/Hp_Bar/hp50.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture40.loadFromFile("../assets/Hp_Bar/hp40.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture30.loadFromFile("../assets/Hp_Bar/hp30.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;;
    }
    if (!HpBarTexture20.loadFromFile("../assets/Hp_Bar/hp20.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture10.loadFromFile("../assets/Hp_Bar/hp10.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }


    sprite.setTexture(idleTexture);

    for(int i=0; i<7; i++)
    {
        idleFrames[i] = sf::IntRect({96*i, 0}, {96, 84});
    }
    for(int i=0; i<8; i++)
    {
        walkFrames[i] = sf::IntRect({96*i, 0}, {96, 84});
    }
    for(int i=0; i<5; i++)
    {
        jumpFrames[i] = sf::IntRect({96*i, 0}, {96, 84});
    }
    for(int i=0; i<6; i++)
    {
        defendFrames[i] = sf::IntRect({96*i, 0}, {96, 84});
    }
    for(int i=0; i<6; i++)
    {
        attackFrames1[i] = sf::IntRect({96*i, 0}, {96, 84});
    }
    for(int i=0; i<5; i++)
    {
        attackFrames2[i] = sf::IntRect({96*i, 0}, {96, 84});
    }
    for(int i=0; i<6; i++)
    {
        attackFrames3[i] = sf::IntRect({96*i, 0}, {96, 84});
    }
    for(int i=0; i<8; i++)
    {
        runningFrames[i] = sf::IntRect({96*i, 0}, {96, 84});
    }
    for(int i=0; i<4; i++)
    {
        hurtFrames[i] = sf::IntRect({96*i, 0}, {96, 84});
    }
    for(int i=0; i<12; i++)
    {
        deathFrames[i] = sf::IntRect({96*i, 0}, {96, 84});
    }

    sprite.setTextureRect(idleFrames[0]);
    sprite.setScale(sf::Vector2f(2.f,2.f));
    sprite.setOrigin({48,42});
    sprite.setPosition({xPos, yPos});
    
    hitbox.setSize({40.f,70.f});
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1.f);
    hitbox.setOrigin({hitbox.getSize().x/2, hitbox.getSize().y/2});
    hitbox.setPosition({xPos,yPos});

    HpBar.setScale({0.08,0.08});
    HpBar.setOrigin({0,0});
    HpBar.setPosition({-10,-10});

    Hp_Bar = sf::IntRect({0,0},{3328,1300});
}

Player::~Player() 
{}

void Player::set_isMovingR(bool isMovingR)
{
    this->isMovingR = isMovingR;
}
void Player::set_isMovingL(bool isMovingL)
{
    this->isMovingL = isMovingL;
}
void Player::set_isJumping(bool isJumping)
{
    this->isJumping = isJumping;
}
void Player::set_isDefending(bool isDefending)
{
    this->isDefending = isDefending;
}
void Player::set_isAttacking1(bool isAttacking1)
{
    this->isAttacking1 = isAttacking1;
}
void Player::set_isAttacking2(bool isAttacking2)
{
    this->isAttacking2 = isAttacking2;
}
void Player::set_isAttacking3(bool isAttacking3)
{
    this->isAttacking3 = isAttacking3;
}
void Player::set_isRunning(bool isRunning)
{
    this->isRunning = isRunning;
}
void Player::set_isHurt(bool isHurt)
{
    this->isHurt = isHurt;
}
void Player::set_isDead(bool isDead)
{
    this->isDead = isDead;
}
void Player::set_currentFrame(int currentFrame)
{
    this->currentFrame = currentFrame;
}
void Player::set_GroundLevel(float groundLevel)
{
    this->groundLevel = groundLevel;
}
void Player::set_xPos(float xPos)
{
    this->xPos = xPos;
}
void Player::set_yPos(float yPos)
{
    this->yPos = yPos;
}

sf::Sprite& Player::get_Sprite()
{
    return sprite;
}
sf::Sprite& Player::get_Hp_Bar()
{

        if (getHp() >= 91)
        {
            HpBar.setTexture(HpBarTexture100);
            HpBar.setTextureRect(Hp_Bar);
        }
        else if (getHp() >= 81)
        {
            HpBar.setTexture(HpBarTexture90);
            HpBar.setTextureRect(Hp_Bar);
        }
        else if (getHp() >= 71)
        {
            HpBar.setTexture(HpBarTexture80);
            HpBar.setTextureRect(Hp_Bar);
        }
        else if (getHp() >= 61)
        {
            HpBar.setTexture(HpBarTexture70);
            HpBar.setTextureRect(Hp_Bar);
        }
        else if (getHp() >= 51)
        {
            HpBar.setTexture(HpBarTexture60);
            HpBar.setTextureRect(Hp_Bar);
        }
        else if (getHp() >= 41)
        {
            HpBar.setTexture(HpBarTexture50);
            HpBar.setTextureRect(Hp_Bar);
        }
        else if (getHp() >= 31)
        {
            HpBar.setTexture(HpBarTexture40);
            HpBar.setTextureRect(Hp_Bar);
        }
        else if (getHp() >= 21)
        {
            HpBar.setTexture(HpBarTexture30);
            HpBar.setTextureRect(Hp_Bar);
        }
        else if (getHp() >= 11)
        {
            HpBar.setTexture(HpBarTexture20);
            HpBar.setTextureRect(Hp_Bar);
        }
        else
        {
            HpBar.setTexture(HpBarTexture10);
            HpBar.setTextureRect(Hp_Bar);
        }

    return HpBar;
}
sf::RectangleShape& Player::get_Hitbox()
{
    return hitbox;
}
int Player::get_currentFrame()
{
    return currentFrame;
}
bool Player::get_isMovingR()
{
    return isMovingR;
}
bool Player::get_isMovingL()
{
    return isMovingL;
}
bool Player::get_isJumping()
{
    return isJumping;
}
bool Player::get_isDefending()
{
    return isDefending;
}
bool Player::get_isAttacking1()
{
    return isAttacking1;
}
bool Player::get_isAttacking2()
{
    return isAttacking2;
}
bool Player::get_isAttacking3()
{
    return isAttacking3;
}
bool Player::get_isRunning()
{
    return isRunning;
}
bool Player::get_isHurt()
{
    return isHurt;
}
bool Player::get_isDead()
{
    return isDead;
}
float Player::get_xPos()
{
    return xPos;
}
float Player::get_yPos()
{
    return yPos;
}
bool Player::get_isFalling()
{
    return isFalling;
}
float Player::get_groundLevel()
{
    return groundLevel;
}


Player &Player::operator+=(int Heal)
{
    Entity::operator+=(Heal);
    return *this;
}
Player &Player::operator-=(int Damage)
{
    Entity::operator-=(Damage);
    return *this;
}


void Player::updateAnimation()
{
    if (animationClock.getElapsedTime().asSeconds() > 0.1f)
    {
        currentFrame++;

        if (isHurt)
        {
            if (currentFrame >= 4)
            {
                currentFrame = 0;
                isHurt = false;
            }
            sprite.setTexture(hurtTexture);
            sprite.setTextureRect(hurtFrames[currentFrame]);
        }
        else if (isDead)
        {
            if (currentFrame >= 12)
                currentFrame = 0;
            sprite.setTexture(deathTexture);
            sprite.setTextureRect(deathFrames[currentFrame]);
            if(currentFrame == 11)
            {
                sprite.setPosition({-1000,-1000});
                hitbox.setPosition({-1000,-1000});
            }
        }
        else if (isJumping)
        {
            if (currentFrame >= 5)
                currentFrame = 0;
            sprite.setTexture(jumpTexture);
            sprite.setTextureRect(jumpFrames[currentFrame]);
        }
        else if (isAttacking1)
        {
            if (currentFrame >= 6)
            {
                currentFrame = 0;
                isAttacking1 = false;
                isAttacking2 = true;
            }
            sprite.setTexture(attackTexture1);
            sprite.setTextureRect(attackFrames1[currentFrame]);
        }
        else if (isAttacking2)
        {
            if (currentFrame >= 5)
            {
                currentFrame = 0;
                isAttacking2 = false;
                isAttacking3 = true;
            }
            sprite.setTexture(attackTexture2);
            sprite.setTextureRect(attackFrames2[currentFrame]);
        }
        else if (isAttacking3)
        {
            if (currentFrame >= 6)
            {
                currentFrame = 0;
                isAttacking3 = false;
                isAttacking1 = true;
            }
            sprite.setTexture(attackTexture3);
            sprite.setTextureRect(attackFrames3[currentFrame]);
        }
        else if (isDefending)
        {
            if (currentFrame >= 6)
                currentFrame = 0;
            sprite.setTexture(defendTexture);
            sprite.setTextureRect(defendFrames[currentFrame]);
        }
        else if (isMovingR)
        {
            if (currentFrame >= 8)
                currentFrame = 0;
            sprite.setTexture(walkTexture);
            sprite.setTextureRect(walkFrames[currentFrame]);
        }
        else if (isMovingL)
        {
            if (currentFrame >= 8)
                currentFrame = 0;
            sprite.setTexture(walkTexture);
            sprite.setTextureRect(walkFrames[currentFrame]);
        }
        else if (isRunning)
        {
            if (currentFrame >= 8)
                currentFrame = 0;
            sprite.setTexture(runningTexture);
            sprite.setTextureRect(runningFrames[currentFrame]);
        }
        else
        {
            if (currentFrame >= 7)
                currentFrame = 0;
            sprite.setTexture(idleTexture);
            sprite.setTextureRect(idleFrames[currentFrame]);
        }

        animationClock.restart();
    }
}


void Player::move(float x, float y)
{
    if (0 <= xPos + x && xPos + x <= 1440)
    {
        sprite.move({x,y});
        hitbox.move({x,y});
        xPos+=x;
        yPos+=y;
    }
}


void Player::jump()
{
    if (!isJumping && sprite.getPosition().y == groundLevel && jumpClock.getElapsedTime().asSeconds() > jumpCooldown)
    {   
        isJumping = true;
        yVelocity = -12.f;
        jumpClock.restart();
    }
}


void Player::updatePhysics()
{
    if (isJumping || isFalling)
    {
        yVelocity += 0.8f;
        move(0,yVelocity);
    }

    if (sprite.getPosition().y >= groundLevel)
    {
        sprite.setPosition({sprite.getPosition().x, groundLevel});
        hitbox.setPosition({hitbox.getPosition().x, groundLevel});
        isJumping = false;
        isFalling = false;
        yVelocity = 0;
    }
    else
    {
        isFalling = true;
    }
}


void Player::checkHp()
{
    if (getHp() == 0)
    {
        isDead = true;
        currentFrame = 0;
    }
}


void Player::respawn()
{   
    isDead = false;
    setHp(100);
    groundLevel = 710;
    xPos=1440/2;
    yPos=500;
    sprite.setPosition({xPos, yPos});
    hitbox.setPosition({xPos,yPos});
}