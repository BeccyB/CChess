#include "abstract_user_interface.h"

#include <iostream>
#include <string>

void Viewer::display_game(Chess_board& cb) const {
    for (Position_of_pawn p : cb.get_positions_of_pawns()) {
        std::cout << "Pawn on: (" << p.x << ", " << p.y << ")" << std::endl; 
    }  
}

std::pair<int, int> Viewer::ask_user_to_select_a_pawn_that_shall_go_one_step_forward() const {

    std:: cout << "Pick a pawn by entering its coordinates" << std::endl;

    int x, y;
    std::cin >> x >> y; 

    return {x, y};
}

void Viewer::print_pawn_reached_other_side_and_game_over() const {
    std::cout << "Pawn reached other side.  GAME OVER." << std::endl; 
}
