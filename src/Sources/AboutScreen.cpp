#include "..\src\Headers\AboutScreen.hpp"

AboutScreen::AboutScreen(unsigned int width, unsigned int height): HomeScreen(width, height),
About(font),
Back(font)
{
    LoadFont(font, "../assets/Medieval-timeline-font/MedievalTimeline-DOPRE.ttf");

    LoadBackground();

    setWidth(width);
    setHeight(height);

    Background.setSize({(float)getWidth(), (float)getHeight()});
    Background.setFillColor(sf::Color(10, 10, 10, 200));

    About.setString("   Hello there,\n"
                    "Welcome to my very first game ever made,\n"
                    "I hope you'll enjoy it as much as I enjoyed making it..\n"
                    "Here I started my journey in game development, \n"
                    "crafting a game in C++ with SFML which I enjoyed thoroughly.\n"
                    "I will continue this journey and if you want to follow my progress,\n"
                    "feel free to check out my WebPage -> robertnistor.dev \n"
                    "-- Rbt-Ghost [Offline]\n");
    About.setLineSpacing(1.2f);
    About.setFillColor(sf::Color::Yellow);
    About.setCharacterSize(35);
    About.setOutlineThickness(5);
    About.setOutlineColor(sf::Color::Black);
    About.setPosition({getWidth() / 2 - 600, 100});

    Back.setString("Back");
    Back.setOutlineThickness(5);
    Back.setOutlineColor(sf::Color::Black);
    BackButton.setSize({120, 50});
    BackButton.setOrigin(BackButton.getSize() / 2.f);
    BackButton.setPosition({getWidth() / 2, 650});
    BackButton.setFillColor(sf::Color::Transparent);
    BackButton.setOutlineThickness(1);
    BackButton.setOutlineColor(sf::Color::Red);
}

AboutScreen::~AboutScreen()
{
}

void AboutScreen::render(sf::RenderWindow& window)
{
    drawBackground(window);
    window.draw(Background);

    window.draw(About);

    window.draw(Back);
    //window.draw(BackButton);

    window.display();
}

void AboutScreen::DefaultBack()
{
    Back.setCharacterSize(50);
    Back.setFillColor(sf::Color::Yellow);
    Back.setPosition({getWidth() / 2 - 60, 620});
}
void AboutScreen::HoverBack()
{
    Back.setCharacterSize(55);
    Back.setFillColor(sf::Color::Red);
    Back.setPosition({getWidth() / 2 - 64, 616});
}

RectangleShape AboutScreen::getBackButton()
{
    return BackButton;
}

bool AboutScreen::getIsActive()
{
    return isActive;
}
void AboutScreen::setIsActive(bool isActive)
{
    this->isActive = isActive;
}