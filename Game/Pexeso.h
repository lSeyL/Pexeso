//
// Created by seil0 on 28. 12. 2024.
//

#ifndef PEXESO_PEXESO_H
#define PEXESO_PEXESO_H

#include <SFML/Graphics.hpp>
#include <iostream>
class Pexeso {
private:
    sf::RectangleShape shape;
    bool clicked;
    sf::Color backColor;
    sf::Color frontColor;
    char label;
    bool revealed;
    int id;
    sf::Text textLabel;
    sf::Font font;
public:
    Pexeso(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& backColor, const sf::Color& frontColor, char label);
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, sf::RenderWindow& window);
    bool isClicked(const sf::Vector2i& mousePosition) const;
    bool isClicked() const;
    void setColor(const sf::Color& color);
    bool isRevealed() const;
    void reveal();
    void hide();
    char getLabel() const;
    const sf::Color& getColor() const;
    sf::FloatRect getBounds() const;

    int getId() const;
    void setId(int newId);

};


#endif //PEXESO_PEXESO_H
