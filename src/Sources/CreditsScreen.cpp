#include "..\src\Headers\CreditsScreen.hpp"

CreditsScreen::CreditsScreen(unsigned int width, unsigned int height) : HomeScreen(width, height),
                                                                        Credits(font),
                                                                        Back(font)
{
    LoadFont(font, "../assets/Medieval-timeline-font/MedievalTimeline-DOPRE.ttf");
    LoadBackground();

    setWidth(width);
    setHeight(height);

    Background.setSize({float(width), float(height)});
    Background.setFillColor(Color(10, 10, 10, 200));

    Credits.setString("Ana are mere");
    Credits.setLineSpacing(1.2f);
    Credits.setCharacterSize(35);
    Credits.setFillColor(Color::Yellow);
    Credits.setOutlineThickness(5);
    Credits.setOutlineColor(Color::Black);
    Credits.setOrigin(Credits.getLocalBounds().getCenter() / 2.f);
    Credits.setPosition({float(width) / 2, float(height) / 2});

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

CreditsScreen::~CreditsScreen()
{
}


void CreditsScreen::render(sf::RenderWindow &window)
{
    drawBackground(window);
    window.draw(Background);

    window.draw(Credits);

    window.draw(Back);
    //window.draw(BackButton);

    window.display();
}

void CreditsScreen::DefaultBack()
{
    Back.setCharacterSize(50);
    Back.setFillColor(sf::Color::Yellow);
    Back.setPosition({getWidth() / 2 - 60, 620});
}

void CreditsScreen::HoverBack()
{
    Back.setCharacterSize(55);
    Back.setFillColor(sf::Color::Red);
    Back.setPosition({getWidth() / 2 - 64, 616});
}

RectangleShape CreditsScreen::getBackButton()
{
    return BackButton;
}

bool CreditsScreen::getIsActive()
{
    return isActive;
}

void CreditsScreen::setIsActive(bool isActive)
{
    this->isActive = isActive;
}