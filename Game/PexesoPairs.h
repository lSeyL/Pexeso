//
// Created by seil0 on 28. 12. 2024.
//

#ifndef PEXESO_PEXESOPAIRS_H
#define PEXESO_PEXESOPAIRS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include <algorithm>
#include <random>

class PexesoPairs{
public:
    PexesoPairs();
    void generatePairs(std::vector<std::pair<sf::Color, char>>& pairs, int rows, int columns);

private:
    void shuffleVector(std::vector<std::pair<sf::Color, char>>& pairs);
};


#endif //PEXESO_PEXESOPAIRS_H
