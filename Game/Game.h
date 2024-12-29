//
// Created by seil0 on 28. 12. 2024.
//

#ifndef PEXESO_GAME_H
#define PEXESO_GAME_H

#include "PexesoGrid.h"
#include <iostream>
#include <unistd.h>
#include "../Logic/Rules.h"
#include <SFML/Graphics.hpp>

class Game {
private:
    PexesoGrid grid;
    Rules rules;
    int rowSize;
    int colSize;
    std::vector<Pexeso*> revealedCards;
public:
    Game();
    void start(int rows, int cols, const sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
};


#endif //PEXESO_GAME_H
