//
// Created by seil0 on 28. 12. 2024.
//

#include "Game.h"
Game::Game()
{
}

Game::~Game() {
    delete grid;
}


void Game::start(int rows, int cols, const sf::RenderWindow& window) {
    rowSize = rows;
    colSize = cols;

    float windowWidth = window.getSize().x - 200;
    float windowHeight = window.getSize().y - 200;
    float tileWidth = windowWidth / colSize;
    float tileHeight = windowHeight / rowSize;
    float tileSize = std::min(tileWidth, tileHeight);
    float minTileSize = 50.f;
    float maxTileSize = 150.f;
    tileSize = std::clamp(tileSize, minTileSize, maxTileSize);

    grid = new PexesoGrid(rowSize, colSize, sf::Vector2f(50, 50), sf::Vector2f(tileSize, tileSize));
   grid->shuffleGrid();
}

void Game::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    static sf::Clock revealTimer;
    static bool waitingToHide = false;
    static bool inputDisabled = false;
    static bool waitingForMatch = false;

    if (inputDisabled) {
        if (waitingToHide && revealTimer.getElapsedTime().asSeconds() > 1.0f) {
            revealedCards[0]->setColor(sf::Color::Black);
            revealedCards[0]->hide();
            revealedCards[1]->setColor(sf::Color::Black);
            revealedCards[1]->hide();

            revealedCards.clear();
            waitingToHide = false;
            inputDisabled = false;
        }
        return;
    }

    grid->handleEvent(event, window);
    revealedCards.clear();
    for (auto& card : grid->getPexesoObjects()) {
        if (card->isRevealed()) {
            revealedCards.push_back(card);
        }
    }

    if (revealedCards.size() == 2) {
        inputDisabled = true;
        if (revealedCards[0]->getId() == revealedCards[1]->getId()) {
            printf("0ID %d, %d", revealedCards[0]->getId(), revealedCards[0]->getColor().toInteger());
            printf("1ID %d, %d", revealedCards[1]->getId(), revealedCards[1]->getColor().toInteger());

            revealedCards[0]->hide();
            revealedCards[1]->hide();
            revealedCards[0]->setColor(sf::Color::Transparent);
            revealedCards[1]->setColor(sf::Color::Transparent);

            revealedCards.clear();
            inputDisabled = false;
            revealTimer.restart();
            waitingToHide = true;
        } else {
            std::cout << "Not a pair." << std::endl;
            revealTimer.restart();
            waitingToHide = true;
        }
    }
}

void Game::draw(sf::RenderWindow& window) {
    //grid->shuffleVector(grid->getPexesoObjects());
    grid->draw(window);
}


