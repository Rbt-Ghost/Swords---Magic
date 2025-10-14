#include "..\src\headers\GameOver.hpp"

GameOver::GameOver(unsigned int width, unsigned int height) : 
HomeScreen(width, height),                                                              
GameOverText(font),                                                              
PlayAgainText(font),                                                              
HomeText(font),                                                              
sound(buffer)
{
    LoadFont(font, "../assets/Medieval-timeline-font/MedievalTimeline-DOPRE.ttf");

    LoadBackground();

    setWidth(width);
    setHeight(height);

    Background.setSize({(float)getWidth(), (float)getHeight()});
    Background.setFillColor(sf::Color(10, 10, 10, 100));

    GameOverText.setString("Game Over");
    GameOverText.setCharacterSize(100);
    GameOverText.setFillColor(sf::Color::Red);
    GameOverText.setOutlineThickness(5);
    GameOverText.setOutlineColor(sf::Color::Black);
    GameOverText.setPosition({getWidth() / 2 - 250, 50});

    PlayAgainText.setString("Play Again");
    PlayAgainText.setOutlineThickness(5);
    PlayAgainText.setOutlineColor(sf::Color::Black);
    PlayAgainButton.setSize({220, 70});
    PlayAgainButton.setOrigin(PlayAgainButton.getSize() / 2.f);
    PlayAgainButton.setPosition({getWidth() / 2, 300});
    PlayAgainButton.setFillColor(sf::Color::Transparent);
    PlayAgainButton.setOutlineThickness(1);
    PlayAgainButton.setOutlineColor(sf::Color::Red);

    HomeText.setString("Home");
    HomeText.setOutlineThickness(5);
    HomeText.setOutlineColor(sf::Color::Black);
    HomeButton.setSize({120, 50});
    HomeButton.setOrigin(HomeButton.getSize() / 2.f);
    HomeButton.setPosition({getWidth() / 2, 450});
    HomeButton.setFillColor(sf::Color::Transparent);
    HomeButton.setOutlineThickness(1);
    HomeButton.setOutlineColor(sf::Color::Red);
}

GameOver::~GameOver()
{
}

void GameOver::render(sf::RenderWindow &window)
{
    window.setFramerateLimit(60);
    window.clear();
    
    drawBackground(window);
    window.draw(Background);

    window.draw(GameOverText);

    window.draw(PlayAgainText);
    //window.draw(PlayAgainButton);

    window.draw(HomeText);
    //window.draw(HomeButton);

    window.display();
}

void GameOver::LoadBackground()
{
    if (!backgroundTexture->loadFromFile("../assets/GameOverBg.png"))
    {
        cerr << "ERROR :: COULD NOT LOAD BACKGROUND TEXTURE" << std::endl;
    }
}

void GameOver::DefaultPlayAgain()
{
    PlayAgainText.setCharacterSize(50);
    PlayAgainText.setFillColor(sf::Color::Yellow);
    PlayAgainText.setPosition({getWidth() / 2 - 100, 270});
}
void GameOver::HoverPlayAgain()
{
    PlayAgainText.setCharacterSize(55);
    PlayAgainText.setFillColor(sf::Color::Red);
    PlayAgainText.setPosition({getWidth() / 2 - 104, 266});
}

void GameOver::DefaultHome()
{
    HomeText.setCharacterSize(50);
    HomeText.setFillColor(sf::Color::White);
    HomeText.setPosition({getWidth() / 2 - 60, 430});
}

void GameOver::HoverHome()
{
    HomeText.setCharacterSize(55);
    HomeText.setFillColor(sf::Color::Red);
    HomeText.setPosition({getWidth() / 2 - 64, 426});
}

sf::RectangleShape GameOver::getPlayAgainButton()
{
    return PlayAgainButton;
}

sf::RectangleShape GameOver::getHomeButton()
{
    return HomeButton;
}