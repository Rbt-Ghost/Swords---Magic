#include "..\src\Headers\Game.hpp"

static sf::Clock atkClock;
static int k = 0;

Game::Game(unsigned int width, unsigned int height) : window(new sf::RenderWindow(sf::VideoMode({width, height}), "Swords & Magic")),
                                                      homeScreen(new HomeScreen(width, height)),
                                                      howToPlayScreen(new HowToPlayScreen(width, height)),
                                                      creditsScreen(new CreditsScreen(width, height)),
                                                      aboutScreen(new AboutScreen(width, height)),
                                                      player(new Player("Hero", 100, 1, 2.25f)),
                                                      gameRoom(new GameRoom()),
                                                      score(new Score()),
                                                      sound(buffer)
{
    setW(width);
    setH(height);

    for (int i = 0; i < 2; i++)
    {
        FlyDemon[i] = new FlyingDemon("Flying Demon", 7, 3, 1.85f);
        FlyDemon[i]->spawn(*player);
    }

    for (int i = 0; i < 3; i++)
    {
        skeleton[i] = new Skeleton("Skeleton Warrior", 10, 2, 1.5);
        skeleton[i]->spawn();
    }
}

Game::~Game()
{
    delete window;
    delete homeScreen;
    delete howToPlayScreen;
    delete creditsScreen;
    delete aboutScreen;
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
            PlayMusic("..//assets//Sounds//medieval-ambient-236809.mp3");
            homeScreen->processEvents(*window);
            homeScreen->render(*window);
            Home_handlePlayerInput();
        }
        else if (howToPlayScreen->getIsActive())
        {
            PlayMusic("..//assets//Sounds//medieval-ambient-236809.mp3");
            homeScreen->processEvents(*window);
            howToPlayScreen->render(*window);
            Home_handlePlayerInput();
        }
        else if (creditsScreen->getIsActive())
        {
            PlayMusic("..//assets//Sounds//medieval-ambient-236809.mp3");
            homeScreen->processEvents(*window);
            creditsScreen->render(*window);
            Home_handlePlayerInput();
        }
        else if (aboutScreen->getIsActive())
        {
            PlayMusic("..//assets//Sounds//medieval-ambient-236809.mp3");
            homeScreen->processEvents(*window);
            aboutScreen->render(*window);
            Home_handlePlayerInput();
        }
        else
        {
            PlayMusic("..//assets//Sounds//Swords&MagicSoundTrack.mp3");
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

    handlePlayerInput();

    for (int i = 0; i < 2; i++)
    {
        FlyDemon[i]->updateLogic(*player);
    }

    for (int i = 0; i < 3; i++)
    {
        skeleton[i]->updateLogic(*player);
    }
}

void Game::update()
{
    player->updatePhysics();
    player->updateAnimation();

    for (int i = 0; i < 2; i++)
    {
        FlyDemon[i]->updateAnimation();
        score->updateFlyingDemon(*FlyDemon[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        skeleton[i]->updateAnimation();
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
        // window->draw(FlyDemon[i]->get_hitbox());
    }

    for (int i = 0; i < 2; i++)
    {
        if (FlyDemon[i]->get_Fireball())
        {
            window->draw(FlyDemon[i]->get_FireballSprite());
            // window->draw(FlyDemon[i]->get_fireballHitbox());
        }
    }

    for (int i = 0; i < 3; i++)
    {
        window->draw(skeleton[i]->get_Sprite());
        // window->draw(skeleton[i]->get_hitbox());
    }

    window->draw(player->get_Sprite());
    if (player->getHp() != 0)
    {
        window->draw(player->get_Hp_Bar());
    }
    // window->draw(player->get_Hitbox());

    score->draw(*window);

    window->display();
}

void Game::handlePlayerInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape))
    {
        window->close();
    }

    if (!player->get_isHurt() && !player->get_isDead())
    {
        playerAttack();

        playerDefend();

        if (player->get_isAttacking1() || player->get_isAttacking2() || player->get_isAttacking3() || player->get_isDefending())
        {
            player->set_isMovingL(false);
            player->set_isMovingR(false);
            player->set_isRunning(false);
            return;
        }
        else
        {
            player->get_Hitbox().setSize({40.f, 70.f});
            player->get_Hitbox().setOrigin({player->get_Hitbox().getSize().x / 2, player->get_Hitbox().getSize().y / 2});
        }

        playerMoveR();
        playerMoveL();

        playerJump();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
        {
            player->set_isMovingR(false);
            player->set_isMovingL(false);
            player->set_isRunning(false);
        }
    }

    if (player->get_isDead() && player->get_Sprite().getPosition().x == -1000 && player->get_Sprite().getPosition().y == -1000 && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::R))
    {
        player->respawn();
        score->saveBestScore();
        score->loadBestScore();
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
                PlaySound("..//assets//Sounds//minimalist-button-hover-sound-effect-399749.mp3");
            homeScreen->HoverStart();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                homeScreen->setIsActive(false);
                backgroundMusic.stop();
                sf::sleep(sf::milliseconds(100));
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
                PlaySound("..//assets//Sounds//minimalist-button-hover-sound-effect-399749.mp3");
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
                PlaySound("..//assets//Sounds//minimalist-button-hover-sound-effect-399749.mp3");
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
                PlaySound("..//assets//Sounds//minimalist-button-hover-sound-effect-399749.mp3");
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
                PlaySound("..//assets//Sounds//minimalist-button-hover-sound-effect-399749.mp3");
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
            if( k == 1)
                PlaySound("..//assets//Sounds//minimalist-button-hover-sound-effect-399749.mp3");
            k++;
            howToPlayScreen->HoverBack();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                howToPlayScreen->setIsActive(false);
                homeScreen->setIsActive(true);
                sf::sleep(sf::milliseconds(100));
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
        if ( creditsScreen->getBackButton().getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
        {
            if (k == 1)
                PlaySound("..//assets//Sounds//minimalist-button-hover-sound-effect-399749.mp3");
            k++;            
            creditsScreen->HoverBack();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                creditsScreen->setIsActive(false);
                homeScreen->setIsActive(true);
                sf::sleep(sf::milliseconds(100));
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
                PlaySound("..//assets//Sounds//minimalist-button-hover-sound-effect-399749.mp3");
            k++;
            aboutScreen->HoverBack();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                aboutScreen->setIsActive(false);
                homeScreen->setIsActive(true);
                sf::sleep(sf::milliseconds(100));
            }
        }
        else
        {
            aboutScreen->DefaultBack();
            k = 0;
        }
    }
}

void Game::playerAttack()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::J))
    {
        if (!player->get_isAttacking2() && !player->get_isAttacking3())
        {
            player->set_isAttacking1(true);
            if (checkAtk1)
            {
                player->set_currentFrame(0);
                checkAtk1 = false;
            }
            player->get_Hitbox().setSize({80.f, 70.f});
            player->get_Hitbox().setOrigin({player->get_Hitbox().getSize().x / 2, player->get_Hitbox().getSize().y / 2});
        }
        else if (!player->get_isAttacking1() && !player->get_isAttacking3())
        {
            player->set_isAttacking2(true);
            checkAtk1 = true;
        }
        else if (!player->get_isAttacking1() && !player->get_isAttacking2())
        {
            player->set_isAttacking3(true);
        }
    }
    else
    {

        player->set_isAttacking1(false);
        player->set_isAttacking2(false);
        player->set_isAttacking3(false);

        for (int i = 0; i < 4; i++)
        {
            FlyDemon[i]->set_isHurt(false);
        }
    }
}

void Game::playerDefend()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::K))
    {
        if (!player->get_isDefending() && !player->get_isHurt() && DefendClock.getElapsedTime().asSeconds() > 1.2f)
        {
            player->set_currentFrame(0);
            player->set_isDefending(true);
            player->get_Hitbox().setSize({45.f, 70.f});
            player->get_Hitbox().setOrigin({player->get_Hitbox().getSize().x / 2, player->get_Hitbox().getSize().y / 2});
            DefendClock.restart();
        }
    }
    if (player->get_currentFrame() == 5)
    {
        player->set_isDefending(false);
    }
}

void Game::playerMoveR()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
    {
        player->get_Sprite().setScale(sf::Vector2f(2.f, 2.f));
        player->set_isMovingR(true);
        player->move(player->getSpeed(), 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::LShift))
        {
            player->set_isMovingR(false);
            player->set_isRunning(true);
            player->move(player->getSpeed() + 0.5f, 0.f);
        }
        else
        {
            player->set_isRunning(false);
        }
    }
    else
    {
        player->set_isMovingR(false);
        player->set_isRunning(false);
    }
}

void Game::playerMoveL()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
    {
        player->get_Sprite().setScale(sf::Vector2f(-2.f, 2.f));
        player->set_isMovingL(true);
        player->move(-player->getSpeed(), 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::LShift))
        {
            player->set_isMovingL(false);
            player->set_isRunning(true);
            player->move(-player->getSpeed() - 0.5f, 0.f);
        }
        else
        {
            player->set_isRunning(false);
        }
    }
    else
    {
        player->set_isMovingL(false);
    }
}

void Game::playerJump()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
    {
        if (!player->get_isJumping())
            player->jump();
    }
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
        cerr<<endl<<"Error at loaading sound file!";
    
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