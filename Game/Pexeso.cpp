//
// Created by seil0 on 28. 12. 2024.
//

#include "Pexeso.h"

Pexeso::Pexeso(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color)
        : clicked(false) {
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
}

void Pexeso::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Pexeso::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (isClicked(sf::Mouse::getPosition(window))) {
            clicked = !clicked;
            setColor(clicked ? sf::Color::Green : sf::Color::Red);
        }
    }
}

bool Pexeso::isClicked(const sf::Vector2i& mousePosition) const {
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
}

void Pexeso::setColor(const sf::Color& color) {
    shape.setFillColor(color);
}

sf::FloatRect Pexeso::getBounds() const {
    return shape.getGlobalBounds();
}