//
// Created by seil0 on 28. 12. 2024.
//

#ifndef PEXESO_PEXESOGRID_H
#define PEXESO_PEXESOGRID_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Pexeso.h"

class PexesoGrid {
private:
    int rows;
    int columns;
    sf::Vector2f startPosition;
    sf::Vector2f pexesoSize;
    std::vector<Pexeso> pexesoObjects;
public:
    PexesoGrid();
    PexesoGrid(int rows, int columns, const sf::Vector2f& startPosition, const sf::Vector2f& pexesoSize);
    void generateGrid();
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
    std::vector<Pexeso>& getPexesoObjects();
};



#endif //PEXESO_PEXESOGRID_H
