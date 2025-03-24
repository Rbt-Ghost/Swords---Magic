#include "..\src\Headers\Game.hpp"

static sf::Clock atkClock;

Game::Game(unsigned int width, unsigned int height) : 
window(new sf::RenderWindow(sf::VideoMode({width, height}), "Swords & Magic")),
player(new Player("Hero", 100, 1, 1.75f)),
gameRoom(new GameRoom()),
score(new Score()),
texture(new sf::Texture(sf::Texture()))
{
    setW(width);
    setH(height);

    if (!texture->loadFromFile("../assets/Mokazar - Medieval Castle Background.jpg"))
    {
        cerr << "ERROR :: COULD NOT LOAD IDLE SPRITE " << endl;
    }

    for (int i = 0; i < 2; i ++)
    {
        FlyDemon[i] = new FlyingDemon("Flying Demon", 7, 2, 1.85f);
        FlyDemon[i]->spawn(*player);
    }

    for (int i = 0; i < 3; i ++)
    {
        skeleton[i] = new Skeleton("Skeleton Warrior", 10,1,1.5);
        skeleton[i]->spawn();
    }
}

Game::~Game()
{
    delete window;
    delete texture;
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
        processEvents();
        update();
        render();
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

    for (int i = 0; i < 2; i ++)
    {
        FlyDemon[i]->FlyingDemonLogic(*player);
    }

    for (int i =0; i < 3; i++)
    {
        skeleton[i]->SkeletonLogic(*player);
    }
}

void Game::update()
{
    player->updatePhysics();
    player->updateAnimation();

    for (int i = 0; i < 2; i ++)
    {
        FlyDemon[i]->updateAnimation();
        score->updateFlyingDemon(*FlyDemon[i]);
    }
    
    for (int i =0; i < 3; i++)
    {
        skeleton[i]->updateAnimation();
        score->updateSkeleton(*skeleton[i]);
    }
    score->update(*player);
}

void Game::render()
{
    window->setFramerateLimit(60);
    sf::Sprite background(*texture);
    background.setScale({(float)window->getSize().x / (float)texture->getSize().x,
                         (float)window->getSize().y / (float)texture->getSize().y});

    window->clear();
    //window->draw(background);
    for (int i = 0; i < 2; i++)
        gameRoom->draw(*window,*player,*FlyDemon[i]);

    for (int i = 0; i < 2; i ++)
    {
        window->draw(FlyDemon[i]->get_Sprite());
        //window->draw(FlyDemon[i]->get_hitbox());
    }
    
    for (int i = 0; i < 2; i ++)
    {
        if (FlyDemon[i]->get_Fireball())
        {
            window->draw(FlyDemon[i]->get_FireballSprite());
            //window->draw(FlyDemon[i]->get_fireballHitbox());
        }
    }
    
    for (int i =0; i < 3; i++)
    {
        window->draw(skeleton[i]->get_Sprite());
        //window->draw(skeleton[i]->get_hitbox());
    }

    window->draw(player->get_Sprite());
    window->draw(player->get_Hp_Bar());
    //window->draw(player->get_Hitbox());
    
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

        for (int i = 0; i < 4; i ++)
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