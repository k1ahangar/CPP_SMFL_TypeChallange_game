#ifndef RECORDMNG_HPP
#define RECORDMNG_HPP
#pragma once

#include <string>

class RecordMng {
public:
    RecordMng(const std::string& playerName, int score);

    int addPoints(int points);
    int getScore() const;
    void saveScoreToFile(const std::string& filename) const;
    void loadScoreFromFile(const std::string& filename);

private:
    std::string playerName;
    int score;
};

#endif // RECORDMNG_HPP