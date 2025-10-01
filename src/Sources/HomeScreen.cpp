#include "..\src\Headers\HomeScreen.hpp"

HomeScreen::HomeScreen(unsigned int width, unsigned int height) : 
GameTitle(font),
Start(font),
HowToPlay(font),
Credits(font),
About(font),
backgroundTexture(new sf::Texture(sf::Texture()))
{
    LoadFont(font, "../assets/Medieval-timeline-font/MedievalTimeline-DOPRE.ttf");

    if (!backgroundTexture->loadFromFile("../assets/Mokazar - Medieval Castle Background.jpg"))
    {
        cerr << "ERROR :: COULD NOT LOAD BACKGROUND TEXTURE" << std::endl;
    }

    GameTitle.setFont(font);
    GameTitle.setCharacterSize(100);
    GameTitle.setFillColor(sf::Color::Yellow);
    GameTitle.setPosition({1440 / 2 - 390, 100});
    GameTitle.setString("Swords & Magic");
    GameTitle.setOutlineThickness(5);
    GameTitle.setOutlineColor(sf::Color::Black);

    Start.setFont(font);
    Start.setCharacterSize(50);
    Start.setFillColor(sf::Color::Yellow);
    Start.setPosition({1440 / 2 - 132, 300});
    Start.setString("Start Game");
    Start.setOutlineThickness(5);
    Start.setOutlineColor(sf::Color::Black);

    HowToPlay.setFont(font);
    HowToPlay.setCharacterSize(50);
    HowToPlay.setFillColor(sf::Color::Yellow);
    HowToPlay.setPosition({1440 / 2 - 144, 375});
    HowToPlay.setString("How To Play");
    HowToPlay.setOutlineThickness(5);
    HowToPlay.setOutlineColor(sf::Color::Black);

    Credits.setFont(font);
    Credits.setCharacterSize(50);
    Credits.setFillColor(sf::Color::Yellow);
    Credits.setPosition({1440 / 2 - 86, 450});
    Credits.setString("Credits");
    Credits.setOutlineThickness(5);
    Credits.setOutlineColor(sf::Color::Black);

    About.setFont(font);
    About.setCharacterSize(50);
    About.setFillColor(sf::Color::Yellow);
    About.setPosition({1440 / 2 - 72, 525});
    About.setString("About");
    About.setOutlineThickness(5);
    About.setOutlineColor(sf::Color::Black);

    buttonsBox.setSize({300, 350});
    buttonsBox.setOrigin(buttonsBox.getSize() / 2.f);
    buttonsBox.setPosition({1440 / 2, 450});
    buttonsBox.setFillColor(sf::Color(0, 0, 0, 100));
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

    sf::Sprite backgroundSprite(*backgroundTexture);

    //backgroundSprite.setColor(sf::Color(255, 255, 255, 200)); // Set opacity to 200 out of 255
    backgroundSprite.setScale(
        {float(width) / backgroundTexture->getSize().x,
         float(height) / backgroundTexture->getSize().y}
    );

    window.clear();
    window.draw(backgroundSprite);
    window.draw(buttonsBox);
    window.draw(GameTitle);
    window.draw(Start);
    window.draw(HowToPlay);
    window.draw(Credits);
    window.draw(About);
    window.display();
}

void HomeScreen::LoadFont(sf::Font &font, string std)
{
    if (!font.openFromFile(std))
    {
        cerr << endl << "ERROR";
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