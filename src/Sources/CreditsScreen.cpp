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

    Credits.setString("Game developed by Robert Nistor\n"
                      "Knight 2D Pixel Art by Mattz Art on itch.io\n"
                      "Flying Demon 2D Pixel Art by Mattz Art on itch.io\n"
                      "Skeleton Warrior 2D Pixel Art by Mattz Art on itch.io\n"
                      "Skeleton Sprite Pack by Jesse Munguia on itch.io\n"
                      "2d-Medieval-Castle-Dungeon-Tileset by TPC on itch.io\n"
                      "HP-Bar by m1ilaan on itch.io\n"
                      "Medieval Timeline Font by Little Red Studio on itch.io\n"
                      "Mokazar - Medieval Castle Background by Arludus on itch.io\n"
                      "All to background music and soundeffects are royalty-free from pixabay.com\n");
    Credits.setLineSpacing(1.2f);
    Credits.setCharacterSize(35);
    Credits.setFillColor(Color::Yellow);
    Credits.setOutlineThickness(5);
    Credits.setOutlineColor(Color::Black);
    Credits.setPosition({float(width) / 2 - 600, 50});

    Back.setString("Back");
    Back.setOutlineThickness(5);
    Back.setOutlineColor(sf::Color::Black);
    BackButton.setSize({120, 50});
    BackButton.setOrigin(BackButton.getSize() / 2.f);
    BackButton.setPosition({getWidth() / 2, 680});
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
    Back.setPosition({getWidth() / 2 - 60, 650});
}

void CreditsScreen::HoverBack()
{
    Back.setCharacterSize(55);
    Back.setFillColor(sf::Color::Red);
    Back.setPosition({getWidth() / 2 - 64, 646});
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