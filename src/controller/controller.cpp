#include "controller.h"

#include <iostream>

Controller::Controller() 
    : _viewer(), _board() {}

void Controller::run_game() {

    while (_board.pawn_reached_other_side() == false) {
        _viewer.display_game(_board);
        
        // if (_viewer.ask_user_if_pawn_should_go_one_step_forward()) {
        //     // _board.move_pawn_one_step_forward();
        //     count_steps ++;
        // }

        // add a bit of control flow here:
        // _viewer.ask_user_to_select_a_pawn_that_will_go_one_step_forward(); // shall return x,y coordinate
        // if(check if coordinates valid (on board) == false)
            // cout: enter valid coordinates
            //_viewer.ask_user_to_select_a_pawn_that_will_go_one_step_forwawrd();  // add loop here
        // if(check if there is a pawn on this position == false)
            // cout: no pawn on this position. Enter new coordinates, with pawn. // add loop here
        //move_pawn_one_step_forward();         // board gets updated
        //if(check if pawn reached other side() == true)
            // cout: game over. Pawn reached other side


        break;

    }
    
    _viewer.print_pawn_reached_other_side_and_game_over();
}
