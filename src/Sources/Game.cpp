#include "..\src\Headers\Game.hpp"

    static sf::Clock atkClock;

    Game::Game(unsigned int width, unsigned int height): 
    window(new sf::RenderWindow (sf::VideoMode({width,height}), "Swords & Magic")),
    player(new Player("Hero", 10, 3, 1.5f)),
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
        player->updatePhysics();
        player->updateAnimation();
    }
    
    void Game::render()
    {
        window->setFramerateLimit(60);
        sf::Sprite background(*texture);
        background.setScale({(float)window->getSize().x / (float)texture->getSize().x,
                    (float)window->getSize().y / (float)texture->getSize().y});

        window->clear();
        window->draw(background);
        window->draw(player->get_Sprite());
        
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
            }
            else if (!player->get_isAttacking1() && !player->get_isAttacking3())
            {
                player->set_isAttacking2(true);
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
        }


       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::K))
        {
            player->set_isDefending(true);
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