#include "Window.h"
//#include "Button.h"
#include <iostream>
Window::Window()
        : singleplayerButton(sf::Vector2f(1200 / 2 - 300 / 2, 800 / 2 - 3 * 75 / 2 - 20), sf::Vector2f(300, 75), "Singleplayer", font),
          multiplayerButton(sf::Vector2f(1200 / 2 - 300 / 2, 800 / 2 - 75/ 2 + 20), sf::Vector2f(300, 75), "Multiplayer", font),
          quitButton(sf::Vector2f(1200 / 2 - 300 / 2, 800 / 2 + 75 / 2 + 60), sf::Vector2f(300, 75), "Quit", font),
          headerLogo(font)
{
    singleplayerButton.setTextPosition(sf::Vector2f(485,275));
    multiplayerButton.setTextPosition(sf::Vector2f(500,390));
    quitButton.setTextPosition(sf::Vector2f(562,510));
    window.create(sf::VideoMode(1200, 800), "SFML Window");
    window.setFramerateLimit(60);
    std::string fontPath = "C:/SFML/Pexeso/UI/Roboto-Light.ttf";
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font\n";
        return;
    }
}

void Window::handleEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (singleplayerButton.isClicked(event, window)) {
            std::cout << "Singleplayer button clicked\n";
        }
        if (multiplayerButton.isClicked(event, window)) {
            std::cout << "Multiplayer button clicked\n";
        }
        if (quitButton.isClicked(event, window)) {
            std::cout << "Quit button clicked\n";
            window.close();
        }
    }
}


void Window::run() {

    while(window.isOpen())
    {
        handleEvents();

        window.clear(sf::Color(89, 89, 89));
        headerLogo.draw(window);
        singleplayerButton.draw(window);
        multiplayerButton.draw(window);
        quitButton.draw(window);
        window.display();
    }
}

Window::~Window() {

}
