#include "..\src\Headers\HomeScreen.hpp"

HomeScreen::HomeScreen(unsigned int width, unsigned int height) : Start(font)
{
    LoadFont(font, "../assets/Medieval-timeline-font/MedievalTimeline-DOPRE.ttf");

    Start.setFont(font);
    Start.setCharacterSize(50);
    Start.setFillColor(sf::Color::Yellow);
    Start.setPosition({1440 / 2 - 120, 300});
    Start.setString("Start Game");
}

HomeScreen::~HomeScreen()
{
}

void HomeScreen::processEvents(sf::RenderWindow &window)
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void HomeScreen::render(sf::RenderWindow &window)
{
    window.setFramerateLimit(60);

    window.clear();
    window.draw(Start);
    window.display();
}

void HomeScreen::LoadFont(sf::Font &font, string std)
{
    if (!font.openFromFile(std))
    {
        cerr << endl
             << "ERROR";
    }
}

void HomeScreen::setIsActive(bool isActive)
{
    this->isActive = isActive;
}

bool HomeScreen::getIsActive()
{
    return isActive;
}