//
// Created by seil0 on 28. 12. 2024.
//

#include "PexesoGrid.h"

PexesoGrid::PexesoGrid() {

}
PexesoGrid::~PexesoGrid() {
    for(auto del: pexesoObjects)
    {
        delete del;
    }
    pexesoObjects.clear();
}
PexesoGrid::PexesoGrid(int rows, int columns, const sf::Vector2f& startPosition, const sf::Vector2f& pexesoSize)
        : rows(rows), columns(columns), startPosition(startPosition), pexesoSize(pexesoSize) {
    generateGrid();

}

void PexesoGrid::generateGrid() {
    pexesoObjects.clear();
    PexesoPairs pexesoPairs;
    std::vector<std::tuple<int, sf::Color, char>> pairs;
    pexesoPairs.generatePairs(pairs, rows, columns);
    shuffleVector(pairs);
    int currentId = 0;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            sf::Vector2f position = startPosition + sf::Vector2f(col * (pexesoSize.x + 10), row * (pexesoSize.y + 10));
            const auto& [id, frontColor, label] = pairs[row * columns + col];
            Pexeso* pex = new Pexeso(position, pexesoSize, sf::Color::Black, frontColor, label);
            pex->setId(id);
            pexesoObjects.push_back(pex);
        }
    }
    log();
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

std::vector<Pexeso*>& PexesoGrid::getPexesoObjects() {
    return pexesoObjects;
}

template<typename T>
void PexesoGrid::shuffleVector(std::vector<T> &vec) {
/*
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
*/

    std::srand(std::time(0));
    for (int i = vec.size() - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(vec[i], vec[j]);
    }

}

void PexesoGrid::shuffleGrid() {
    shuffleVector(pexesoObjects);
}

void PexesoGrid::log() {
    for (int i = 0; i < pexesoObjects.size(); ++i) {
        printf("index: [%d], ID [%d]\n",i, pexesoObjects[i]->getId());
    }
}





