#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "HeaderLogo.h"
#include "Screens.h"
#include "DimensionButtons.h"
#include "../Logic/Rules.h"
#include "../Game/PexesoGrid.h"
#include "../Game/Game.h"

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
    Rules rules;
    Game singleplayerGame;
    int rowSize = 2;
    int colSize = 2;
    void setRowSize(int row);
    void setColSize(int col);
public:
    Window();
    ~Window();
    void handleEvents();
    void run();
    void changeScreen(Screen newScreen);
    void drawScreens();
    void checkPairs();
    void gameStart();
};

#endif //PEXESO_WINDOW_H