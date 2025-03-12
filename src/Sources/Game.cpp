#include "..\src\Headers\Game.hpp"

    static sf::Clock atkClock;

    Game::Game(unsigned int width, unsigned int height): 
    window(new sf::RenderWindow (sf::VideoMode({width,height}), "Swords & Magic")),
    player(new Player("Hero", 30, 1, 1.5f)),
    FlyDemon(new FlyingDemon("Flying Demon", 10, 1, 1.85f)),
    texture(new sf::Texture (sf::Texture()))
    {
        setW(width);
        setH(height);

        if (!texture->loadFromFile("../assets/Mokazar - Medieval Castle Background.jpg"))
        {
            cerr << "ERROR :: COULD NOT LOAD IDLE SPRITE " << endl;
        }
    }

    Game::~Game() 
    { 
        delete window;
        delete player;
        delete FlyDemon;
        delete texture;
    }
    
    void Game::run()
    {
        while ( window->isOpen())
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
    }
    
    void Game::update()
    {
        handlePlayerInput();
        enemyLogic();
        player->updatePhysics();
        player->updateAnimation();
        FlyDemon->updateAnimation();
    }
    
    void Game::render()
    {
        window->setFramerateLimit(60);
        sf::Sprite background(*texture);
        background.setScale({(float)window->getSize().x / (float)texture->getSize().x,
                    (float)window->getSize().y / (float)texture->getSize().y});

        window->clear();
        window->draw(background);
        window->draw(FlyDemon->get_Sprite());
        window->draw(FlyDemon->get_hitbox());
        window->draw(player->get_Sprite());
        window->draw(player->get_Hitbox());
        
        window->display();
    }


    void Game::handlePlayerInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape))
        {
            window->close();
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::J)) // daca vrei un lucru bun faacut fa-l cu mana ta
        {
            if (!player->get_isAttacking2() && !player->get_isAttacking3())
            {
                player->set_isAttacking1(true);
                if (checkAtk1)
                {
                    player->set_currentFrame(0);
                    checkAtk1 = false;
                }
                player->get_Hitbox().setSize({80.f,70.f});
                player->get_Hitbox().setOrigin({player->get_Hitbox().getSize().x/2, player->get_Hitbox().getSize().y/2});
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
            FlyDemon->set_isHurt(false);
        }

       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::K))
        {
            if (!player->get_isDefending())
            {
                player->set_isDefending(true);
                player->get_Hitbox().setSize({50.f,70.f});
                player->get_Hitbox().setOrigin({player->get_Hitbox().getSize().x/2, player->get_Hitbox().getSize().y/2});
            }
        }
        else
        {
            player->set_isDefending(false);
        }

        
        if (player->get_isAttacking1() || player->get_isAttacking2() || player->get_isAttacking3() || player->get_isDefending())
        {
            player->set_isMovingL(false);
            player->set_isMovingR(false);
            player->set_isRunning(false);
            return;
        }
        else
        {
            player->get_Hitbox().setSize({40.f,70.f});
            player->get_Hitbox().setOrigin({player->get_Hitbox().getSize().x/2, player->get_Hitbox().getSize().y/2});
        }

        
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
        {
            if (!player->get_isJumping()) 
                player->jump();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
        {
            player->set_isDead(true);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
        {
            player->set_isMovingR(false);
            player->set_isMovingL(false);
            player->set_isRunning(false);
        }
    }


    bool Game::checkCollisions()
    {
        if (player->get_Hitbox().getGlobalBounds().findIntersection(FlyDemon->get_hitbox().getGlobalBounds()))
            return true;
        else return false;
    }


    void Game::enemyLogic()
    {
        if (playerLeft())
            FlyDemon->get_Sprite().setScale(sf::Vector2f(1.8f,1.8f));
        else if (playerRight())
            FlyDemon->get_Sprite().setScale(sf::Vector2f(-1.8f,1.8f));


        if (checkCollisions())
        {
            if (FlyDemon->getHp() > 0 && player->get_isAttacking1())
            {
                FlyDemon->set_isHurt(true);

                if (player->get_currentFrame() == 4 && clock.getElapsedTime().asSeconds() > 0.4f)
                {    
                    FlyDemon->set_CurrentFrame(0);

                    *FlyDemon-=player->getAtk();
                    FlyDemon->checkHp();

                    if (!FlyDemon->get_isDead())
                        FlyDemon->escape();

                    clock.restart();
                }
            }
            
            if (FlyDemon->getHp() > 0 && player->get_isAttacking2())
            {
                FlyDemon->set_isHurt(true);

                if (player->get_currentFrame() == 1 && clock.getElapsedTime().asSeconds() > 0.1f)
                {    
                    FlyDemon->set_CurrentFrame(0);

                    *FlyDemon-=player->getAtk();
                    FlyDemon->checkHp();

                    if (!FlyDemon->get_isDead())
                        FlyDemon->escape();
                    
                    clock.restart();
                }
            }

            if (FlyDemon->getHp() > 0 && player->get_isAttacking3())
            {
                FlyDemon->set_isHurt(true);

                if (player->get_currentFrame() == 3 && clock.getElapsedTime().asSeconds() > 0.3f)
                {
                    FlyDemon->set_CurrentFrame(0);

                    *FlyDemon-=player->getAtk();

                    if (FlyDemon->getHp() != 0)
                    {
                        if (playerLeft())
                        {
                            FlyDemon->move( 60.f, 0.f);
                        }
                        if (playerRight())
                        {
                            FlyDemon->move( -60.f, 0.f);
                        }
                    }

                    FlyDemon->checkHp();

                    clock.restart();
                }
            }
        }
        else if (FlyDemon->get_isHurt() && FlyDemon->get_CurrentFrame() > 3)
            FlyDemon->set_isHurt(false);

        if ( FlyDemon->get_isFlying() && distance() < 400 )
        {   
            if (playerLeft())
            {
                FlyDemon->move(FlyDemon->getSpeed(),-FlyDemon->getSpeed());
            }
            if (playerRight())
            {
                FlyDemon->move(-FlyDemon->getSpeed(),-FlyDemon->getSpeed());
            }
        }
        else
        {
            FlyDemon->set_isFlying(false);
        }

        if (FlyDemon->get_isAttacking() && FlyDemon->get_CurrentFrame() >= 7)
        {
            FlyDemon->set_isAttacking(false);
        }
        if (FlyDemon->get_isFlying() || FlyDemon->get_isIdle() && clock.getElapsedTime().asSeconds() > 3.0f)
        {
            FlyDemon->ifAttack();
            FlyDemon->set_CurrentFrame(0);
            clock.restart();
        }
    }


    float Game::distance()
    {
        return sqrt (pow ( player->get_xPos()-FlyDemon->get_xPos(), 2) + pow ( player->get_yPos()-FlyDemon->get_yPos(), 2));
    }


    bool Game::playerLeft()
    {
        return (player->get_xPos() - FlyDemon->get_xPos() < 0);
    }
    bool Game::playerRight()
    {
        return (player->get_xPos() - FlyDemon->get_xPos() > 0);
    }


    void Game::setW(unsigned int width)
    {
        this->width=width;
    }
    void Game::setH(unsigned int height)
    {
        this->height=height;
    }

    unsigned int Game::getW()
    {
        return width;
    }
    unsigned int Game::getH()
    {
        return height;
    }