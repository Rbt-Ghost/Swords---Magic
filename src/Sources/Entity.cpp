#include "..\src\Headers\Entity.hpp"

Entity::Entity(string Name, int Hp, int Atk, float Speed) : sprite(texture),
                                                            sound(soundBuffer)
{
    setName(Name);
    setHp(Hp);
    setAtk(Atk);
    setSpeed(Speed);
}
Entity::~Entity()
{
}

void Entity::setName(string Name)
{
    this->Name = Name;
}
void Entity::setHp(int Hp)
{
    if (Hp > 0)
        this->Hp = Hp;
    else
        this->Hp = 0;
}
void Entity::setAtk(int Atk)
{
    this->Atk = Atk;
}
void Entity::setSpeed(float Speed)
{
    this->Speed = Speed;
}
void Entity::set_currentFrame(int currentFrame)
{
    this->currentFrame = currentFrame;
}
void Entity::set_isDead(bool isDead)
{
    this->isDead = isDead;
}
void Entity::set_xPos(float xPos)
{
    this->xPos = xPos;
}
void Entity::set_yPos(float yPos)
{
    this->yPos = yPos;
}

string Entity::getName()
{
    return Name;
}
int Entity::getHp()
{
    return Hp;
}
int Entity::getAtk()
{
    return Atk;
}
float Entity::getSpeed()
{
    return Speed;
}
int Entity::get_currentFrame()
{
    return currentFrame;
}
bool Entity::get_isDead()
{
    return isDead;
}
float Entity::get_xPos()
{
    return xPos;
}
float Entity::get_yPos()
{
    return yPos;
}
sf::Sprite &Entity::get_Sprite()
{
    return sprite;
}
sf::Texture &Entity::get_Texture()
{
    return texture;
}
sf::RectangleShape &Entity::get_Hitbox()
{
    return hitbox;
}
sf::Sound &Entity::get_Sound()
{
    return sound;
}
sf::SoundBuffer &Entity::get_SoundBuffer()
{
    return soundBuffer;
}


Entity &Entity::operator+=(int Heal)
{
    setHp(Hp += Heal);
    return *this;
}
Entity &Entity::operator-=(int Damage)
{
    setHp(Hp -= Damage);
    return *this;
}

Entity &Entity::operator*=(int Heal)
{
    setHp(Hp *= Heal);
    return *this;
}
Entity &Entity::operator/=(int Damage)
{
    setHp(Hp /= Damage);
    return *this;
}
bool operator==(const Entity a, const Entity b)
{
    return (a.Name == b.Name);
}

void Entity::updateAnimation() {}

void Entity::jump() {}

void Entity::updatePhysics() {}

void Entity::move(float x, float y)
{
    if (0 <= xPos + x && xPos + x <= 1440)
    {
        sprite.move({x, y});
        hitbox.move({x, y});
        xPos += x;
        yPos += y;
    }
}

void Entity::checkHp()
{
    if (Hp == 0 && !isDead)
    {
        isDead = true;
        currentFrame = 0;
    }
}

static std::mt19937 &rng()
{
    static std::mt19937 gen{std::random_device{}()};
    return gen;
}

void Entity::PlaySound(const std::filesystem::path &filename)
{
    if (!soundBuffer.loadFromFile(filename.string()))
    {
        std::cerr << "Error loading sound file: " << filename.string() << '\n';
        return;
    }

    std::uniform_real_distribution<float> dist(-0.10f, 0.10f);
    float pitchVariation = dist(rng());

    sound.setBuffer(soundBuffer);
    sound.setPitch(1.0f + pitchVariation);
    sound.play();
}