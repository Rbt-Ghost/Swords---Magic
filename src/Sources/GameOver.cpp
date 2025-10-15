#include "..\src\headers\GameOver.hpp"
#include <algorithm> // ensure std::clamp

// add file-scope animation state
static sf::Clock go_animClock;
static float go_alpha = 0.f;                 // 0..255
static bool go_animating = false;
static float go_duration = 1.0f;             // seconds for fade-in

// helper to update animation alpha (called each frame)
static void update_go_alpha()
{
	if (go_animating)
	{
		float elapsed = go_animClock.getElapsedTime().asSeconds();
		float t = elapsed / go_duration;
		if (t >= 1.f)
		{
			t = 1.f;
			go_animating = false;
		}
		go_alpha = t * 255.f;
	}
}

GameOver::GameOver(unsigned int width, unsigned int height) :                                                             
GameOverText(font),                                                              
PlayAgainText(font),                                                              
HomeText(font),                                                              
sound(buffer),
backgroundTexture(new sf::Texture(sf::Texture()))
{
    LoadFont(font, "../assets/Medieval-timeline-font/MedievalTimeline-DOPRE.ttf");

    LoadBackground();

    setWidth(width);
    setHeight(height);

    GameOverText.setString("Game Over");
    GameOverText.setCharacterSize(100);
    GameOverText.setFillColor(sf::Color::Red);
    GameOverText.setOutlineThickness(5);
    GameOverText.setOutlineColor(sf::Color::Black);
    GameOverText.setPosition({getWidth() / 2 - 610, 120});

    PlayAgainText.setString("Play Again");
    PlayAgainText.setOutlineThickness(5);
    PlayAgainText.setOutlineColor(sf::Color::Black);
    PlayAgainButton.setSize({240, 58});
    PlayAgainButton.setOrigin(PlayAgainButton.getSize() / 2.f);
    PlayAgainButton.setPosition({getWidth() / 2 - 360, 360});
    PlayAgainButton.setFillColor(sf::Color::Transparent);
    PlayAgainButton.setOutlineThickness(1);
    PlayAgainButton.setOutlineColor(sf::Color::Red);

    HomeText.setString("Home");
    HomeText.setOutlineThickness(5);
    HomeText.setOutlineColor(sf::Color::Black);
    HomeButton.setSize({120, 49});
    HomeButton.setOrigin(HomeButton.getSize() / 2.f);
    HomeButton.setPosition({getWidth() / 2 - 360, 450});
    HomeButton.setFillColor(sf::Color::Transparent);
    HomeButton.setOutlineThickness(1);
    HomeButton.setOutlineColor(sf::Color::Red);
}

GameOver::~GameOver()
{
}

void GameOver::processEvents(sf::RenderWindow &window)
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}

void GameOver::render(sf::RenderWindow &window)
{
    window.setFramerateLimit(60);
    window.clear();

    // update animation alpha
    update_go_alpha();

    // if not animating, ensure alpha reflects active state
    if (!go_animating)
    {
        if (isActive) go_alpha = 255.f;
        else go_alpha = 0.f;
    }

    // draw background with current alpha
    drawBackground(window);

    // apply alpha to texts and buttons before drawing (preserve RGB from hover/default)
    unsigned char a = static_cast<unsigned char>(std::clamp(go_alpha, 0.f, 255.f));

    {
        sf::Color c = GameOverText.getFillColor();
        sf::Color o = GameOverText.getOutlineColor();
        GameOverText.setFillColor(sf::Color(c.r, c.g, c.b, a));
        GameOverText.setOutlineColor(sf::Color(o.r, o.g, o.b, a));
    }
    {
        sf::Color c = PlayAgainText.getFillColor();
        sf::Color o = PlayAgainText.getOutlineColor();
        PlayAgainText.setFillColor(sf::Color(c.r, c.g, c.b, a));
        PlayAgainText.setOutlineColor(sf::Color(o.r, o.g, o.b, a));
    }
    {
        sf::Color c = HomeText.getFillColor();
        sf::Color o = HomeText.getOutlineColor();
        HomeText.setFillColor(sf::Color(c.r, c.g, c.b, a));
        HomeText.setOutlineColor(sf::Color(o.r, o.g, o.b, a));
    }
    {
        sf::Color c = PlayAgainButton.getFillColor();
        sf::Color o = PlayAgainButton.getOutlineColor();
        PlayAgainButton.setFillColor(sf::Color(c.r, c.g, c.b, a));
        PlayAgainButton.setOutlineColor(sf::Color(o.r, o.g, o.b, a));
    }
    {
        sf::Color c = HomeButton.getFillColor();
        sf::Color o = HomeButton.getOutlineColor();
        HomeButton.setFillColor(sf::Color(c.r, c.g, c.b, a));
        HomeButton.setOutlineColor(sf::Color(o.r, o.g, o.b, a));
    }

    // draw UI
    window.draw(GameOverText);
    window.draw(PlayAgainText);
    //window.draw(PlayAgainButton);
    window.draw(HomeText);
    //window.draw(HomeButton);

    window.display();
}


// modify drawBackground to apply current alpha
void GameOver::drawBackground(sf::RenderWindow &window)
{
    sf::Sprite backgroundSprite(*backgroundTexture);
    backgroundSprite.setScale(
        {float(width) / backgroundTexture->getSize().x,
         float(height) / backgroundTexture->getSize().y}
    );

    unsigned char a = static_cast<unsigned char>(std::clamp(go_alpha, 0.f, 255.f));
    backgroundSprite.setColor(sf::Color(255,255,255,a));
    window.draw(backgroundSprite);
}

void GameOver::LoadFont(sf::Font &font, string std)
{
    if (!font.openFromFile(std))
    {
        cerr << endl << "ERROR";
    }
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
    PlayAgainText.setFillColor(sf::Color::Red);
    PlayAgainText.setPosition({getWidth() / 2 - 125 - 360, 330});
}
void GameOver::HoverPlayAgain()
{
    PlayAgainText.setCharacterSize(55);
    PlayAgainText.setFillColor(sf::Color::Yellow);
    PlayAgainText.setPosition({getWidth() / 2 - 135 - 360, 326});
}

void GameOver::DefaultHome()
{
    HomeText.setCharacterSize(50);
    HomeText.setFillColor(sf::Color::Red);
    HomeText.setPosition({getWidth() / 2 - 62 - 360 , 420});
}

void GameOver::HoverHome()
{
    HomeText.setCharacterSize(55);
    HomeText.setFillColor(sf::Color::Yellow);
    HomeText.setPosition({getWidth() / 2 - 66 - 360, 416});
}

sf::RectangleShape GameOver::getPlayAgainButton()
{
    return PlayAgainButton;
}

sf::RectangleShape GameOver::getHomeButton()
{
    return HomeButton;
}

bool GameOver::getIsActive()
{
    return isActive;
}
void GameOver::setIsActive(bool isActive)
{
    this->isActive = isActive;

    if (isActive)
    {
        // start fade-in animation
        go_animClock.restart();
        go_animating = true;
        go_alpha = 0.f;
    }
    else
    {
        // hide immediately
        go_animating = false;
        go_alpha = 0.f;
    }
}

void GameOver::setWidth(unsigned int width)
{
    this->width = width;
}
void GameOver::setHeight(unsigned int height)
{
    this->height = height;
}

float GameOver::getWidth()
{
    return width;
}
float GameOver::getHeight()
{
    return height;
}