#include "..\src\Headers\Score.hpp"

int Score::globalBestScore = 0;

Score::Score():
currentScoreText(font),
bestScoreText(font)
{
    LoadFont(font, "../assets/Medieval-timeline-font/MedievalTimeline-DOPRE.ttf");
    
    currentScore = 0;
    loadBestScore();

    // Set up current score display
    currentScoreText.setFont(font);
    currentScoreText.setCharacterSize(30);
    currentScoreText.setFillColor(sf::Color::Yellow);
    currentScoreText.setPosition({580, 20});
    currentScoreText.setString("Score: 0");

    // Set up best score display
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
    std::ifstream file("Score.txt");
    if (file.is_open()) {
        file >> globalBestScore;  // Use the static member to load best score
        file.close();
    } else {
        globalBestScore = 0;
    }
}

void Score::saveBestScore()
{
    if (currentScore > globalBestScore) {
        globalBestScore = currentScore;  // Update the static best score
        std::ofstream file("Score.txt");
        if (file.is_open()) {
            file << globalBestScore;  // Save the global best score
            file.close();
        }
    }
}

void Score::update(Player &player)
{
    if (clock.getElapsedTime().asSeconds() >= 1.f && !player.get_isDead()) {
        currentScore++;
        clock.restart();
    }

    currentScoreText.setString("Score: " + std::to_string(currentScore));
}

void Score::updateFlyingDemon(FlyingDemon &FlyDemon)
{
    if (!FlyDemon.get_isDead())
    {
        checkE1 = true;
    }
    if (checkE1 && FlyDemon.get_isDead() && FlyDemon.get_CurrentFrame() == 1 && clock1.getElapsedTime().asSeconds() > 0.16f)
    {
        currentScore += 10;
        checkE1 = false;
        clock1.restart();
    }
}

void Score::updateSkeleton(Skeleton &Skeleton)
{
    if (!Skeleton.get_isDead())
    {
        checkE2 = true;
    }
    if (checkE2 && Skeleton.get_isDead() && Skeleton.get_CurrentFrame() == 1 && clock2.getElapsedTime().asSeconds() > 0.11f)
    {
        currentScore += 10;
        checkE2 = false;
        clock2.restart();
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
        globalBestScore = currentScore;  // Update global best score
        saveBestScore();
    }
    currentScore = 0;
    clock.restart();
}

void Score::LoadFont(sf::Font &font, string str)
{
    if(!font.openFromFile(str))
    {
        cerr << endl << "ERROR";
    }
}

// Static function to get the global best score
int Score::getGlobalBestScore()
{
    return globalBestScore;
}
