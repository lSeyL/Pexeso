//
// Created by seil0 on 27. 12. 2024.
//

#include "Button.h"
Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, const sf::String& label, const sf::Font& font) {
    buttonShape.setSize(size);
    buttonShape.setPosition(position);
    buttonShape.setFillColor(sf::Color(43,43,43));

    buttonText.setString(label);
    buttonText.setFont(font);
    buttonText.setCharacterSize(42);
    buttonText.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.width / 2.f, textBounds.height / 2.f);
    buttonText.setPosition(position.x, position.y);

}

void Button::draw(sf::RenderWindow& window) {
    window.draw(buttonShape);
    window.draw(buttonText);
}

bool Button::isClicked(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (buttonShape.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                return true;
            }
        }
    }
    return false;
}

void Button::setTextPosition(const sf::Vector2f &position) {
    buttonText.setPosition(position.x, position.y);
}

void Button::setFillColor(const sf::Color &color) {
    buttonShape.setFillColor(color);
}
