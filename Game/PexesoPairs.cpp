//
// Created by seil0 on 28. 12. 2024.
//

#include "PexesoPairs.h"

PexesoPairs::PexesoPairs() {}

void PexesoPairs::generatePairs(std::vector<std::pair<sf::Color, char>>& pairs, int rows, int columns) {
    pairs.clear();
    std::vector<std::pair<sf::Color, char>> basePairs = {
            {sf::Color::Red, 'A'},
            {sf::Color::Blue, 'B'},
            {sf::Color::Green, 'C'},
            {sf::Color::Yellow, 'D'},
            {sf::Color::Cyan, 'E'},
            {sf::Color::Magenta, 'F'},
            {sf::Color(178, 32, 170), 'L'},
            {sf::Color::White, 'H'},
            {sf::Color(255, 69, 0), 'I'},
            {sf::Color(255, 165, 0), 'J'},
            {sf::Color(255, 20, 147), 'K'},
            {sf::Color(32, 178, 170), 'L'},
            {sf::Color(135, 206, 235), 'M'},
            {sf::Color(0, 255, 127), 'N'},
            {sf::Color(255, 69, 0), 'O'},
            {sf::Color(186, 85, 211), 'P'},
            {sf::Color(0, 255, 255), 'Q'},
            {sf::Color(255, 105, 180), 'R'},
            {sf::Color(128, 0, 128), 'S'},
            {sf::Color(240, 128, 128), 'T'},
            {sf::Color(255, 99, 71), 'U'},
            {sf::Color(144, 238, 144), 'V'},
            {sf::Color(102, 205, 170), 'W'},
            {sf::Color(250, 128, 114), 'X'},
            {sf::Color(255, 215, 0), 'Y'},
            {sf::Color(186, 85, 211), 'Z'},
    };
    int requiredPairs = rows * columns / 2;
    while (basePairs.size() < requiredPairs) {
        basePairs.insert(basePairs.end(), basePairs.begin(), basePairs.end());
    }
    basePairs.resize(requiredPairs);
    pairs.reserve(requiredPairs * 2);
    for (const auto& pair : basePairs) {
        pairs.push_back(pair);
        pairs.push_back(pair);
    }
}
