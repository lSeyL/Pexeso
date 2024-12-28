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
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            sf::Vector2f position = startPosition + sf::Vector2f(col * (pexesoSize.x + 10), row * (pexesoSize.y + 10));
            pexesoObjects.emplace_back(position, pexesoSize, sf::Color::Red);
        }
    }
}

void PexesoGrid::draw(sf::RenderWindow& window) {
    for (auto& pexeso : pexesoObjects) {
        pexeso.draw(window);
    }
}

void PexesoGrid::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    for (auto& pexeso : pexesoObjects) {
        pexeso.handleEvent(event, window);
    }
}

std::vector<Pexeso>& PexesoGrid::getPexesoObjects() {
    return pexesoObjects;
}

