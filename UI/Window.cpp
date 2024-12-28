#include "Window.h"


Window::Window()
        : singleplayerButton(sf::Vector2f(1200 / 2 - 300 / 2, 800 / 2 - 3 * 75 / 2 - 20), sf::Vector2f(300, 75), "Singleplayer", font),
          multiplayerButton(sf::Vector2f(1200 / 2 - 300 / 2, 800 / 2 - 75/ 2 + 20), sf::Vector2f(300, 75), "Multiplayer", font),
          quitButton(sf::Vector2f(1200 / 2 - 300 / 2, 800 / 2 + 75 / 2 + 60), sf::Vector2f(300, 75), "Quit", font),
          headerLogo(font),
          backButton(sf::Vector2f(60 / 2, 700), sf::Vector2f(200, 75), "Back", font),
          startButton(sf::Vector2f(970, 700), sf::Vector2f(200, 75), "Start", font),
          rowButtons(sf::Vector2f(100, 100), sf::Vector2f(50, 50), 9, font),
          columnButtons(sf::Vector2f(100, 200), sf::Vector2f(50, 50), 9, font)
{
    grid = PexesoGrid(rowSize, colSize, sf::Vector2f(50, 50), sf::Vector2f(100, 100));
    currentScreen = Screen::MainMenu;
    singleplayerButton.setTextPosition(sf::Vector2f(485,275));
    multiplayerButton.setTextPosition(sf::Vector2f(500,390));
    quitButton.setTextPosition(sf::Vector2f(562,510));
    backButton.setTextPosition(sf::Vector2f(80, 710));
    startButton.setTextPosition(sf::Vector2f(1025, 710));
    window.create(sf::VideoMode(1200, 800), "Pexeso");
    window.setFramerateLimit(60);


    std::string fontPath = "C:/SFML/Pexeso/UI/Roboto-Light.ttf";
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font\n";
        return;
    }
}

Window::~Window() {

}

void Window::handleEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

    if(currentScreen == Screen::MainMenu) {
        if (singleplayerButton.isClicked(event, window)) {
            std::cout << "Singleplayer button clicked\n";
            changeScreen(Screen::Singleplayer);
        }
        if (multiplayerButton.isClicked(event, window)) {
            std::cout << "Multiplayer button clicked\n";
            changeScreen(Screen::Multiplayer);
        }
        if (quitButton.isClicked(event, window)) {
            std::cout << "Quit button clicked\n";
            changeScreen(Screen::Quit);
            window.close();
        }
    }
        if(currentScreen == Screen::Singleplayer) {
            if (backButton.isClicked(event, window)) {
                std::cout << "Back button clicked\n";
                changeScreen(Screen::MainMenu);
            }
            if(startButton.isClicked(event,window))
            {
                printf("Row : %d, Col: %d\n", rowSize, colSize);
                printf("%dx%d\n", rowSize, colSize);
                if(rules.checkPair(rowSize, colSize))
                {
                    printf("START\n");
                    changeScreen(Screen::GameSingle);
                    gameStart();
                } else {
                    printf("CANNOT START\n");
                }

            }
            rowButtons.handleEvent(event, window);
            columnButtons.handleEvent(event, window);
            setRowSize(rowButtons.getSelectedIndex());
            setColSize(columnButtons.getSelectedIndex());
        }

        if(currentScreen == Screen::GameSingle)
        {
            grid.handleEvent(event,window);
        }
        if(currentScreen == Screen::Multiplayer) {
            if (backButton.isClicked(event, window)) {
                std::cout << "Back button clicked\n";
                changeScreen(Screen::MainMenu);
            }
            if(startButton.isClicked(event,window))
            {
                printf("Row : %d, Col: %d\n", rowSize, colSize);
                printf("%dx%d\n", rowSize, colSize);
                if(rules.checkPair(rowSize, colSize))
                {
                    printf("START\n");
                    changeScreen(Screen::GameMulti);
                } else {
                    printf("CANNOT START\n");
                }

            }
            rowButtons.handleEvent(event, window);
            columnButtons.handleEvent(event, window);
            setRowSize(rowButtons.getSelectedIndex());
            setColSize(columnButtons.getSelectedIndex());

        }
    }
}

void Window::run() {

    while(window.isOpen())
    {
        handleEvents();
        window.clear(sf::Color(89, 89, 89));
        drawScreens();
        window.display();
    }
}

void Window::changeScreen(Screen newScreen) {
    currentScreen = newScreen;
}

void Window::drawScreens() {
    if(currentScreen == Screen::MainMenu) {
        headerLogo.draw(window);
        singleplayerButton.draw(window);
        multiplayerButton.draw(window);
        quitButton.draw(window);
    }
    if(currentScreen == Screen::Singleplayer) {
        backButton.draw(window);
        startButton.draw(window);
        columnButtons.draw(window);
        rowButtons.draw(window);
    }
    if(currentScreen == Screen::GameSingle) {
        grid.draw(window);
    }
    if(currentScreen == Screen::Multiplayer) {
        backButton.draw(window);
        startButton.draw(window);
        columnButtons.draw(window);
        rowButtons.draw(window);
    }
}

void Window::setRowSize(int row) {
    rowSize = row;
}

void Window::setColSize(int col) {
    colSize = col;
}

void Window::gameStart() {
    int row = rowSize;
    int col = colSize;

    float windowWidth = window.getSize().x - 200;
    float windowHeight = window.getSize().y - 200;
    float tileWidth = windowWidth / col;
    float tileHeight = windowHeight / row;
    float tileSize = std::min(tileWidth, tileHeight);
    float minTileSize = 50.f;
    float maxTileSize = 150.f;
    tileSize = std::clamp(tileSize, minTileSize, maxTileSize);
    grid = PexesoGrid(row, col,
                      sf::Vector2f(50, 50),
                      sf::Vector2f(tileSize, tileSize));
}

