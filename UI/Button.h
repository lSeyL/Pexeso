//
// Created by seil0 on 27. 12. 2024.
//
#include <SFML/Graphics.hpp>
#ifndef PEXESO_BUTTON_H
#define PEXESO_BUTTON_H


class Button {
public:
    Button(const sf::Vector2f& position, const sf::Vector2f& size, const sf::String& label, const sf::Font& font);

    void draw(sf::RenderWindow& window);
    void setTextPosition(const sf::Vector2f& position);
    bool isClicked(const sf::Event& event, sf::RenderWindow& window);

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
};


#endif //PEXESO_BUTTON_H
