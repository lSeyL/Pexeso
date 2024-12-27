#include <SFML/Graphics.hpp>
#include "Button.h"
#include "HeaderLogo.h"
#ifndef PEXESO_WINDOW_H
#define PEXESO_WINDOW_H

class Window {
private:
    sf::RenderWindow window;
    sf::Font font;
    HeaderLogo headerLogo;
    Button singleplayerButton;
    Button multiplayerButton;
    Button quitButton;
public:
    Window();
    ~Window();
    void handleEvents();
    void run();
};

#endif //PEXESO_WINDOW_H