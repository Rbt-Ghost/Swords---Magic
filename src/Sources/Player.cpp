#include "..\src\Headers\Player.hpp"

Player::Player(string Name, int Hp, int Atk, float Speed): 
Entity(Name,Hp,Atk,Speed),
sprite(idleTexture)
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
    sprite.setPosition({1440/2, 800/4});
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

sf::Sprite& Player::get_Sprite()
{
    return sprite;
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

        if (isJumping)
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
        else if (isHurt)
        {
            if (currentFrame >= 4)
                currentFrame = 0;
            sprite.setTexture(hurtTexture);
            sprite.setTextureRect(hurtFrames[currentFrame]);
        }
        else if (isMovingR)
        {
            sprite.setScale(sf::Vector2f(2.f, 2.f));
            if (currentFrame >= 8)
                currentFrame = 0;
            sprite.setTexture(walkTexture);
            sprite.setTextureRect(walkFrames[currentFrame]);
        }
        else if (isMovingL)
        {
            sprite.setScale(sf::Vector2f(-2.f, 2.f));
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
        else if (isDead)
        {
            if (currentFrame >= 12)
                currentFrame = 0;
            sprite.setTexture(deathTexture);
            sprite.setTextureRect(deathFrames[currentFrame]);
            if(currentFrame == 11)
            {
                sprite.setPosition({-1000,-1000});
            }
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
    sprite.move({x,y});
}


void Player::jump()
{
    if (!isJumping && sprite.getPosition().y == groundLevel && jumpClock.getElapsedTime().asSeconds() > jumpCooldown)
    {   
        isJumping = true;
        yVelocity = -12.f; // Moves player up
        jumpClock.restart();
    }
}


void Player::updatePhysics()
{
    if (isJumping || isFalling)
    {
        yVelocity += 0.8f; // Apply gravity
    sprite.move({0, yVelocity}); // Move sprite based on velocity
    }

    if (sprite.getPosition().y >= groundLevel)
    {
        sprite.setPosition({sprite.getPosition().x, groundLevel});
        isJumping = false;
        isFalling = false;
        yVelocity = 0;
    }
    else
    {
        isFalling = true;
    }
}

/*
bool Player::animationFinished()
{
    if (isAttacking1 && currentFrame >= 5) return true; // Atk 1 has 6 frames
    if (isAttacking2 && currentFrame >= 4) return true; // Atk 2 has 5 frames
    if (isAttacking3 && currentFrame >= 5) return true; // Atk 3 has 6 frames
    return false;
}


float Player::getCurrentAttackDuration() 
{
    if (isAttacking1) return 0.6f;  // Adjust based on animation time
    if (isAttacking2) return 0.5f;
    if (isAttacking3) return 0.6f;
    return 0.0f;
}
*/