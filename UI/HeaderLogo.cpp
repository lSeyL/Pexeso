//
// Created by seil0 on 27. 12. 2024.
//

#include "HeaderLogo.h"
HeaderLogo::HeaderLogo(const sf::Font& font) {
    logoText.setFont(font);
    logoText.setString("Pexeso");
    logoText.setCharacterSize(125);
    logoText.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = logoText.getLocalBounds();
    logoText.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
    logoText.setPosition(400, 175);
}

void HeaderLogo::draw(sf::RenderWindow& window) {
    window.draw(logoText);
}