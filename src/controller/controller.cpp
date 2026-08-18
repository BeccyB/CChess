#include "controller.h"

#include <iostream>

Controller::Controller() 
    : _viewer(), _board() {}

void Controller::run_game() { 

    while (_board.pawn_reached_other_side() == false) {
        _viewer.display_game(_board);
        std::pair<int, int> input_coords {0, 0}; // intended not to be on the board

        while (true) {
            bool inside_field = 
                _board.selection_inside_the_field(input_coords.first, input_coords.second);
            bool pawn_exists_on_position = 
                _board.check_if_there_is_a_pawn_in_given_position(input_coords.first, input_coords.second);

            if (inside_field && pawn_exists_on_position) {
                break;
            }

            input_coords = _viewer.ask_user_to_select_a_pawn_that_shall_go_one_step_forward();
        }

        // here, the coords must be on the board and a pawns position.
        //move_pawn_one_step_forward();         // board gets updated

        break;
    }

    _viewer.print_pawn_reached_other_side_and_game_over();
}
