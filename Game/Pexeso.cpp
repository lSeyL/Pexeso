//
// Created by seil0 on 28. 12. 2024.
//

#include "Pexeso.h"

Pexeso::Pexeso(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& backColor, const sf::Color& frontColor, char label)
        : backColor(backColor), frontColor(frontColor), label(label), revealed(false), clicked(false), id(-1) {
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(backColor);

    std::string fontPath = "C:/SFML/Pexeso/UI/Roboto-Light.ttf";
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font\n";
        return;
    }

    textLabel.setString(label);
    textLabel.setFont(font);
    textLabel.setCharacterSize(42);
    textLabel.setFillColor(sf::Color::White);
    textLabel.setStyle(sf::Text::Bold);

    sf::FloatRect textBounds = textLabel.getLocalBounds();
    textLabel.setOrigin(textBounds.width, textBounds.height);
    textLabel.setPosition(position.x + size.x / 2 + 2, position.y + size.y / 2);


}

void Pexeso::draw(sf::RenderWindow& window) {
    window.draw(shape);
    if(revealed)
    {
        window.draw(textLabel);
    }
}

void Pexeso::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (isClicked(sf::Mouse::getPosition(window))) {
            printf("Click: %d", getId());
            if (!revealed) {
                reveal();
            }
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
void Pexeso::reveal() {
    revealed = true;
    shape.setFillColor(frontColor);
}
void Pexeso::hide() {
    revealed = false;
    shape.setFillColor(backColor);
}
char Pexeso::getLabel() const {
    return label;
}
bool Pexeso::isRevealed() const {
    return revealed;
}
const sf::Color& Pexeso::getColor() const {
    return shape.getFillColor();
}

bool Pexeso::isClicked() const {
    return clicked;
}

int Pexeso::getId() const {
    return id;
}

void Pexeso::setId(int newId) {
    id = newId;
}
