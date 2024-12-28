#include "Window.h"
#include <iostream>

Window::Window()
        : singleplayerButton(sf::Vector2f(1200 / 2 - 300 / 2, 800 / 2 - 3 * 75 / 2 - 20), sf::Vector2f(300, 75), "Singleplayer", font),
          multiplayerButton(sf::Vector2f(1200 / 2 - 300 / 2, 800 / 2 - 75/ 2 + 20), sf::Vector2f(300, 75), "Multiplayer", font),
          quitButton(sf::Vector2f(1200 / 2 - 300 / 2, 800 / 2 + 75 / 2 + 60), sf::Vector2f(300, 75), "Quit", font),
          headerLogo(font),
          backButton(sf::Vector2f(60 / 2, 700), sf::Vector2f(200, 75), "Back", font),
          startButton(sf::Vector2f(970, 700), sf::Vector2f(200, 75), "Start", font),
          rowButtons(sf::Vector2f(100, 100), sf::Vector2f(50, 50), 10, font),
          columnButtons(sf::Vector2f(100, 200), sf::Vector2f(50, 50), 10, font)
{

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
                std::cout << "Not ready!\n";
            }
            rowButtons.handleEvent(event, window);
            columnButtons.handleEvent(event, window);
        }

        if(currentScreen == Screen::Multiplayer) {
            if (backButton.isClicked(event, window)) {
                std::cout << "Back button clicked\n";
                changeScreen(Screen::MainMenu);
            }
            if(startButton.isClicked(event,window))
            {
                std::cout << "Not ready!\n";
            }

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
    if(currentScreen == Screen::Multiplayer) {
        backButton.draw(window);
        startButton.draw(window);
    }
}
