//
// Created by seil0 on 28. 12. 2024.
//

#ifndef PEXESO_PEXESO_H
#define PEXESO_PEXESO_H

#include <SFML/Graphics.hpp>
class Pexeso {
private:
    sf::RectangleShape shape;
    bool clicked;


public:
    Pexeso(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color);

    void draw(sf::RenderWindow& window);

    void handleEvent(const sf::Event& event, sf::RenderWindow& window);

    bool isClicked(const sf::Vector2i& mousePosition) const;

    void setColor(const sf::Color& color);
    sf::FloatRect getBounds() const;

};


#endif //PEXESO_PEXESO_H
