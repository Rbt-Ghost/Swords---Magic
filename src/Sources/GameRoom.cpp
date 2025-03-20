#include "..\src\Headers\GameRoom.hpp"

GameRoom::GameRoom():
TorchSprite1(TorchTexture),
TorchSprite2(TorchTexture),
TorchSprite3(TorchTexture),
TorchSprite4(TorchTexture),
TorchSprite5(TorchTexture)
{
    if (!topTileTexture.loadFromFile("../assets/Medivel Castle Dungeon 2D Pixel Art/Top.png") ||
        !middleTileTexture.loadFromFile("../assets/Medivel Castle Dungeon 2D Pixel Art/Middle.png") ||
        !bottomTileTexture.loadFromFile("../assets/Medivel Castle Dungeon 2D Pixel Art/Bottom.png") ||
        !KnightStatueTexture.loadFromFile("../assets/Medivel Castle Dungeon 2D Pixel Art/KnightStatue.png") ||
        !PriestStatueTexture.loadFromFile("../assets/Medivel Castle Dungeon 2D Pixel Art/PriestStatue.png") ||
        !TorchTexture.loadFromFile("../assets/Medivel Castle Dungeon 2D Pixel Art/Torch.png") ||
        !FloorTexture.loadFromFile("../assets/Medivel Castle Dungeon 2D Pixel Art/Floor.png"))
    {
        std::cerr << "ROOM TEXTURES LOAD ERROR" << std::endl;
    }

    for(int i = 0; i < 4; i++)
    {
        TorchFrames[i] = sf::IntRect({38 * i, 0}, {38, 68});
    }


    TorchSprite1.setTextureRect(TorchFrames[0]);
    TorchSprite1.setScale(sf::Vector2f(2.f,2.f));
    TorchSprite1.setOrigin({20.125,34});
    TorchSprite1.setPosition({224,300});

    TorchSprite2.setTextureRect(TorchFrames[0]);
    TorchSprite2.setScale(sf::Vector2f(2.f,2.f));
    TorchSprite2.setOrigin({20.125,34});
    TorchSprite2.setPosition({480,300});

    TorchSprite3.setTextureRect(TorchFrames[0]);
    TorchSprite3.setScale(sf::Vector2f(2.f,2.f));
    TorchSprite3.setOrigin({20.125,34});
    TorchSprite3.setPosition({736,300});

    TorchSprite4.setTextureRect(TorchFrames[0]);
    TorchSprite4.setScale(sf::Vector2f(2.f,2.f));
    TorchSprite4.setOrigin({20.125,34});
    TorchSprite4.setPosition({992,300});

    TorchSprite5.setTextureRect(TorchFrames[0]);
    TorchSprite5.setScale(sf::Vector2f(2.f,2.f));
    TorchSprite5.setOrigin({20.125,34});
    TorchSprite5.setPosition({1248,300});

    tiles.resize(ROOM_HEIGHT, std::vector<std::optional<sf::Sprite>>(ROOM_WIDTH));

    for (int row = 0; row < ROOM_HEIGHT; ++row)
    {
        for (int col = 0; col < ROOM_WIDTH; ++col)
        {
            if (row == 0)
            {
                selectedTexture = &topTileTexture;
            }
            else if (row == ROOM_HEIGHT - 1)
            {
                selectedTexture = &bottomTileTexture;
            }
            else
            {
                selectedTexture = &middleTileTexture;
            }

            tiles[row][col].emplace(*selectedTexture);
            tiles[row][col]->setPosition({static_cast<float>(col * TILE_WIDTH), static_cast<float>(row * TILE_HEIGHT)});
            tiles[row][col]->setScale({2, 2});
        }
    }
}

GameRoom::~GameRoom() 
{
    //delete selectedTexture;
}

void GameRoom::draw(sf::RenderWindow &window)
{
    for (int row = 0; row < ROOM_HEIGHT; ++row)
    {
        for (int col = 0; col < ROOM_WIDTH; ++col)
        {
            if (tiles[row][col])
            {
                window.draw(*tiles[row][col]);
            }
        }
    }
    sf::Sprite sprite1(KnightStatueTexture);
    sprite1.setOrigin({26.f, 100.f});
    sprite1.setScale({3.5f, 3.5f});
    sprite1.move({130, 745});
    window.draw(sprite1);

    sf::Sprite sprite2(KnightStatueTexture);
    sprite2.setOrigin({26.f, 100.f});
    sprite2.setScale({3.5f, 3.5f});
    sprite2.move({620, 745});
    window.draw(sprite2);

    sf::Sprite sprite3(KnightStatueTexture);
    sprite3.setOrigin({26.f, 100.f});
    sprite3.setScale({3.5f, 3.5f});
    sprite3.move({1134, 745});
    window.draw(sprite3);

    sf::Sprite sprite4(PriestStatueTexture);
    sprite4.setOrigin({26.f, 100.f});
    sprite4.setScale({3.5f, 3.5f});
    sprite4.move({350, 745});
    window.draw(sprite4);

    sf::Sprite sprite5(PriestStatueTexture);
    sprite5.setOrigin({26.f, 100.f});
    sprite5.setScale({3.5f, 3.5f});
    sprite5.move({864, 745});
    window.draw(sprite5);

    sf::Sprite sprite6(PriestStatueTexture);
    sprite6.setOrigin({26.f, 100.f});
    sprite6.setScale({3.5f, 3.5f});
    sprite6.move({1375, 745});
    window.draw(sprite6);

    sf::Sprite FloorSprite1(FloorTexture);
    FloorSprite1.setOrigin({63.5f, 8.f});
    FloorSprite1.setScale({3.5f, 3.5f});
    FloorSprite1.move({220, 776});
    window.draw(FloorSprite1);

    sf::Sprite FloorSprite2(FloorTexture);
    FloorSprite2.setOrigin({63.5f, 8.f});
    FloorSprite2.setScale({3.5f, 3.5f});
    FloorSprite2.move({660, 776});
    window.draw(FloorSprite2);

    sf::Sprite FloorSprite3(FloorTexture);
    FloorSprite3.setOrigin({63.5f, 8.f});
    FloorSprite3.setScale({3.5f, 3.5f});
    FloorSprite3.move({1100, 776});
    window.draw(FloorSprite3);

    sf::Sprite FloorSprite4(FloorTexture);
    FloorSprite4.setOrigin({63.5f, 8.f});
    FloorSprite4.setScale({3.5f, 3.5f});
    FloorSprite4.move({1540, 776});
    window.draw(FloorSprite4);

    window.draw(TorchSprite1);
    if (AnimationClock1.getElapsedTime().asSeconds() > 0.15f)
    {
        if (CurrentFrame1 >= 4)
            CurrentFrame1 = 0;
        TorchSprite1.setTexture(TorchTexture);
        TorchSprite1.setTextureRect(TorchFrames[CurrentFrame1]);
        CurrentFrame1++;
        AnimationClock1.restart();
    }

    window.draw(TorchSprite2);
    if (AnimationClock2.getElapsedTime().asSeconds() > 0.15f)
    {
        if (CurrentFrame2 >= 4)
            CurrentFrame2 = 0;
        TorchSprite2.setTexture(TorchTexture);
        TorchSprite2.setTextureRect(TorchFrames[CurrentFrame2]);
        CurrentFrame2++;
        AnimationClock2.restart();
    }
    
    window.draw(TorchSprite3);
    if (AnimationClock3.getElapsedTime().asSeconds() > 0.15f)
    {
        if (CurrentFrame3 >= 4)
            CurrentFrame3 = 0;
        TorchSprite3.setTexture(TorchTexture);
        TorchSprite3.setTextureRect(TorchFrames[CurrentFrame3]);
        CurrentFrame3++;
        AnimationClock3.restart();
    }

    window.draw(TorchSprite4);
    if (AnimationClock4.getElapsedTime().asSeconds() > 0.15f)
    {
        if (CurrentFrame4 >= 4)
            CurrentFrame4 = 0;
        TorchSprite4.setTexture(TorchTexture);
        TorchSprite4.setTextureRect(TorchFrames[CurrentFrame4]);
        CurrentFrame4++;
        AnimationClock4.restart();
    }

    window.draw(TorchSprite5);
    if (AnimationClock5.getElapsedTime().asSeconds() > 0.15f)
    {
        if (CurrentFrame5 >= 4)
            CurrentFrame5 = 0;
        TorchSprite5.setTexture(TorchTexture);
        TorchSprite5.setTextureRect(TorchFrames[CurrentFrame5]);
        CurrentFrame5++;
        AnimationClock5.restart();
    }
}