#include "..\src\Headers\HowToPlayScreen.hpp"

HowToPlayScreen::HowToPlayScreen(unsigned int width, unsigned int height): HomeScreen(width, height),
Instructions(font),
Back(font)
{
    LoadFont(font, "../assets/Medieval-timeline-font/MedievalTimeline-DOPRE.ttf");

    LoadBackground();

    setWidth(width);
    setHeight(height);

    Background.setSize({(float)getWidth(), (float)getHeight()});
    Background.setFillColor(sf::Color(10, 10, 10, 200));

    Instructions.setString("Use A and D to move left and right.\n"
                           "Use W or Space to jump.\n"
                           "Hold Left Shift to run.\n"
                           "Hold J to attack with your sword.\n"
                           "Hold K to raise the shield.\n"
                           "Defeat enemies to earn points and increase your score!\n"
                           "1 point for every second you survive and 10 points for defeating an enemy.\n"
                           "Avoid enemy attacks to stay alive.\n"
                           "Reach the highest score possible!");
    Instructions.setLineSpacing(1.2f);
    //Instructions.setOrigin(Instructions.getLocalBounds().getCenter() / 2.f);
    Instructions.setFillColor(sf::Color::Yellow);
    Instructions.setCharacterSize(35);
    Instructions.setOutlineThickness(5);
    Instructions.setOutlineColor(sf::Color::Black);
    Instructions.setPosition({getWidth() / 2 - 600, 50});

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

HowToPlayScreen::~HowToPlayScreen()
{
}

void HowToPlayScreen::processEvents(sf::RenderWindow& window)
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}
void HowToPlayScreen::render(sf::RenderWindow& window)
{
    //window.setFramerateLimit(60);
    //window.clear();

    drawBackground(window);
    window.draw(Background);

    window.draw(Instructions);

    window.draw(Back);
    //window.draw(BackButton);

    window.display();
}


void HowToPlayScreen::DefaultBack()
{
    Back.setCharacterSize(50);
    Back.setFillColor(sf::Color::Yellow);
    Back.setPosition({getWidth() / 2 - 60, 620});
}
void HowToPlayScreen::HoverBack()
{
    Back.setCharacterSize(55);
    Back.setFillColor(sf::Color::Red);
    Back.setPosition({getWidth() / 2 - 64, 616});
}

sf::RectangleShape HowToPlayScreen::getBackButton()
{
    return BackButton;
}

bool HowToPlayScreen::getIsActive()
{
    return HomeScreen::getIsActive();
}
void HowToPlayScreen::setIsActive(bool isActive)
{
    HomeScreen::setIsActive(isActive);
}