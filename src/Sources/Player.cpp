#include "..\src\Headers\Player.hpp"

Player::Player(string Name, int Hp, int Atk, float Speed): 
Entity(Name,Hp,Atk,Speed),
HpBar(HpBarTexture100)
{

    if (!idleTexture.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Sprites/IDLE.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD IDLE SPRITE" << std::endl;
    }
    if (!walkTexture.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Sprites/WALK.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD WALK SPRITE" << endl;
    }
    if (!jumpTexture.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Sprites/JUMP.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD JUMP SPRITE" << endl;
    }
    if (!defendTexture.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Sprites/DEFEND.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD DEFEND SPRITE" << endl;
    }
    if (!attackTexture1.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Sprites/ATTACK 1.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD ATTACK SPRITE" << endl;
    }
    if (!attackTexture2.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Sprites/ATTACK 2.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD ATTACK SPRITE" << endl;
    }
    if (!attackTexture3.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Sprites/ATTACK 3.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD ATTACK SPRITE" << endl;
    }
    if (!runningTexture.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Sprites/RUN.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD RUNNING SPRITE" << endl;
    }
    if (!deathTexture.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Sprites/DEATH.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD IDLE SPRITE" << endl;
    }
    if (!hurtTexture.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Sprites/HURT.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD IDLE SPRITE" << endl;
    }
    if (!HpBarTexture100.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Hp_Bar/hp100.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture90.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Hp_Bar/hp90.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture80.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Hp_Bar/hp80.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture70.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Hp_Bar/hp70.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture60.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Hp_Bar/hp60.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture50.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Hp_Bar/hp50.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture40.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Hp_Bar/hp40.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture30.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Hp_Bar/hp30.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;;
    }
    if (!HpBarTexture20.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Hp_Bar/hp20.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }
    if (!HpBarTexture10.loadFromFile("../assets/2D_Models/Knight 2D Pixel Art/Hp_Bar/hp10.png"))
    {
        cerr << "ERROR :: COULD NOT Texture SPRITE" << endl;
    }


    get_Sprite().setTexture(idleTexture);

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

    set_xPos(1440/2.f);
    set_yPos(500.f);

    get_Sprite().setTextureRect(idleFrames[0]);
    get_Sprite().setScale(sf::Vector2f(2.f,2.f));
    get_Sprite().setOrigin({48,42});
    get_Sprite().setPosition({get_xPos(), get_yPos()});
    get_Hitbox().setFillColor(sf::Color::Transparent);
    get_Hitbox().setOutlineColor(sf::Color::Red);
    get_Hitbox().setOutlineThickness(1.f);
    get_Hitbox().setPosition({get_xPos(), get_yPos()});

    HpBar.setScale({0.08,0.08});
    HpBar.setOrigin({0,0});
    HpBar.setPosition({-10,-10});

    Hp_Bar = sf::IntRect({0,0},{3328,1300});

    get_Sound().setVolume(92.5f);
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
    if (isAttacking1 && !this->isAttacking1)
        swordSoundPlayed = false;
    if (!isAttacking1 && this->isAttacking1)
    {
        if (currentSoundType == SoundType::Sword && get_Sound().getStatus() == sf::Sound::Status::Playing)
            stopCurrentSound();
        swordSoundPlayed = false;
    }
    this->isAttacking1 = isAttacking1;
}
void Player::set_isAttacking2(bool isAttacking2)
{
    if (isAttacking2 && !this->isAttacking2)
        swordSoundPlayed = false;
    if (!isAttacking2 && this->isAttacking2)
    {
        if (currentSoundType == SoundType::Sword && get_Sound().getStatus() == sf::Sound::Status::Playing)
            stopCurrentSound();
        swordSoundPlayed = false;
    }
    this->isAttacking2 = isAttacking2;
}
void Player::set_isAttacking3(bool isAttacking3)
{
    if (isAttacking3 && !this->isAttacking3)
        swordSoundPlayed = false;
    if (!isAttacking3 && this->isAttacking3)
    {
        if (currentSoundType == SoundType::Sword && get_Sound().getStatus() == sf::Sound::Status::Playing)
            stopCurrentSound();
        swordSoundPlayed = false;
    }
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
void Player::set_GroundLevel(float groundLevel)
{
    this->groundLevel = groundLevel;
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
        set_currentFrame(get_currentFrame() + 1);

        if (isHurt)
        {
            if (get_currentFrame() >= 4)
            {
                isAttacking1 = false;
                isAttacking2 = false;
                isAttacking3 = false;
                set_currentFrame(0);
                isHurt = false;
            }
            get_Sprite().setTexture(hurtTexture);
            get_Sprite().setTextureRect(hurtFrames[get_currentFrame()]);
        }
        else if (get_isDead())
        {
            if (get_currentFrame() >= 12)
                set_currentFrame(11);
            get_Sprite().setTexture(deathTexture);
            get_Sprite().setTextureRect(deathFrames[get_currentFrame()]);
            if (get_currentFrame() == 11)
            {
                get_Sprite().setPosition({-1000.f, -1000.f});
                get_Hitbox().setPosition({-1000.f, -1000.f});
            }
        }
        else if (isJumping)
        {
            if (get_currentFrame() >= 5)
                set_currentFrame(0);
            get_Sprite().setTexture(jumpTexture);
            get_Sprite().setTextureRect(jumpFrames[get_currentFrame()]);
        }
        else if (isAttacking1)
        {
            if (get_currentFrame() >= 6)
            {
                set_currentFrame(0);
                set_isAttacking1(false);
                set_isAttacking2(true);
            }
            get_Sprite().setTexture(attackTexture1);
            get_Sprite().setTextureRect(attackFrames1[get_currentFrame()]);
        }
        else if (isAttacking2)
        {
            if (get_currentFrame() >= 5)
            {
                set_currentFrame(0);
                set_isAttacking2(false);
                set_isAttacking3(true);
            }
            get_Sprite().setTexture(attackTexture2);
            get_Sprite().setTextureRect(attackFrames2[get_currentFrame()]);
        }
        else if (isAttacking3)
        {
            if (get_currentFrame() >= 6)
            {
                set_currentFrame(0);
                set_isAttacking3(false);
                set_isAttacking1(true);
            }
            get_Sprite().setTexture(attackTexture3);
            get_Sprite().setTextureRect(attackFrames3[get_currentFrame()]);
        }
        else if (isDefending)
        {
            if (get_currentFrame() >= 6)
                set_currentFrame(0);
            get_Sprite().setTexture(defendTexture);
            get_Sprite().setTextureRect(defendFrames[get_currentFrame()]);
        }
        else if (isMovingR)
        {
            if (get_currentFrame() >= 8)
                set_currentFrame(0);
            get_Sprite().setTexture(walkTexture);
            get_Sprite().setTextureRect(walkFrames[get_currentFrame()]);
        }
        else if (isMovingL)
        {
            if (get_currentFrame() >= 8)
                set_currentFrame(0);
            get_Sprite().setTexture(walkTexture);
            get_Sprite().setTextureRect(walkFrames[get_currentFrame()]);
        }
        else if (isRunning)
        {
            if (get_currentFrame() >= 8)
                set_currentFrame(0);
            get_Sprite().setTexture(runningTexture);
            get_Sprite().setTextureRect(runningFrames[get_currentFrame()]);
        }
        else
        {
            if (get_currentFrame() >= 7)
                set_currentFrame(0);
            get_Sprite().setTexture(idleTexture);
            get_Sprite().setTextureRect(idleFrames[get_currentFrame()]);
        }

        animationClock.restart();
    }
}


void Player::jump()
{
    if (!isJumping && get_Sprite().getPosition().y == groundLevel && jumpClock.getElapsedTime().asSeconds() > jumpCooldown)
    {   
        isJumping = true;
        yVelocity = -14.f;
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

    if (get_Sprite().getPosition().y >= groundLevel)
    {
        get_Sprite().setPosition({get_Sprite().getPosition().x, groundLevel});
        get_Hitbox().setPosition({get_Hitbox().getPosition().x, groundLevel});
        isJumping = false;
        isFalling = false;
        yVelocity = 0;
    }
    else
    {
        isFalling = true;
    }
}


void Player::respawn()
{   
    set_isDead(false);
    setHp(100);
    groundLevel = 710;
    set_xPos(1440/2);
    set_yPos(500);
    get_Sprite().setPosition({get_xPos(), get_yPos()});
    get_Hitbox().setPosition({get_xPos(), get_yPos()});
}

void Player::KnightSounds()
{
    if (isHurt && !hurtSoundPlayed)
    {
        if (moveSoundPlayed && currentSoundType == SoundType::Walk && get_Sound().getStatus() == sf::Sound::Status::Playing)
            stopCurrentSound();
        moveSoundPlayed = false;
        if (runSoundPlayed && currentSoundType == SoundType::Run && get_Sound().getStatus() == sf::Sound::Status::Playing)
            stopCurrentSound();
        runSoundPlayed = false;

        PlaySoundWithType("..//assets//Sounds//Knight//Hurt.mp3", SoundType::Hurt);
        hurtSoundPlayed = true;
    }
    else if (!isHurt)
    {
        hurtSoundPlayed = false;
    }
    if (get_isDead() && !deathSoundPlayed)
    {
        PlaySound("..//assets//Sounds//Knight//Death.mp3");
        deathSoundPlayed = true;
    }
    else if (!get_isDead())
    {
        deathSoundPlayed = false;
    }
    if (isJumping && !jumpSoundPlayed)
    {
        PlaySound("..//assets//Sounds//Knight//Jump.mp3");
        get_Sound().setPlayingOffset(sf::seconds(0.24f));
        jumpSoundPlayed = true;
    }
    else if (!isJumping)
    {
        jumpSoundPlayed = false;
    }

    if (!isDefending)
    {
        defendSoundPlayed = false;
    }
    if ((isAttacking1 || isAttacking2 || isAttacking3) && !swordSoundPlayed)
    {
        PlaySoundWithType("..//assets//Sounds//Knight//Sword.mp3", SoundType::Sword);
        swordSoundPlayed = true;
    }
    else if (!isAttacking1 && !isAttacking2 && !isAttacking3)
    {
        swordSoundPlayed = false;
        if (currentSoundType == SoundType::Sword && get_Sound().getStatus() == sf::Sound::Status::Playing)
            stopCurrentSound();
    }

    if ((isMovingR || isMovingL) && !isRunning && !isHurt)
    {
        if (!moveSoundPlayed || currentSoundType != SoundType::Walk || get_Sound().getStatus() != sf::Sound::Status::Playing)
        {
            PlaySoundWithType("..//assets//Sounds//Knight//Walking.mp3", SoundType::Walk);
            moveSoundPlayed = true;
        }
    }
    else
    {
        if (moveSoundPlayed && currentSoundType == SoundType::Walk && get_Sound().getStatus() == sf::Sound::Status::Playing)
            stopCurrentSound();
        moveSoundPlayed = false;
    }

    if (isRunning && !isHurt)
    {
        if (!runSoundPlayed || currentSoundType != SoundType::Run || get_Sound().getStatus() != sf::Sound::Status::Playing)
        {
            PlaySoundWithType("..//assets//Sounds//Knight//Running.mp3", SoundType::Run);
            runSoundPlayed = true;
        }
    }
    else
    {
        if (runSoundPlayed && currentSoundType == SoundType::Run && get_Sound().getStatus() == sf::Sound::Status::Playing)
            stopCurrentSound();
        runSoundPlayed = false;
    }
}
void Player::onShieldBlock()
{
    if (!defendSoundPlayed || currentSoundType != SoundType::Shield || get_Sound().getStatus() != sf::Sound::Status::Playing)
    {
        PlaySoundWithType("..//assets//Sounds//Knight//Shield.mp3", SoundType::Shield);
        defendSoundPlayed = true;
    }
}

static std::mt19937& player_rng()
{
    static std::mt19937 gen{std::random_device{}()};
    return gen;
}

void Player::PlaySound(const std::filesystem::path& filename)
{
    if (!get_SoundBuffer().loadFromFile(filename.string()))
    {
        std::cerr << "Error loading sound file: " << filename.string() << '\n';
        return;
    }

    std::uniform_real_distribution<float> dist(-0.10f, 0.10f);
    float pitchVariation = dist(player_rng());

    get_Sound().setBuffer(get_SoundBuffer());
    get_Sound().setPitch(1.0f + pitchVariation);
    get_Sound().play();
    currentSoundType = SoundType::None;
}

void Player::PlaySoundWithType(const std::filesystem::path& filename, SoundType type)
{
    if (!get_SoundBuffer().loadFromFile(filename.string()))
    {
        std::cerr << "Error loading sound file: " << filename.string() << '\n';
        return;
    }

    std::uniform_real_distribution<float> dist(-0.10f, 0.10f);
    float variation = dist(player_rng());

    get_Sound().setBuffer(get_SoundBuffer());
    get_Sound().setPitch(1.0f + variation);
    get_Sound().play();
    currentSoundType = type;
}
void Player::stopCurrentSound()
{
    if (get_Sound().getStatus() == sf::Sound::Status::Playing)
        get_Sound().stop();
    currentSoundType = SoundType::None;
    swordSoundPlayed = false;
}

void Player::playerAttack()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::J) && isJumping == false)
    {
        if (!get_isAttacking2() && !get_isAttacking3())
        {
            set_isAttacking1(true);
            if (checkAtk1)
            {
                set_currentFrame(0);
                checkAtk1 = false;
            }
            if(get_Sprite().getScale().x > 0)
            {
                get_Hitbox().setSize({75.f, 55.f});
            }
            else if(get_Sprite().getScale().x < 0)
            {
                get_Hitbox().setSize({75.f, 55.f});
                get_Hitbox().setOrigin({get_Hitbox().getSize().x / 2 + 24, get_Hitbox().getSize().y / 2 - 7.5f});
            }
        }
        else if (!get_isAttacking1() && !get_isAttacking3())
        {
            set_isAttacking2(true);
            checkAtk1 = true;
        }
        else if (!get_isAttacking1() && !get_isAttacking2())
        {
            set_isAttacking3(true);
        }
    }
    else
    {

        set_isAttacking1(false);
        set_isAttacking2(false);
        set_isAttacking3(false);
    }
}
void Player::playerDefend()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::K))
    {
        if (!get_isDefending() && !get_isHurt() && DefendClock.getElapsedTime().asSeconds() > 1.0f)
        {
            set_currentFrame(0);
            set_isDefending(true);
            DefendClock.restart();
        }
    }
    if (get_currentFrame() == 5)
    {
        set_isDefending(false);
    }
}
void Player::playerMoveR()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
    {
        get_Sprite().setScale(sf::Vector2f(2.f, 2.f));
        set_isMovingR(true);
        move(getSpeed(), 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::LShift))
        {
            set_isMovingR(false);
            set_isRunning(true);
            move(getSpeed() + 0.5f, 0.f);
        }
        else
        {
            set_isRunning(false);
        }
    }
    else
    {
        set_isMovingR(false);
        set_isRunning(false);
    }
}
void Player::playerMoveL()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
    {
        get_Sprite().setScale(sf::Vector2f(-2.f, 2.f));
        set_isMovingL(true);
        move(-getSpeed(), 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::LShift))
        {
            set_isMovingL(false);
            set_isRunning(true);
            move(-getSpeed() - 0.5f, 0.f);
        }
        else
        {
            set_isRunning(false);
        }
    }
    else
    {
        set_isMovingL(false);
    }
}
void Player::playerJump()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
    {
        if (!get_isJumping())
            jump();
    }
}