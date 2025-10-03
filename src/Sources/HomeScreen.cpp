#include "..\src\Headers\HomeScreen.hpp"

HomeScreen::HomeScreen(unsigned int width, unsigned int height) : 
GameTitle(font),
Start(font),
HowToPlay(font),
Credits(font),
About(font),
Quit(font),
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
    Start.setString("Start Game");
    Start.setOutlineThickness(5);
    Start.setOutlineColor(sf::Color::Black);
    DefaultStart();
    StartButton.setSize({275, 45});
    StartButton.setOrigin(StartButton.getSize() / 2.f);
    StartButton.setPosition({1440 / 2, 330});
    StartButton.setFillColor(sf::Color::Transparent);
    StartButton.setOutlineThickness(1);
    StartButton.setOutlineColor(sf::Color::Red);

    HowToPlay.setFont(font);
    HowToPlay.setString("How To Play");
    HowToPlay.setOutlineThickness(5);
    HowToPlay.setOutlineColor(sf::Color::Black);
    DefaultHowToPlay();
    HowToPlayButton.setSize({275, 45});
    HowToPlayButton.setOrigin(HowToPlayButton.getSize() / 2.f);
    HowToPlayButton.setPosition({1440 / 2, 405});
    HowToPlayButton.setFillColor(sf::Color::Transparent);
    HowToPlayButton.setOutlineThickness(1);
    HowToPlayButton.setOutlineColor(sf::Color::Red);

    Credits.setFont(font);
    Credits.setString("Credits");
    Credits.setOutlineThickness(5);
    Credits.setOutlineColor(sf::Color::Black);
    DefaultCredits();
    CreditsButton.setSize({165, 45});
    CreditsButton.setOrigin(CreditsButton.getSize() / 2.f);
    CreditsButton.setPosition({1440 / 2, 480});
    CreditsButton.setFillColor(sf::Color::Transparent);
    CreditsButton.setOutlineThickness(1);
    CreditsButton.setOutlineColor(sf::Color::Red);

    About.setFont(font);
    About.setString("About");
    About.setOutlineThickness(5);
    About.setOutlineColor(sf::Color::Black);
    DefaultAbout();
    AboutButton.setSize({150, 45});
    AboutButton.setOrigin(AboutButton.getSize() / 2.f);
    AboutButton.setPosition({1440 / 2, 555});
    AboutButton.setFillColor(sf::Color::Transparent);
    AboutButton.setOutlineThickness(1);
    AboutButton.setOutlineColor(sf::Color::Red);

    Quit.setFont(font);
    Quit.setString("Quit");
    Quit.setOutlineThickness(5);
    Quit.setOutlineColor(sf::Color::Black);
    DefaultQuit();
    QuitButton.setSize({110, 45});
    QuitButton.setOrigin(QuitButton.getSize() / 2.f);
    QuitButton.setPosition({1440 / 2, 630});
    QuitButton.setFillColor(sf::Color::Transparent);
    QuitButton.setOutlineThickness(1);
    QuitButton.setOutlineColor(sf::Color::Red);
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

    backgroundSprite.setScale(
        {float(width) / backgroundTexture->getSize().x,
         float(height) / backgroundTexture->getSize().y}
    );

    window.clear();
    window.draw(backgroundSprite);
    window.draw(GameTitle);

    window.draw(Start);
    //window.draw(StartButton);

    window.draw(HowToPlay);
    //window.draw(HowToPlayButton);

    window.draw(Credits);
    //window.draw(CreditsButton);

    window.draw(About);
    //window.draw(AboutButton);

    window.draw(Quit);
    //window.draw(QuitButton);

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

sf::RectangleShape HomeScreen::getStartButton()
{
    return StartButton;
}
sf::RectangleShape HomeScreen::getHowToPlayButton()
{
    return HowToPlayButton;
}
sf::RectangleShape HomeScreen::getCreditsButton()
{
    return CreditsButton;
}
sf::RectangleShape HomeScreen::getAboutButton()
{
    return AboutButton;
}
sf::RectangleShape HomeScreen::getQuitButton()
{
    return QuitButton;
}

void HomeScreen::DefaultStart()
{
    Start.setCharacterSize(50);
    Start.setFillColor(sf::Color::Yellow);
    Start.setPosition({1440 / 2 - 134, 300});
}
void HomeScreen::HoverStart()
{
    Start.setCharacterSize(55);
    Start.setFillColor(sf::Color::Red);
    Start.setPosition({1440 / 2 - 148, 295});
}

void HomeScreen::DefaultHowToPlay()
{
    HowToPlay.setCharacterSize(50);
    HowToPlay.setFillColor(sf::Color::Yellow);
    HowToPlay.setPosition({1440 / 2 - 144, 375});
}
void HomeScreen::HoverHowToPlay()
{
    HowToPlay.setCharacterSize(55);
    HowToPlay.setFillColor(sf::Color::Red);
    HowToPlay.setPosition({1440 / 2 - 159, 370});
}

void HomeScreen::DefaultCredits()
{
    Credits.setCharacterSize(50);
    Credits.setFillColor(sf::Color::Yellow);
    Credits.setPosition({1440 / 2 - 86, 450});
}
void HomeScreen::HoverCredits()
{
    Credits.setCharacterSize(55);
    Credits.setFillColor(sf::Color::Red);
    Credits.setPosition({1440 / 2 - 92, 445});
}

void HomeScreen::DefaultAbout()
{
    About.setCharacterSize(50);
    About.setFillColor(sf::Color::Yellow);
    About.setPosition({1440 / 2 - 72, 525});
}
void HomeScreen::HoverAbout()
{
    About.setCharacterSize(55);
    About.setFillColor(sf::Color::Red);
    About.setPosition({1440 / 2 - 78, 520});
}

void HomeScreen::DefaultQuit()
{
    Quit.setCharacterSize(50);
    Quit.setFillColor(sf::Color::Yellow);
    Quit.setPosition({1440 / 2 - 50, 600});
}
void HomeScreen::HoverQuit()
{
    Quit.setCharacterSize(55);
    Quit.setFillColor(sf::Color::Red);
    Quit.setPosition({1440 / 2 - 54, 595});
}