#include <iostream>
#include <memory>

#include <chess/game.h>

void show_options() {
    // Game options
}

// TODO(rebecca) move this method to chess library
void main_menu() {
    std::cout << "Chess game menu:" << std::endl;
    std::cout << "Enter \"S\" to start new Game." << std::endl;
    std::cout << "Enter \"O\" for Options" << std::endl;
    std::cout << "Enter \"E\" for Exit" << std::endl;
    std::cout << "Enter \"H\" for Help." << std::endl;

    char selection;

    std::cin >> selection;

    if (selection == 'S') {

        std::string name_white;
        std::cout << "Enter player white:" << std::endl;
        std::cin >> name_white;

        std::string name_black;
        std::cout << "Enter player black:" << std::endl;
        std::cin >> name_black;

        // start game:
        auto game = std::make_unique<chess::Game>();
        game->start();
        return;
    }

    if (selection == 'O') {
        show_options(); // TODO...
        return;
    }

    if (selection == 'H') {
        std::cout << "Help is coming..."
                  << std::endl; // How to operate our game ...
        std::cout << "If you want to learn more about chess, read wikipedia: "
                     "https://en.wikipedia.org/wiki/Chess. "
                  << std::endl;
        return;
    }

    if (selection == 'E') {
        return;
    }
}

int main() {

    main_menu();
}