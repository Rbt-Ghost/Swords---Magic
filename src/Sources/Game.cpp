#include "..\src\Headers\Game.hpp"

static sf::Clock atkClock;
static int k = 0;
static bool previousKeyState = false;
static bool gameOverMusicPlayed = false; // track if GameOver sound has been started

Game::Game(unsigned int width, unsigned int height) : 
window(new sf::RenderWindow(sf::VideoMode({width, height}), "Swords & Magic")),
homeScreen(new HomeScreen(width, height)),
howToPlayScreen(new HowToPlayScreen(width, height)),                                                      
creditsScreen(new CreditsScreen(width, height)),                                                      
aboutScreen(new AboutScreen(width, height)),                                                      
gameOverScreen(new GameOverScreen(width, height)),                                                      
player(new Player("Hero", 100, 1, 2.15f)),                                                      
gameRoom(new GameRoom()),                                                      
score(new Score()),                                                      
sound(buffer),                                                      
pauseText(font)
{
    setW(width);
    setH(height);

    if(!icon.loadFromFile("../assets/Game-Icon.png"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD ICON IMAGE" << std::endl;
    }
    window->setIcon(icon);

    for (int i = 0; i < 2; i++)
    {
        FlyDemon[i] = new FlyingDemon("Flying Demon", 5, 4, 1.85f);
        FlyDemon[i]->spawn(*player);
    }

    for (int i = 0; i < 3; i++)
    {
        skeleton[i] = new Skeleton("Skeleton Warrior", 7, 2, 1.75f);
        skeleton[i]->spawn();
    }

    if (!font.openFromFile("../assets/Medieval-timeline-font/MedievalTimeline-DOPRE.ttf"))
    {
        std::cerr << "ERROR :: COULD NOT LOAD FONT" << std::endl;
    }
    pauseText.setString("Game is Paused");
    pauseText.setCharacterSize(75);
    pauseText.setFillColor(sf::Color::Yellow);
    pauseText.setPosition({(float)getW() / 2 - 270, (float)getH() / 2 - 50});
    pauseText.setOutlineThickness(5);
    pauseText.setOutlineColor(sf::Color::Black);

    pauseBackground.setSize({(float)getW(), (float)getH()});
    pauseBackground.setFillColor(sf::Color(10, 10, 10, 200));
}

Game::~Game()
{
    delete window;
    delete homeScreen;
    delete howToPlayScreen;
    delete creditsScreen;
    delete aboutScreen;
    delete gameOverScreen;
    delete player;
    for (int i = 0; i < 2; ++i)
        delete FlyDemon[i];
    for (int i = 0; i < 3; ++i)
        delete skeleton[i];
    delete gameRoom;
    delete score;
}

void Game::run()
{
    while (window->isOpen())
    {
        if (homeScreen->getIsActive())
        {
            gameOverMusicPlayed = false; 
            PlayMusic("..//assets//Sounds//BackgroundMusic//medieval-ambient-236809.mp3");
            homeScreen->processEvents(*window);
            homeScreen->render(*window);
            if (window->hasFocus())
                Home_handlePlayerInput();
        }
        else if (howToPlayScreen->getIsActive())
        {
            PlayMusic("..//assets//Sounds//BackgroundMusic//medieval-ambient-236809.mp3");
            howToPlayScreen->processEvents(*window);
            howToPlayScreen->render(*window);
            if (window->hasFocus())
                Home_handlePlayerInput();
        }
        else if (creditsScreen->getIsActive())
        {
            PlayMusic("..//assets//Sounds//BackgroundMusic//medieval-ambient-236809.mp3");
            creditsScreen->processEvents(*window);
            creditsScreen->render(*window);
            if (window->hasFocus())
                Home_handlePlayerInput();
        }
        else if (aboutScreen->getIsActive())
        {
            PlayMusic("..//assets//Sounds//BackgroundMusic//medieval-ambient-236809.mp3");
            aboutScreen->processEvents(*window);
            aboutScreen->render(*window);
            if (window->hasFocus())
                Home_handlePlayerInput();
        }
        else if (gameOverScreen->getIsActive())
        {
            // only start the GameOver sound once when entering the GameOver state
            if (!gameOverMusicPlayed)
            {
                backgroundMusic.stop();
                PlayMusic("..//assets//Sounds//UI//GameOver.mp3");
                gameOverMusicPlayed = true;
            }
            gameOverScreen->processEvents(*window);
            gameOverScreen->render(*window);
            if (window->hasFocus())
                GameOver_handlePlayerInput();
        }
        else
        {
            gameOverMusicPlayed = false;
            PlayMusic("..//assets//Sounds//BackgroundMusic//Swords&MagicSoundTrack.mp3");
            processEvents();
            update();
            render();
        }
    }
}

void Game::processEvents()
{
    while (const std::optional event = window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window->close();
    }

    if (window->hasFocus())
        handlePlayerInput();

    if (!isGamePaused)
    {
        for (int i = 0; i < 2; i++)
        {
            FlyDemon[i]->updateLogic(*player);
        }

        for (int i = 0; i < 3; i++)
        {
            skeleton[i]->updateLogic(*player);
        }
    }

    if (player->get_isDead() && player->get_Sprite().getPosition().x == -1000 && player->get_Sprite().getPosition().y == -1000)
    {
        resetGame();
    }
}

void Game::update()
{
    if (isGamePaused || gameOverScreen->getIsActive())
    {
        player->get_Sound().pause();
        for (int i = 0; i < 2; i++)
            FlyDemon[i]->get_Sound().pause();
        for (int i = 0; i < 3; i++)
            skeleton[i]->get_Sound().pause();
        return;
    }
    player->updatePhysics();
    player->updateAnimation();
    player->KnightSounds();

    for (int i = 0; i < 2; i++)
    {
        FlyDemon[i]->updateAnimation();
        FlyDemon[i]->FlyingDemonSounds();
        score->updateFlyingDemon(*FlyDemon[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        skeleton[i]->updateAnimation();
        skeleton[i]->SkeletonSounds();
        score->updateSkeleton(*skeleton[i]);
    }
    score->update(*player);
}

void Game::render()
{
    window->setFramerateLimit(60);

    window->clear();
    for (int i = 0; i < 2; i++)
        gameRoom->draw(*window, *player, *FlyDemon[i]);

    for (int i = 0; i < 2; i++)
    {
        window->draw(FlyDemon[i]->get_Sprite());
        //window->draw(FlyDemon[i]->get_Hitbox());
    }

    for (int i = 0; i < 2; i++)
    {
        if (FlyDemon[i]->get_Fireball())
        {
            window->draw(FlyDemon[i]->get_FireballSprite());
            //window->draw(FlyDemon[i]->get_fireballHitbox());
        }
    }

    for (int i = 0; i < 3; i++)
    {
        window->draw(skeleton[i]->get_Sprite());
        //window->draw(skeleton[i]->get_Hitbox());
    }

    window->draw(player->get_Sprite());
    if (player->getHp() != 0)
    {
        window->draw(player->get_Hp_Bar());
    }
    //window->draw(player->get_Hitbox());

    if (isGamePaused)
    {
        window->draw(pauseBackground);
        window->draw(pauseText);
    }

    score->draw(*window);

    window->display();
}

void Game::handlePlayerInput()
{
    currentPauseKeyState = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::P);

    if (currentPauseKeyState && !previousKeyState)
    {
        isGamePaused = !isGamePaused;
    }
    previousKeyState = currentPauseKeyState;

    if (!isGamePaused)
    {
        if (!player->get_isHurt() && !player->get_isDead())
        {
            player->playerAttack();

            player->playerDefend();

            if (player->get_isAttacking1() || player->get_isAttacking2() || player->get_isAttacking3() || player->get_isDefending())
            {
                player->set_isMovingL(false);
                player->set_isMovingR(false);
                player->set_isRunning(false);
                return;
            }
            else
            {
                player->get_Hitbox().setSize({27.5f, 55.f});
                player->get_Hitbox().setOrigin({player->get_Hitbox().getSize().x / 2, player->get_Hitbox().getSize().y / 2  - 7.5f});
            }

            player->playerMoveR();
            player->playerMoveL();

            player->playerJump();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
            {
                player->set_isMovingR(false);
                player->set_isMovingL(false);
                player->set_isRunning(false);
            }
        }
    }
}


void Game::Home_handlePlayerInput()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    if (window->getSize().x > 1440 || window->getSize().y > 800)
    {
        mousePos.x = mousePos.x / float(window->getSize().x) * 1440.f;
        mousePos.y = mousePos.y / float(window->getSize().y) * 800.f;
    }

    if (homeScreen->getIsActive())
    {
        bool isHoverStart = homeScreen->getStartButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
        if (isHoverStart)
        {
            if (!wasHoverStart)
                PlaySound("..//assets//Sounds//UI//minimalist-button-hover-sound-effect-399749.mp3");
            homeScreen->HoverStart();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                homeScreen->setIsActive(false);

                if (gameOverScreen->getIsActive())
                    gameOverScreen->setIsActive(false);
                backgroundMusic.stop();

                sf::sleep(sf::milliseconds(100));

                player->respawn();

                for (int i = 0; i < 2; ++i)
                    FlyDemon[i]->spawn(*player);
                for (int i = 0; i < 3; ++i)
                    skeleton[i]->spawn();

                score->loadBestScore();
            }
        }
        else
        {
            homeScreen->DefaultStart();
        }
        wasHoverStart = isHoverStart;

        bool isHoverHowToPlay = homeScreen->getHowToPlayButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
        if (isHoverHowToPlay)
        {
            if (!wasHoverHowToPlay)
                PlaySound("..//assets//Sounds//UI//minimalist-button-hover-sound-effect-399749.mp3");
            homeScreen->HoverHowToPlay();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                howToPlayScreen->setIsActive(true);
                homeScreen->setIsActive(false);
                sf::sleep(sf::milliseconds(100));
            }
        }
        else
        {
            homeScreen->DefaultHowToPlay();
        }
        wasHoverHowToPlay = isHoverHowToPlay;

        bool isHoverCredits = homeScreen->getCreditsButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
        if (isHoverCredits)
        {
            if (!wasHoverCredits)
                PlaySound("..//assets//Sounds//UI//minimalist-button-hover-sound-effect-399749.mp3");
            homeScreen->HoverCredits();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                creditsScreen->setIsActive(true);
                homeScreen->setIsActive(false);
                sf::sleep(sf::milliseconds(100));
            }
        }
        else
        {
            homeScreen->DefaultCredits();
        }
        wasHoverCredits = isHoverCredits;

        bool isHoverAbout = homeScreen->getAboutButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
        if (isHoverAbout)
        {
            if (!wasHoverAbout)
                PlaySound("..//assets//Sounds//UI//minimalist-button-hover-sound-effect-399749.mp3");
            homeScreen->HoverAbout();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                aboutScreen->setIsActive(true);
                homeScreen->setIsActive(false);
                sf::sleep(sf::milliseconds(100));
            }
        }
        else
        {
            homeScreen->DefaultAbout();
        }
        wasHoverAbout = isHoverAbout;

        bool isHoverQuit = homeScreen->getQuitButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
        if (isHoverQuit)
        {
            if (!wasHoverQuit)
                PlaySound("..//assets//Sounds//UI//minimalist-button-hover-sound-effect-399749.mp3");
            homeScreen->HoverQuit();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                backgroundMusic.stop();
                window->close();
                sf::sleep(sf::milliseconds(100));
            }
        }
        else
        {
            homeScreen->DefaultQuit();
        }
        wasHoverQuit = isHoverQuit;
    }

    if (howToPlayScreen->getIsActive())
    {

        if (howToPlayScreen->getBackButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        {
            if (k == 1)
                PlaySound("..//assets//Sounds//UI//minimalist-button-hover-sound-effect-399749.mp3");
            k++;
            howToPlayScreen->HoverBack();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                howToPlayScreen->setIsActive(false);
                homeScreen->setIsActive(true);
                sf::sleep(sf::milliseconds(250));
            }
        }
        else
        {
            howToPlayScreen->DefaultBack();
            k = 0;
        }
    }

    if (creditsScreen->getIsActive())
    {

        if (creditsScreen->getBackButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        {
            if (k == 1)
                PlaySound("..//assets//Sounds//UI//minimalist-button-hover-sound-effect-399749.mp3");
            k++;
            creditsScreen->HoverBack();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                creditsScreen->setIsActive(false);
                homeScreen->setIsActive(true);
                sf::sleep(sf::milliseconds(250));
            }
        }
        else
        {
            creditsScreen->DefaultBack();
            k = 0;
        }
    }

    if (aboutScreen->getIsActive())
    {

        if (aboutScreen->getBackButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        {
            if (k == 1)
                PlaySound("..//assets//Sounds//UI//minimalist-button-hover-sound-effect-399749.mp3");
            k++;
            aboutScreen->HoverBack();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                aboutScreen->setIsActive(false);
                homeScreen->setIsActive(true);
                sf::sleep(sf::milliseconds(250));
            }
        }
        else
        {
            aboutScreen->DefaultBack();
            k = 0;
        }
    }
}

void Game::GameOver_handlePlayerInput()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

    if (window->getSize().x > 1440 || window->getSize().y > 800)
    {
        mousePos.x = mousePos.x / float(window->getSize().x) * 1440.f;
        mousePos.y = mousePos.y / float(window->getSize().y) * 800.f;
    }

    if (gameOverScreen->getIsActive())
    {
        bool isHoverPlayAgain = gameOverScreen->getPlayAgainButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
        if (isHoverPlayAgain)
        {
            if (!wasHoverPlayAgain)
                PlaySound("..//assets//Sounds//UI//minimalist-button-hover-sound-effect-399749.mp3");
            gameOverScreen->HoverPlayAgain();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                gameOverScreen->setIsActive(false);
                backgroundMusic.stop();
                sf::sleep(sf::milliseconds(100));

                restartFromGameOver();
            }
        }
        else
        {
            gameOverScreen->DefaultPlayAgain();
        }
        wasHoverPlayAgain = isHoverPlayAgain;

        bool isHoverHome = gameOverScreen->getHomeButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
        if (isHoverHome)
        {
            if (!wasHoverHome)
                PlaySound("..//assets//Sounds//UI//minimalist-button-hover-sound-effect-399749.mp3");
            gameOverScreen->HoverHome();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                gameOverScreen->setIsActive(false);
                homeScreen->setIsActive(true);
                backgroundMusic.stop();
                sf::sleep(sf::milliseconds(100));
            }
        }
        else
        {
            gameOverScreen->DefaultHome();
        }
        wasHoverHome = isHoverHome;
    }
}

void Game::resetGame()
{
    score->saveBestScore();
    score->loadBestScore();
    gameOverScreen->setIsActive(true);
    backgroundMusic.stop();
}

void Game::restartFromGameOver()
{
    player->respawn();

    for (int i = 0; i < 2; i++)
    {
        FlyDemon[i]->spawn(*player);
    }
    for (int i = 0; i < 3; i++)
    {
        skeleton[i]->spawn();
    }

    gameOverScreen->setIsActive(false);
    score->loadBestScore();
}

void Game::PlayMusic(const std::filesystem::path &filename)
{
    if (backgroundMusic.getStatus() != sf::Music::Status::Playing)
    {
        if (backgroundMusic.openFromFile(filename.string()))
        {
            backgroundMusic.play();
        }
        else
        {
            std::cerr << "Failed to load music: " << filename << std::endl;
        }
    }
}
void Game::PlaySound(const std::filesystem::path &filename)
{
    if (!buffer.loadFromFile(filename.string()))
        cerr << endl
             << "Error at loaading sound file!";

    sound.setBuffer(buffer);
    sound.play();
}

void Game::setW(unsigned int width)
{
    this->width = width;
}
void Game::setH(unsigned int height)
{
    this->height = height;
}

unsigned int Game::getW()
{
    return width;
}
unsigned int Game::getH()
{
    return height;
}