//
// Created by seil0 on 28. 12. 2024.
//

#include "PexesoGrid.h"

PexesoGrid::PexesoGrid() {

}
PexesoGrid::PexesoGrid(int rows, int columns, const sf::Vector2f& startPosition, const sf::Vector2f& pexesoSize)
        : rows(rows), columns(columns), startPosition(startPosition), pexesoSize(pexesoSize) {
    generateGrid();
}

void PexesoGrid::generateGrid() {
    pexesoObjects.clear();
    PexesoPairs pexesoPairs;
    std::vector<std::pair<sf::Color, char>> pairs;
    pexesoPairs.generatePairs(pairs, rows, columns);
    int currentId = 0;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            sf::Vector2f position = startPosition + sf::Vector2f(col * (pexesoSize.x + 10), row * (pexesoSize.y + 10));
            const auto& [frontColor, label] = pairs[row * columns + col];
           // Pexeso pexeso(position, pexesoSize, sf::Color::Black, frontColor, label);
            auto pexeso = std::make_shared<Pexeso>(position, pexesoSize, sf::Color::Black, frontColor, label);
            pexeso->setId(currentId);
            if ((row * columns + col) % 2 == 1) {
                ++currentId;
            }

            pexesoObjects.push_back(pexeso);
        }
    }
    shuffleVector(pexesoObjects);
}

void PexesoGrid::draw(sf::RenderWindow& window) {
    for (auto& pexeso : pexesoObjects) {
        pexeso->draw(window);
    }
}

void PexesoGrid::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    for (auto& pexeso : pexesoObjects) {
        pexeso->handleEvent(event, window);
    }
}

std::vector<std::shared_ptr<Pexeso>>& PexesoGrid::getPexesoObjects() {
    return pexesoObjects;
}

template<typename T>
void PexesoGrid::shuffleVector(std::vector<T> &vec) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
}

void PexesoGrid::shuffleGrid() {
    shuffleVector(pexesoObjects);  // Shuffle the cards in the vector
    std::cout << "AFTER SHUFFLE" << std::endl;
    for (const auto& pexeso : pexesoObjects) {
        std::cout << " Id: " << pexeso->getId() << std::endl;
    }
}





