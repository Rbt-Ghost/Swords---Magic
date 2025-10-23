#include "..\src\Headers\Score.hpp"
#include <cstring>
#include <iomanip>
#include <sstream>
#include <cstdint>
#include <stdexcept>

// ------------------ SHA256 implementation (small, self-contained) ------------------
std::string Score::sha256(const std::string &input)
{
    static const uint32_t k[64] = {
        0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
        0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
        0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
        0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
        0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
        0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
        0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
        0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
    };

    auto rotr = [](uint32_t x, uint32_t n){ return (x >> n) | (x << (32 - n)); };

    // preprocess
    std::vector<uint8_t> msg(input.begin(), input.end());
    uint64_t bitlen = msg.size() * 8ULL;
    msg.push_back(0x80);
    while ((msg.size() % 64) != 56) msg.push_back(0x00);
    for (int i = 7; i >= 0; --i) msg.push_back(static_cast<uint8_t>((bitlen >> (i*8)) & 0xFF));

    // initial hash values
    uint32_t h0 = 0x6a09e667, h1 = 0xbb67ae85, h2 = 0x3c6ef372, h3 = 0xa54ff53a;
    uint32_t h4 = 0x510e527f, h5 = 0x9b05688c, h6 = 0x1f83d9ab, h7 = 0x5be0cd19;

    // process each 512-bit chunk
    for (size_t chunk = 0; chunk < msg.size(); chunk += 64)
    {
        uint32_t w[64];
        std::memset(w, 0, sizeof(w));
        for (int i = 0; i < 16; ++i)
        {
            w[i] = (uint32_t(msg[chunk + i*4]) << 24) | (uint32_t(msg[chunk + i*4 + 1]) << 16)
                 | (uint32_t(msg[chunk + i*4 + 2]) << 8) | uint32_t(msg[chunk + i*4 + 3]);
        }
        for (int i = 16; i < 64; ++i)
        {
            uint32_t s0 = rotr(w[i-15], 7) ^ rotr(w[i-15], 18) ^ (w[i-15] >> 3);
            uint32_t s1 = rotr(w[i-2], 17) ^ rotr(w[i-2], 19) ^ (w[i-2] >> 10);
            w[i] = w[i-16] + s0 + w[i-7] + s1;
        }

        uint32_t a = h0, b = h1, c = h2, d = h3, e = h4, f = h5, g = h6, h = h7;
        for (int i = 0; i < 64; ++i)
        {
            uint32_t S1 = rotr(e, 6) ^ rotr(e, 11) ^ rotr(e, 25);
            uint32_t ch = (e & f) ^ ((~e) & g);
            uint32_t temp1 = h + S1 + ch + k[i] + w[i];
            uint32_t S0 = rotr(a, 2) ^ rotr(a, 13) ^ rotr(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        h0 += a; h1 += b; h2 += c; h3 += d;
        h4 += e; h5 += f; h6 += g; h7 += h;
    }

    std::ostringstream os;
    os << std::hex << std::setfill('0') << std::nouppercase;
    auto out32 = [&os](uint32_t x){ os << std::setw(8) << x; };
    out32(h0); out32(h1); out32(h2); out32(h3); out32(h4); out32(h5); out32(h6); out32(h7);
    return os.str();
}
// ------------------ end SHA256 implementation ------------------

// ------------------ simple XOR encrypt/decrypt (hex encoded) ------------------
std::string Score::xorEncryptHex(const std::string &plain, const std::string &key)
{
    if (key.empty()) throw std::invalid_argument("key empty");
    std::ostringstream os;
    os << std::hex << std::setfill('0') << std::nouppercase;
    for (size_t i = 0; i < plain.size(); ++i)
    {
        uint8_t b = static_cast<uint8_t>(plain[i]) ^ static_cast<uint8_t>(key[i % key.size()]);
        os << std::setw(2) << static_cast<int>(b);
    }
    return os.str();
}

std::string Score::xorDecryptHex(const std::string &hexStr, const std::string &key)
{
    if (key.empty()) throw std::invalid_argument("key empty");
    if (hexStr.size() % 2 != 0) return {};
    std::string out;
    out.reserve(hexStr.size() / 2);
    for (size_t i = 0; i < hexStr.size(); i += 2)
    {
        std::string byteHex = hexStr.substr(i, 2);
        uint8_t val = static_cast<uint8_t>(std::stoul(byteHex, nullptr, 16));
        uint8_t dec = val ^ static_cast<uint8_t>(key[(i/2) % key.size()]);
        out.push_back(static_cast<char>(dec));
    }
    return out;
}
// ------------------ end XOR helpers ------------------

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
}

void Score::loadBestScore()
{
    std::ifstream file("../Score.txt");
    if (!file.is_open())
    {
        globalBestScore = 0;
        return;
    }
    std::string encLine;
    std::string hashLine;
    if (!std::getline(file, encLine) || !std::getline(file, hashLine))
    {
        globalBestScore = 0;
        file.close();
        return;
    }
    file.close();
    // verify integrity: hash is computed over the encrypted blob + salt
    std::string expected = sha256(encLine + this->scoreSalt);
    if (expected != hashLine)
    {
        globalBestScore = 0; // tampered or corrupted
        return;
    }
    // decrypt
    std::string scoreStr;
    try {
        scoreStr = xorDecryptHex(encLine, this->scoreSalt);
        globalBestScore = std::stoi(scoreStr);
    } catch (...) {
        globalBestScore = 0;
    }
}

void Score::saveBestScore()
{
    if (currentScore > globalBestScore) {
        globalBestScore = currentScore;
    }
    // encrypt the score string, then store encryptedHex and sha256(encryptedHex + salt)
    std::ofstream file("../Score.txt", std::ios::trunc);
    if (file.is_open())
    {
        std::string scoreStr = std::to_string(globalBestScore);
        std::string enc = xorEncryptHex(scoreStr, this->scoreSalt);
        std::string h = sha256(enc + this->scoreSalt);
        file << enc << "\n" << h << "\n";
        file.close();
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
