#ifndef GAMEROOM_HPP
#define GAMEROOM_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <optional>  // Required for std::optional
using namespace std;

#define TILE_WIDTH 256
#define TILE_HEIGHT 96
#define ROOM_WIDTH (1536 / TILE_WIDTH)
#define ROOM_HEIGHT (768 / TILE_HEIGHT)

class GameRoom {
private:
    sf::Texture topTileTexture;
    sf::Texture middleTileTexture;
    sf::Texture bottomTileTexture;
    sf::Texture KnightStatueTexture;
    sf::Texture PriestStatueTexture;
    sf::Texture TorchTexture;
    sf::Texture FloorTexture;
    sf::Texture* selectedTexture = nullptr;
    
    std::vector<std::vector<std::optional<sf::Sprite>>> tiles; // Optional to avoid default constructor issue
    sf::Sprite TorchSprite1;
    sf::Sprite TorchSprite2;
    sf::Sprite TorchSprite3;
    sf::Sprite TorchSprite4;
    sf::Sprite TorchSprite5;
    sf::IntRect TorchFrames[4];
    int CurrentFrame1 = 0;
    int CurrentFrame2 = 1;
    int CurrentFrame3 = 2;
    int CurrentFrame4 = 3;
    int CurrentFrame5 = 0;

    sf::Clock AnimationClock1;
    sf::Clock AnimationClock2;
    sf::Clock AnimationClock3;
    sf::Clock AnimationClock4;
    sf::Clock AnimationClock5;

    bool Statue1 = false;
    bool Statue2 = true;

public:
    GameRoom();
    ~GameRoom();
    void draw(sf::RenderWindow& window);
};

#endif // GAMEROOM_HPP
