#ifndef WORDGENERATOR_HPP
#define WORDGENERATOR_HPP
#pragma once


#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <random>

struct Word {
    sf::Text text;
    bool active = true;
    bool hit = false;
};

class WordGenerator {
public:
    explicit WordGenerator(const sf::Font& font, const std::vector<std::string>& wordList);
    void draw(sf::RenderWindow& window) const;
    void updateMovement(float deltaTime);
    bool checkWordMatch(const std::string& typed);
    const std::vector<Word>& getWords() const { return wordsData; }

private:
    std::vector<Word> wordsData;
    sf::Font textFont;
    float moveSpeed = 200.f;
    float dropSpeed = 300.f;
    std::mt19937 randomEngine;  // https://www.reddit.com/r/cpp/comments/r7dc8b/debunking_all_myths_about_mt19937_random_number/
    //NOTE:HOW to apply setting and template for this part was with AI Help ai.dev
    std::uniform_real_distribution<float> yDistribution;

    void textBuilder(const std::vector<std::string>& wordList);
};

#endif // WORDGENERATOR_HPP