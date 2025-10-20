#include "../Headers/Screen.hpp"

Screen::Screen(unsigned int width, unsigned int height) :
backgroundTexture(new sf::Texture(sf::Texture()))
{
    setWidth(width);
    setHeight(height);
}

Screen::~Screen()
{}

void Screen::setIsActive(bool isActive)
{
    this->isActive = isActive;
}
bool Screen::getIsActive()
{
    return isActive;
}

float Screen::getWidth()
{
    return width;
}
float Screen::getHeight()
{
    return height;
}
void Screen::setWidth(unsigned int width)
{
    this->width = width;
}
void Screen::setHeight(unsigned int height)
{
    this->height = height;
}


void Screen::LoadFont(sf::Font &font, string std)
{
    if (!font.openFromFile(std))
    {
        cerr << endl << "ERROR";
    }
}
void Screen::LoadBackground()
{
    if (!backgroundTexture->loadFromFile("../assets/Backgrounds/Mokazar - Medieval Castle Background.jpg"))
    {
        cerr << "ERROR :: COULD NOT LOAD BACKGROUND TEXTURE" << std::endl;
    }
}
void Screen::drawBackground(sf::RenderWindow& window)
{
    sf::Sprite backgroundSprite(*backgroundTexture);
    backgroundSprite.setScale(
        {float(width) / backgroundTexture->getSize().x,
         float(height) / backgroundTexture->getSize().y}
    );
    window.draw(backgroundSprite);
}


void Screen::processEvents(sf::RenderWindow &window) 
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void Screen::render(sf::RenderWindow &window)
{}