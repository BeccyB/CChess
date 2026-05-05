#include "abstract_user_interface.h"

#include <iostream>
#include <string>


void Viewer::display_game(Position_of_pawn p) {
    std::cout << "---- imaginary chess board with pawn ---- on position: (" << p.x << ", " << p.y << ")" << std::endl;  
}

bool Viewer::ask_user_if_pawn_should_go_one_step_forward() {
    std::cout << "Do you want to move the pawn one step forward? (y/n)" << std::endl;

    std::string input;
    std::cin >> input;

    if (input == "y") {
        return true;
    } else {
        return false;
    }
}