//
// Created by seil0 on 27. 12. 2024.
//

#ifndef PEXESO_HEADERLOGO_H
#define PEXESO_HEADERLOGO_H

#include "SFML/Graphics.hpp"

class HeaderLogo {
private:
    sf::Text logoText;
public:
    HeaderLogo(const sf::Font& font);
    void draw(sf::RenderWindow& window);
};


#endif //PEXESO_HEADERLOGO_H
