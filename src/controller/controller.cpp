#include "controller.h"

#include <iostream>

Controller::Controller() 
    : _viewer(), _board() {}

void Controller::run_game() {

    while (_board.pawn_reached_other_side() == false) {
        _viewer.display_game(_board);

        // add a bit of control flow here:
        // _viewer.ask_user_to_select_a_pawn_that_will_go_one_step_forward(); // shall return x,y coordinate
        // if(check if coordinates valid (on board) == false)
            // cout: enter valid coordinates
            //_viewer.ask_user_to_select_a_pawn_that_will_go_one_step_forwawrd();  // add loop here
        // if(check if there is a pawn on this position == false)
            // cout: no pawn on this position. Enter new coordinates, with pawn. // add loop here
        //move_pawn_one_step_forward();         // board gets updated

        break;
    }

    _viewer.print_pawn_reached_other_side_and_game_over();
}
