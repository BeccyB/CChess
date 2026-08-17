#include "abstract_user_interface.h"

#include <iostream>
#include <string>

void Viewer::display_game(Chess_board& cb) const {
    for (Position_of_pawn p : cb.get_positions_of_pawns()) {
        std::cout << "Pawn on: (" << p.x << ", " << p.y << ")" << std::endl; 
    }  
}

// bool Viewer::ask_user_if_pawn_should_go_one_step_forward() const {
//     std::cout << "Do you want to move the pawn one step forward? (y/n)" << std::endl;

//     std::string input;
//     std::cin >> input;

//     if (input == "y") {
//         return true;
//     } else {
//         return false;
//     }
// }

std::pair<int, int> Viewer::ask_user_to_select_a_pawn_that_shall_go_one_step_forward() const { // only return x,y coordinates TODO

    std:: cout << "Pick a pawn by entering its coordinates" << std::endl;

    int x, y;
    std::cin >> x >> y;

    // if ((x < b.get_board_lower_bound_x() || x > b.get_board_upper_bound_x()) || (y < b.get_board_lower_bound_y() || y > b.get_board_upper_bound_y())) {
    //     std::cout << "The coordinates you entered are not in the domain. Please try again." << std::endl;
    //     return false;
    // } 

    if (b.selection_inside_the_field(x, y)) {                       // this code might belong rather somewhere else ...  
        if (b.check_if_there_is_a_pawn_in_given_position(x, y)) {
            b.move_pawn_one_step_forward(x, y); // to implement
        }
        return false;
    }
    return false;
}

void Viewer::print_pawn_reached_other_side_and_game_over() const {
    std::cout << "Pawn reached other side.  GAME OVER." << std::endl; 
}
