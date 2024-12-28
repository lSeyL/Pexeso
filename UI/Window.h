#include <SFML/Graphics.hpp>
#include "Button.h"
#include "HeaderLogo.h"
#include "Screens.h"
#include "DimensionButtons.h"
#ifndef PEXESO_WINDOW_H
#define PEXESO_WINDOW_H

class Window {
private:
    sf::RenderWindow window;
    sf::Font font;
    Screen currentScreen;
    HeaderLogo headerLogo;
    Button singleplayerButton;
    Button multiplayerButton;
    Button quitButton;
    Button backButton;
    Button startButton;
    DimensionButtons rowButtons;
    DimensionButtons columnButtons;
public:
    Window();
    ~Window();
    void handleEvents();
    void run();
    void changeScreen(Screen newScreen);
    void drawScreens();
};

#endif //PEXESO_WINDOW_H