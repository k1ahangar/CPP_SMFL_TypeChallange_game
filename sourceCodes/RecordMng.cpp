#include "RecordMng.hpp"
#include <fstream>
#include <iostream>
//constructor for storing user score
RecordMng::RecordMng(const std::string& playerName, int score)
    : playerName(playerName), score(score) {}
// adding points to prevoius point
int RecordMng::addPoints(int points) {
    score += points;
    return score;
}
//score getter
int RecordMng::getScore() const {
    return score;
}
// saving score to one text file
void RecordMng::saveScoreToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::out | std::ios::app);
    if (file.is_open()) {
        file << playerName << " " << score << std::endl;
    } else {
        std::cerr << "Error: Unable to open file for writing: " << filename << std::endl;
    }
}
//loading users scores previously saved on one txt file
void RecordMng::loadScoreFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::in);
    if (file.is_open()) {
        file >> playerName >> score;
    } else {
        std::cerr << "Error: Unable to open file for reading: " << filename << std::endl;
    }
}