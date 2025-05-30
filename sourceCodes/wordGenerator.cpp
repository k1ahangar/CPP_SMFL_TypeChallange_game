#include "WordGenerator.hpp"
//constructor for getting word to process generating word
WordGenerator::WordGenerator(const sf::Font& font, const std::vector<std::string>& wordList)
    : textFont(font), randomEngine(std::random_device{}()), yDistribution(50.f, 620.f) {
    textBuilder(wordList);
}
//function to create text style
void WordGenerator::textBuilder(const std::vector<std::string>& wordList) {
    for (const auto& wordString : wordList) {
        Word wordInstance(textFont);
        wordInstance.text.setFont(textFont);
        wordInstance.text.setCharacterSize(30);
        wordInstance.text.setFillColor(sf::Color::White);
        wordInstance.text.setPosition({0, yDistribution(randomEngine)});
        wordsData.push_back(wordInstance);
    }
}
// word drawer s
void WordGenerator::draw(sf::RenderWindow& window) const {
    for (const auto& word : wordsData) {
        window.draw(word.text);
    }
}
//update words movement
void WordGenerator::updateMovement(float timer) {
    for (auto& word : wordsData) {
        if (word.active) {
            word.text.move({moveSpeed * timer, 0});
        } else if (word.hit) {
            word.text.move({0, dropSpeed * timer});
        }
    }
}

bool WordGenerator::checkWordMatch(const std::string& typed) {
    for (auto& word : wordsData) {
        if (word.active && word.text.getString() == typed) {
            word.active = false;
            word.hit = true;
            return true;
        }
    }
    return false;
}