#include "..\src\Headers\Score.hpp"

int Score::globalBestScore = 0;

Score::Score():
currentScoreText(font),
bestScoreText(font)
{
    LoadFont(font, "../assets/Medieval-timeline-font/MedievalTimeline-DOPRE.ttf");
    
    currentScore = 0;
    loadBestScore();

    currentScoreText.setFont(font);
    currentScoreText.setCharacterSize(30);
    currentScoreText.setFillColor(sf::Color::Yellow);
    currentScoreText.setPosition({580, 20});
    currentScoreText.setString("Score: 0");

    bestScoreText.setFont(font);
    bestScoreText.setCharacterSize(30);
    bestScoreText.setFillColor(sf::Color::Yellow);
    bestScoreText.setPosition({780, 20});
    bestScoreText.setString("Best: " + std::to_string(globalBestScore));
}

Score::~Score()
{
    saveBestScore();
}

void Score::loadBestScore()
{
    std::ifstream file("../Score.txt");
    if (file.is_open()) {
        file >> globalBestScore; 
        file.close();
    } else {
        globalBestScore = 0;
    }
}

void Score::saveBestScore()
{
    if (currentScore > globalBestScore) {
        globalBestScore = currentScore;
        std::ofstream file("../Score.txt");
        if (file.is_open()) {
            file << globalBestScore; 
            file.close();
        }
    }
    bestScoreText.setString("Best: " + std::to_string(globalBestScore));
    currentScore = 0;
}

void Score::update(Player &player)
{
    currentScoreText.setString("Score: " + std::to_string(currentScore));
}

void Score::updateFlyingDemon(FlyingDemon &enemy)
{
    const void* key = static_cast<const void*>(&enemy);
    if (!enemy.get_isDead())
    {
        awardedEnemies.erase(key);
        return;
    }
    if (awardedEnemies.find(key) == awardedEnemies.end())
    {
        currentScore += 10;
        awardedEnemies.insert(key);
    }
}

void Score::updateSkeleton(Skeleton &enemy)
{
    const void* key = static_cast<const void*>(&enemy);
    if (!enemy.get_isDead())
    {
        awardedEnemies.erase(key);
        return;
    }
    if (awardedEnemies.find(key) == awardedEnemies.end())
    {
        currentScore += 25;
        awardedEnemies.insert(key);
    }
}

void Score::addScore(int amount)
{
    currentScore += amount;
}

void Score::draw(sf::RenderWindow& window)
{
    window.draw(currentScoreText);
    window.draw(bestScoreText);
}

void Score::reset()
{
    if (currentScore > globalBestScore) {
        globalBestScore = currentScore;
        saveBestScore();
    }
    currentScore = 0;
}

void Score::LoadFont(sf::Font &font, string str)
{
    if(!font.openFromFile(str))
    {
        cerr << endl << "ERROR";
    }
}

int Score::getGlobalBestScore()
{
    return globalBestScore;
}
