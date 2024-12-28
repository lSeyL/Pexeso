//
// Created by seil0 on 28. 12. 2024.
//

#include "DimensionButtons.h"

DimensionButtons::DimensionButtons(const sf::Vector2f& startPosition, const sf::Vector2f& buttonSize, int count, const sf::Font& font) {
    for (int i = 0; i < count; ++i) {
        sf::Vector2f position = startPosition + sf::Vector2f(i * (buttonSize.x + 10), 0);
        buttons.emplace_back(position, buttonSize, std::to_string(i + 2), font);
    }
}

void DimensionButtons::draw(sf::RenderWindow& window) {
    for (auto& button : buttons) {
        button.draw(window);
    }
}

void DimensionButtons::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    for (size_t i = 0; i < buttons.size(); ++i) {
        if (buttons[i].isClicked(event, window)) {
            selectedIndex = i;
            highlightButton(i);

            printf("Selected button : %zu\n", i+2);
        }
    }
}


int DimensionButtons::getSelectedIndex() const {
    return selectedIndex + 2;
}



void DimensionButtons::highlightButton(size_t index) {
    for (size_t i = 0; i < buttons.size(); ++i) {
        if (i == index) {
            buttons[i].setFillColor(sf::Color(105, 122, 69));
        } else {
            buttons[i].setFillColor(sf::Color(43, 43, 43));
        }
    }
}