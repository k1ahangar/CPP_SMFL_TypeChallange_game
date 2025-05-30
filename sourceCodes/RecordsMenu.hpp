#ifndef RECORDSMENU_HPP
#define RECORDSMENU_HPP
#pragma once
#include <string>


auto loadRecords(const std::string& filename);
void Record ();
struct PlayerRecord {
    std::string name;
    int score;
};



#endif //RECORDSMENU_HPP
