//
// Created by seil0 on 28. 12. 2024.
//

#ifndef PEXESO_DIMENSIONBUTTONS_H
#define PEXESO_DIMENSIONBUTTONS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Button.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Button.h"

class DimensionButtons {
private:
    std::vector<Button> buttons;
    int selectedIndex = -1;
    void highlightButton(size_t index);
public:
    DimensionButtons(const sf::Vector2f& startPosition, const sf::Vector2f& buttonSize, int count, const sf::Font& font);
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
    int getSelectedIndex() const;
};



#endif //PEXESO_DIMENSIONBUTTONS_H
